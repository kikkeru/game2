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
	//bool m_isFoundTarget;	// –Ú•W•¨‚ğŒ©‚Â‚¯‚½ó‘Ô‚©
	//float m_searchLength;	// ’Tõ‹——£
	//float m_searchAngle;	// ’Tõ”ÍˆÍ
	// –Ú•W•¨‚ª’Tõ”ÍˆÍ“à‚É“ü‚Á‚Ä‚¢‚é‚©‚Ç‚¤‚©
	//bool IsFoundTarget() const;
public:
	Enemy(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
