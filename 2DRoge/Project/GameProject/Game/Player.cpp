#include"Player.h"
#include"AnimData.h"
#include"AreaChange.h"
#include"Field.h"
#include"Block.h"
#include"MoveBlock.h"
#include"Slash.h"
#include"Effect.h"
#include"Enemy.h"
#include"Goal.h"
#include"Map.h"
#include"Door.h"
#include"Guard.h"


Player::Player(const CVector2D& p, bool flip) :Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	//座標設定
	m_pos = p;
	m_img.SetSize(200, 200);
	//中心位置設定
	m_img.SetCenter(100, 100);
	//当たり判定
	m_rect = CRect(-30, -40, 30, 100);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = false;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//ヒットポイント
	m_hp = 3000;
	m_cnt;
	m_A = 1;
}

void Player::StateAttack() {
	m_cnt = 0;
	switch (m_A) {
	case 1:
		//攻撃アニメーション１へ変更
		m_img.ChangeAnimation(eAnimAttack01, false);
		//1番目のパターンなら
		if (m_img.GetIndex() == 1) {
			if (m_flip) {
				Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack, m_attack_no));
			}
			else {
				Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack, m_attack_no));
			}
		}
		//アニメーションが終了したら
		if (m_img.CheckAnimationEnd()) {
			//通常状態へ移行
			m_state = eState_Idle;
			m_A ++;
		}
		break;
	case 2:
		//攻撃アニメーション2へ変更
		m_img.ChangeAnimation(eAnimAttack02, false);
		//1番目のパターンなら
		if (m_img.GetIndex() == 1) {
			if (m_flip) {
				Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack2, m_attack_no));
			}
			else {
				Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack2, m_attack_no));
			}
		}
		//アニメーションが終了したら
		if (m_img.CheckAnimationEnd()) {
			//通常状態へ移行
			m_state = eState_Idle;
			m_A ++;
		}
		break;
	case 3:
		//攻撃アニメーション3へ変更
		m_img.ChangeAnimation(eAnimAttack03, false);
		//1番目のパターンなら
		if (m_img.GetIndex() == 1) {
			if (m_flip) {
				Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack3, m_attack_no));
			}
			else {
				Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack3, m_attack_no));
			}
		}
		//アニメーションが終了したら
		if (m_img.CheckAnimationEnd()) {
			//通常状態へ移行
			m_state = eState_Idle;
			m_A = 1;
		}
		break;
	}
	
}

void Player::StateAttack2() {
	//攻撃アニメーション2へ変更
	m_img.ChangeAnimation(eAnimAttack02, false);
	//1番目のパターンなら
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack2, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack2, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}
void Player::StateAttack3() {
	//攻撃アニメーション3へ変更
	m_img.ChangeAnimation(eAnimAttack03, false);
	//1番目のパターンなら
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack3, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack3, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		
		//通常状態へ移行
		m_state = eState_Idle;
	}
}

//ガード
void Player::StateGuard() {
	if (HOLD(CInput::eButton4)) {
		m_img.ChangeAnimation(eAnimGuard, true);
		if (m_img.GetIndex() == 0) {
			if (m_flip) {
				Base::Add(new Guard(m_pos + CVector2D(-50, 30), m_flip, eType_Guard, m_attack_no));
			}
			else {
				Base::Add(new Guard(m_pos + CVector2D(50, 30), m_flip, eType_Guard, m_attack_no));
			}
		}
	}
	else {
		m_state = eState_Idle;
	}
}

//ステップ
void Player::StateStep() {
	m_img.ChangeAnimation(eAnimStep, false);
	if (m_flip) {
		//右向き
		m_pos.x += 25.0f;
		m_pos.y -= 4.0f;
	}else {
		//左向き
		m_pos.x -= 25.0f;
		m_pos.y -= 4.0f;
	
	}
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player::StateDamage() {
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}
void Player::StateDown() {
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
			m_kill = true;
	}	
}

void Player::Update() {
	m_pos_old = m_pos;
	m_vec.x = m_vec.x * 0.9;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//攻撃状態2
	case eState_Attack2:
		StateAttack2();
		break;
		//攻撃状態3
	case eState_Attack3:
		StateAttack3();
		break;

		//ガード状態
	case eState_Guard:
		StateGuard();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
		//ステップ（回避）状態
	case eState_Step:
		StateStep();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//アニメーション更新
	m_img.UpdateAnimation();
	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 650;
}

/*Player* Player::Instance()
{
	return ms_instance;
}*/

const CVector2D& Player::GetPos() const
{
	return m_pos;
}

void Player::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

