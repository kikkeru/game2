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
	//�����蔻��v��`�ݒ�
	m_rect = CRect(-30, -40, 30, 100);
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//�̗͂̏�����
	m_hp = 300;
	m_flip = flip;
	m_state = eState_Idle;
	waitcnt = Utility::Rand(15, 60) ;
	m_cnt=0;
}


void Enemy::StateAttack() {
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//2�Ԗڂ̃p�^�[���Ȃ�
	if (m_img.GetIndex() == 2) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-80, 30), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(80, 30), m_flip, eType_Enemy_Attack, m_attack_no));
		}
	}
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
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
			//�E����
			m_pos.x += 30.0f;
			m_pos.y -= 5.0f;
	}
	else {
			//������
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
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
		//�X�^��
	case eState_Stan:
		StateStan();
		//���
		break;
	case eState_Step:
		StateStep();
		break;
	}
	//���E�ɓ�������s��
	/*if (m_isFoundTarget)
	{
		CVector2D targetPos = Player::Instance()->GetPos();
		CVector2D targetVec = (targetPos - m_pos).GetNormalize();
	}*/

	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
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
		//Block�^�փL���X�g�A�^�ϊ��o������
		if (Block* k = dynamic_cast<Block*>(b)) {
			if (k->CollisionRect(this, k)) {
				//b1�̋�`
				CRect rect1 = CRect(
					m_pos.x + m_rect.m_left,
					m_pos.y + m_rect.m_top,
					m_pos.x + m_rect.m_right,
					m_pos.y + m_rect.m_bottom);
				//b2�̋�`
				CRect rect2 = CRect(
					b->m_pos.x + b->m_rect.m_left,
					b->m_pos.y + b->m_rect.m_top,
					b->m_pos.x + b->m_rect.m_right,
					b->m_pos.y + b->m_rect.m_bottom);

				//���̔���̂�
				if (CCollision::CollisionRect(rect2, CRect(
					m_pos.x + m_rect.m_left,
					m_pos_old.y + m_rect.m_top,
					m_pos.x + m_rect.m_right,
					m_pos_old.y + m_rect.m_bottom))) {
					//�u���b�N�̉��ɓ���������
					//�E�̏ꍇ
					if (m_pos.x > b->m_pos.x) {
						m_pos.x = rect2.m_right - m_rect.m_left + 4;
					}
					//���̏ꍇ
					else {
						m_pos.x = rect2.m_left - m_rect.m_right - 4;
					}
				}
				//�c�̔���̂�
				if (CCollision::CollisionRect(rect2, CRect(
					//�u���b�N���ɓ��������Ƃ���a���Ȃ�������悤�ɏ������l��������
					m_pos_old.x + m_rect.m_left + 8,
					m_pos.y + m_rect.m_top,
					m_pos_old.x + m_rect.m_right - 8,
					m_pos.y + m_rect.m_bottom))) {
					m_pos.y = m_pos_old.y;
					//�v���C���[���u���b�N�̏c�ɂ�����������
					if (m_pos_old.y < b->m_pos.y) {
						//�ڒn�t���OON
						m_is_ground = true;
						m_pos += b->m_vec;
					}
					m_vec.y = 0;

				}
			}
		}
		break;
	case eType_Player_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
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
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
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
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
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

		//�}�b�v�^�փL���X�g�A�^�ϊ��ł�����
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
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
		//Map�^
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
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
void Enemy::StateIdle() {
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��傭
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		if (waitcnt >0) {
			waitcnt--;
		}
		else  {
			
			//���ړ�
			if (player->m_pos.x < m_pos.x - 120) {
				//�ړ��ʂ�ݒ�
				m_pos.x += -move_speed;
				//���]�t���O
				m_flip = true;
				move_flag = true;
			}
			else{
				//�E�ړ�
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