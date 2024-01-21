#pragma once
#include"../Base/Base.h"
class Enemy :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Stan,
		eState_Step,
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
	int m_cnt;
	int waitcnt;
	bool m_is_ground;
	void StateIdle();
	void StateAttack();
	void StateAttack2();
	void StateAttack3();
	void StateDamage();
	void StateDown();
	void StateStan();
	void StateStep();
	void GetRandom();
	//bool m_isFoundTarget;	// �ڕW������������Ԃ�
	//float m_searchLength;	// �T������
	//float m_searchAngle;	// �T���͈�
	// �ڕW�����T���͈͓��ɓ����Ă��邩�ǂ���
	//bool IsFoundTarget() const;
public:
	Enemy(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