void Player::Collision(Base* b) {
	const float move_speed = 3;
	switch (b->m_type) {
	case eType_MoveBlock:

		//MoveBlock型へキャスト、型変換出来たら
		if (MoveBlock* MB = dynamic_cast<MoveBlock*>(b)) {
			if (MB->CollisionRect(this, MB)) {
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
	case eType_Block:

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
		//ドア
	case eType_Door:
		if (PUSH(CInput::eUp)) {
			if (Door* s = dynamic_cast<Door*>(b)) {
				if (Base::CollisionRect(this, s)) {
					m_pos_old = m_pos = s->GetNextPos();
				}
			}
		}
		break;
		//エリアチェンジ
	case eType_AreaChange:
		//Eキーを押したら
		if (PUSH(CInput::eButton16)) {
			if (AreaChange* s = dynamic_cast<AreaChange*>(b)) {
				if (Base::CollisionRect(this, s)) {
					//int n = 0;
					//n += 1;
					Base::Kill(1 << eType_Field
						| 1 << eType_Enemy
						| 1 << eType_AreaChange
						| 1 << eType_Block
						| 1 << eType_MoveBlock
						| 1 << eType_Goal
						| 1 << eType_Boss);
					m_pos_old = m_pos = s->GetNextPos();
					Base::Add(new Map(s->GetNextArea()));
				}
			}
		}
		break;

		//ゴール判定
	case eType_Goal:
		if (Goal* g = dynamic_cast<Goal*>(b)) {
			if (Base::CollisionRect(this, g)) {
				g->SetGoal();
			}
		}
		break;
		//攻撃オブジェクトとの判定
		//ガード判定
	case eType_Enemy_Attack:
		if (Base* GB = Base::FindObject(eType_Guard)) {
			if (Guard* G = dynamic_cast<Guard*>(GB)) {
				if ( Base::CollisionRect(b, G)) {
					m_damage_no = G->GetAttackNo();
					m_hp -= 0;
					if (m_flip) {
						//右向きなら

						m_vec.x = move_speed;
						
					}
					else {
						//左向きなら
						m_vec.x = -move_speed;
					}
					break;
				}
			}
		}
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state==eState_Step) {
					m_hp -= 0;
					break;
				}
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
		break;

		//攻撃オブジェクトとの判定
		//ガード判定
	case eType_Boss_Attack:
		if (Base* GB = Base::FindObject(eType_Guard)) {
			if (Guard* G = dynamic_cast<Guard*>(GB)) {
				if (Base::CollisionRect(b, G)) {
					m_damage_no = G->GetAttackNo();
					m_hp -= 0;
					if (m_flip) {
						//右向きなら

						m_vec.x = move_speed;

					}
					else {
						//左向きなら
						m_vec.x = -move_speed;
					}
					break;
				}
			}
		}
		//Slash型へキャスト、型変換できたら
		if (ESlash1* s = dynamic_cast<ESlash1*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state == eState_Step) {
					m_hp -= 0;
					break;
				}
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
		break;

		//攻撃オブジェクトとの判定
	case eType_Boss_Attack2:
		
		//Slash型へキャスト、型変換できたら
		if (ESlash2* s = dynamic_cast<ESlash2*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state == eState_Step) {
					m_hp -= 0;
					break;
				}
				m_damage_no = s->GetAttackNo();
				m_hp -= 30;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
		break;
		//攻撃オブジェクトとの判定
//ガード判定
	case eType_Boss_Attack3:
		if (Base* GB = Base::FindObject(eType_Guard)) {
			if (Guard* G = dynamic_cast<Guard*>(GB)) {
				if (Base::CollisionRect(b, G)) {
					m_damage_no = G->GetAttackNo();
					m_hp -= 0;
					if (m_flip) {
						//右向きなら

						m_vec.x = move_speed+13;

					}
					else {
						//左向きなら
						m_vec.x = -move_speed+13;
					}
					break;
				}
			}
		}
		//Slash型へキャスト、型変換できたら
		if (ESlash3* s = dynamic_cast<ESlash3*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				if (m_state == eState_Step) {
					m_hp -= 0;
					break;
				}
				m_damage_no = s->GetAttackNo();
				m_hp -= 500;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
					
				}
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
		//マップ型へキャスト、型変換できたら
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y),m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y),m_rect);
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
void Player::StateIdle() {
	//移動量
	const float move_speed = 10;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 15;
	//左移動
	if (HOLD(CInput::eButton12)) {
		//移動量を設定
		m_pos.x -= move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eButton14)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton11)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//攻撃(J)
	if (PUSH(CInput::eButton3)) {
		//攻撃状態へ移行
		m_state = eState_Attack;
		m_attack_no++;
	}

	//ガード(K)
	if (HOLD(CInput::eButton4)) {
		//ガード状態へ移行
		m_state = eState_Guard;
		
	}

	//ステップ(I)
	if (PUSH(CInput::eButton15)) {
		m_state = eState_Step;
	}

	

	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
				m_img.ChangeAnimation(eAnimJumpDown, true);
	}
	//地面にいるなら
	else {
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
}