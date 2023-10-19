#pragma once
#include"../Base/Base.h"
class Enemy :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	//��ԕϐ�
	int m_state;
	CImage m_img;
	bool m_flip;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�̗�
	int m_hp;
	bool m_is_ground;
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
public:
	Enemy(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
