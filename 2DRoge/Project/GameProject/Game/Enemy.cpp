#include"Enemy.h"
#include"AnimData.h"
#include"Field.h"
#include"Bullet.h"
#include"Effect.h"
#include"Slash.h"
#include"Map.h"


Enemy::Enemy(const CVector2D& p, bool flip) :Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	m_pos = p;
	m_img.SetSize(150, 150);
	m_img.SetCenter(50,150);
	//当たり判定要矩形設定
	m_rect = CRect(-32, -150, 50, 0);
	//体力の初期化
	m_hp = 50;
	m_flip = flip;
	m_state = eState_Idle;
}
void Enemy::StateAttack() {
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//3番目のパターンなら
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, -80), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, -80), m_flip, eType_Enemy_Attack, m_attack_no));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}
void Enemy::StateDamage() {
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}
void Enemy::StateDown() {
		Base::Add(new Effect("Effect_Bomb", m_pos + CVector2D(0, 0), m_flip));
		m_kill = true;
}

void Enemy::Update() {
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
	}
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
	case eType_Player_Attack:
		//Slash型へキャスト、型変換できたら
		if (Bullet* s = dynamic_cast<Bullet*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
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
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionPoint(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionPoint(CVector2D(m_pos_old.x, m_pos.y));
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
		//左移動
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
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