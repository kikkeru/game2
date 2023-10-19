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
	//ó‘Ô•Ï”
	int m_state;
	CImage m_img;
	bool m_flip;
	//UŒ‚”Ô†
	int m_attack_no;
	//ƒ_ƒ[ƒW”Ô†
	int m_damage_no;
	//‘Ì—Í
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
