#include"Enemy.h"
#include"Player.h"
#include"AnimData.h"
#include"Field.h"
#include"Bullet.h"
#include"Block.h"
#include"Effect.h"
#include"Slash.h"
#include"Map.h"


Enemy::Enemy(const CVector2D& p, bool flip) :Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	m_pos = p;
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	//当たり判定要矩形設定
	m_rect = CRect(-30, -40, 30, 100);
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//体力の初期化
	m_hp = 300;
	m_flip = flip;
	m_state = eState_Idle;
	waitcnt = Utility::Rand(15, 60) ;
	m_cnt=0;
}


void Enemy::StateAttack() {
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//2番目のパターンなら
	if (m_img.GetIndex() == 2) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Enemy_Attack, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
		waitcnt = Utility::Rand(15, 120);
	}
}
void Enemy::StateDamage() {
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Enemy::StateDown() {
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}		
}

void Enemy::StateStan() {
	m_cnt = 0;
	m_pos.x += 100;
	m_img.ChangeAnimation(eAnimStan, true);
	while (m_cnt > 300 ) {
		m_cnt++;
	}
	m_state = eState_Idle;
	m_cnt = 0;
}

void Enemy::StateStep() {
	Base* player = Base::FindObject(eType_Player);
	m_img.ChangeAnimation(eAnimStep, false);
	if (m_flip) {
			//右向き
			m_pos.x += 30.0f;
			m_pos.y -= 5.0f;
	}
	else {
			//左向き
			m_pos.x -= 30.0f;
			m_pos.y -= 5.0f;
	}
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
		waitcnt = Utility::Rand(15, 120);
	}
}

void Enemy::Update() {
	//m_isFoundTarget = IsFoundTarget();
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
		//スタン
	case eState_Stan:
		StateStan();
		//回避
		break;
	case eState_Step:
		StateStep();
		break;
	}
	//視界に入ったら行動
	/*if (m_isFoundTarget)
	{
		CVector2D targetPos = Player::Instance()->GetPos();
		CVector2D targetVec = (targetPos - m_pos).GetNormalize();
	}*/

	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_img.UpdateAnimation();
}

void Enemy::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

void Enemy::Collision(Base* b) {
	switch (b->m_type) {
		//Block型へキャスト、型変換出来たら
		if (Block* k = dynamic_cast<Block*>(b)) {
			if (k->CollisionRect(this, k)) {
				//b1の矩形
				CRect rect1 = CRect(
					m_pos.x + m_rect.m_left,
					m_pos.y + m_rect.m_top,
					m_pos.x + m_rect.m_right,
					m_pos.y + m_rect.m_bottom);
				//b2の矩形
				CRect rect2 = CRect(
					b->m_pos.x + b->m_rect.m_left,
					b->m_pos.y + b->m_rect.m_top,
					b->m_pos.x + b->m_rect.m_right,
					b->m_pos.y + b->m_rect.m_bottom);

				//横の判定のみ
				if (CCollision::CollisionRect(rect2, CRect(
					m_pos.x + m_rect.m_left,
					m_pos_old.y + m_rect.m_top,
					m_pos.x + m_rect.m_right,
					m_pos_old.y + m_rect.m_bottom))) {
					//ブロックの横に当たったら
					//右の場合
					if (m_pos.x > b->m_pos.x) {
						m_pos.x = rect2.m_right - m_rect.m_left + 4;
					}
					//左の場合
					else {
						m_pos.x = rect2.m_left - m_rect.m_right - 4;
					}
				}
				//縦の判定のみ
				if (CCollision::CollisionRect(rect2, CRect(
					//ブロック横に当たったとき違和感なく落ちるように少し数値を加える
					m_pos_old.x + m_rect.m_left + 8,
					m_pos.y + m_rect.m_top,
					m_pos_old.x + m_rect.m_right - 8,
					m_pos.y + m_rect.m_bottom))) {
					m_pos.y = m_pos_old.y;
					//プレイヤーがブロックの縦にあったったら
					if (m_pos_old.y < b->m_pos.y) {
						//接地フラグON
						m_is_ground = true;
						m_pos += b->m_vec;
					}
					m_vec.y = 0;

				}
			}
		}
		break;
	case eType_Player_Attack:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state == eState_Step) {
					m_hp -= 0;
					break;
				}
				if(m_hp>=1) {
					if (rand() % 1000 < 350) {
						m_state = eState_Step;
					}else{
						m_damage_no = s->GetAttackNo();
						m_hp -= 50;
						m_state = eState_Damage;
					}
				}
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
			}
		}
		break;
	case eType_Player_Attack2:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state == eState_Step) {
					m_hp -= 0;
					break;
				}
				if (m_hp >= 1) {
					if (rand() % 1000 < 450) {
						m_state = eState_Step;
					}
					else {
						m_damage_no = s->GetAttackNo();
						m_hp -= 50;
						m_state = eState_Damage;
					}
				}
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
			}
		}
		break;

	case eType_Player_Attack3:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state == eState_Step) {
					m_hp -= 0;
					break;
				}
				if (m_hp >= 1) {
					if (rand() % 1000 < 250) {
						m_state = eState_Step;
					}
					else {
						m_damage_no = s->GetAttackNo();
						m_hp -= 100;
						m_state = eState_Damage;
						if (m_img.CheckAnimationEnd()) {
							m_state = eState_Stan;
						}
					}
				}
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
			}
		}
		break;

		//マップ型へキャスト、型変換できたら
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
	case eType_Field:
		//Field型へキャスト、型変換出来たら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下に行ったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さを戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//設置フラグON
				m_is_ground = true;
			}
		}
		//Map型
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
	
		
	}
}
void Enemy::StateIdle() {
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;
	//ジャンプりょく
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		if (waitcnt >0) {
			waitcnt--;
		}
		else  {
			
			//左移動
			if (player->m_pos.x < m_pos.x - 120) {
				//移動量を設定
				m_pos.x += -move_speed;
				//反転フラグ
				m_flip = true;
				move_flag = true;
			}
			else{
				//右移動
				if (player->m_pos.x > m_pos.x + 120) {
					m_pos.x += move_speed;
					m_flip = false;
					move_flag = true;
				}
				else {
					m_state = eState_Attack;
					m_attack_no++;
					
				}
			}
		}
	}
	//移動中なら
	if (move_flag) {
		//走るアニメーション
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	}
}