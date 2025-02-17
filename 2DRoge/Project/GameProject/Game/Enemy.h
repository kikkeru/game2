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
	//状態変数
	int m_state;
	CImage m_img;
	bool m_flip;
	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;
	//体力
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
	//bool m_isFoundTarget;	// 目標物を見つけた状態か
	//float m_searchLength;	// 探索距離
	//float m_searchAngle;	// 探索範囲
	// 目標物が探索範囲内に入っているかどうか
	//bool IsFoundTarget() const;
public:
	Enemy(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
