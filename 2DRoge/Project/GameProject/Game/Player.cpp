#include"Player.h"
#include"AnimData.h"
#include"AreaChange.h"
#include"Field.h"
#include"Bullet.h"
#include"Slash.h"
#include"Effect.h"
#include"Enemy.h"
#include"Goal.h"
#include"Map.h"
#include"Door.h"
#include"Guard.h"



Player::Player(const CVector2D& p, bool flip) :Base(eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("Player", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	//���W�ݒ�
	m_pos = p;
	m_img.SetSize(200, 200);
	//���S�ʒu�ݒ�
	m_img.SetCenter(100, 100);
	//�����蔻��
	m_rect = CRect(-30, -40, 30, 100);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = false;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//�q�b�g�|�C���g
	m_hp = 3000;
	m_cnt;
}
void Player::StateAttack() {
	
	 //�U���A�j���[�V�����P�֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//1�Ԗڂ̃p�^�[���Ȃ�
	/*if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack, m_attack_no));
		}
	}*/
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		if (HOLD(CInput::eButton3)) {
			m_state = eState_Attack2;
			if (HOLD(CInput::eButton3)) {
				m_state = eState_Attack3;
			}
		}
		else if(m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
			m_state = eState_Idle;
		}
	}
		

	
}

void Player::StateAttack2() {
	//�U���A�j���[�V����2�֕ύX
	m_img.ChangeAnimation(eAnimAttack02, false);
	//1�Ԗڂ̃p�^�[���Ȃ�
	/*if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack, m_attack_no));
		}
	}*/
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}
void Player::StateAttack3() {
	//�U���A�j���[�V����3�֕ύX
	m_img.ChangeAnimation(eAnimAttack03, false);
	//1�Ԗڂ̃p�^�[���Ȃ�
	/*if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Player_Attack, m_attack_no));
		}
	}*/
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

//�K�[�h
void Player::StateGuard() {
	if (HOLD(CInput::eButton4)) {
		m_img.ChangeAnimation(eAnimGuard, true);
		if (m_img.GetIndex() == 0) {
			if (m_flip) {
				Base::Add(new Guard(m_pos + CVector2D(-80, 30), m_flip, eType_Guard, m_attack_no));
			}
			else {
				Base::Add(new Guard(m_pos + CVector2D(80, 30), m_flip, eType_Guard, m_attack_no));
			}
		}
	}
	else {
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
	m_kill = true;
	
}

void Player::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
		//�U�����2
	case eState_Attack2:
		StateAttack2();
		break;
		//�U�����3
	case eState_Attack3:
		StateAttack3();
		break;

		//�K�[�h���
	case eState_Guard:
		StateGuard();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;
}

void Player::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	DrawRect();
}

void Player::Collision(Base* b) {
	switch (b->m_type) {
		//�h�A
	case eType_Door:
		if (PUSH(CInput::eUp)) {
			if (Door* s = dynamic_cast<Door*>(b)) {
				if (Base::CollisionRect(this, s)) {
					m_pos_old = m_pos = s->GetNextPos();
				}
			}
		}
		break;
		//�G���A�`�F���W
	case eType_AreaChange:
		if (PUSH(CInput::eUp)) {
			if (AreaChange* s = dynamic_cast<AreaChange*>(b)) {
				if (Base::CollisionRect(this, s)) {
					Base::Kill(1 << eType_Field
						| 1 << eType_Enemy
						| 1 << eType_AreaChange
						| 1 << eType_Goal);
					m_pos_old = m_pos = s->GetNextPos();
					Base::Add(new Map(s->GetNextArea()));
				}
			}
		}
		break;

		//�S�[������
	case eType_Goal:
		if (Goal* g = dynamic_cast<Goal*>(b)) {
			if (Base::CollisionRect(this, g)) {
				g->SetGoal();
			}
		}
		break;
		//�U���I�u�W�F�N�g�Ƃ̔���
	case eType_Enemy_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				//Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��o������
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɍs������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍�����߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ݒu�t���OON
				m_is_ground = true;
			}
		}
		//�}�b�v�^�փL���X�g�A�^�ϊ��ł�����
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y),m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y),m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
		break;

		
	}
}
void Player::StateIdle() {
	//�ړ���
	const float move_speed = 8;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 15;
	//���ړ�
	if (HOLD(CInput::eButton12)) {
		//�ړ��ʂ�ݒ�
		m_pos.x -= move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eButton14)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//�U��(J)
	if (PUSH(CInput::eButton3)) {
		//�U����Ԃֈڍs
		m_state = eState_Attack;
		m_attack_no++;
	}
	//�K�[�h(K)
	if (HOLD(CInput::eButton4)) {
		//�K�[�h��Ԃֈڍs
		m_state = eState_Guard;
		
	}
	//�W�����v���Ȃ�
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
				m_img.ChangeAnimation(eAnimJumpDown, true);
	}
	//�n�ʂɂ���Ȃ�
	else {
		//�ړ����Ȃ�
		if (move_flag) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}