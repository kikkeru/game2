#pragma once

#include"../Base/Base.h"

class Slash :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	Slash(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};

class Slash2 :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	Slash2(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};

class Slash3 :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	Slash3(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};

class ESlash1 :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	ESlash1(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};

class ESlash2 :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	ESlash2(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};

class ESlash3 :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	ESlash3(const CVector2D& pos, bool flip, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};


