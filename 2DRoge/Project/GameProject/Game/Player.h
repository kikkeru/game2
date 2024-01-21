#pragma once
#pragma once
#include"../Base/Base.h"
class Player :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Attack2,
		eState_Attack3,
		eState_Guard,
		eState_Step,
		eState_Damage,
		eState_Down,
	};
	int m_state;
	CImage m_img;
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�q�b�g�|�C���g
	int m_hp;
	float m_cnt;
	int m_A;
	void StateIdle();
	void StateAttack();
	void StateAttack2();
	void StateAttack3();
	void StateGuard();
	void StateDamage();
	void StateDown();
	void StateStep();
	static Player* ms_instance;

public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
	static Player* Instance();
	const CVector2D& GetPos() const;

};
