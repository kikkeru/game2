#pragma once
#include"../Base/Base.h"

class Bullet :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
	int m_cnt;
public:
	Bullet(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};