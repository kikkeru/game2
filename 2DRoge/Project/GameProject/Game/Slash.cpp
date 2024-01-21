#include"Slash.h"

Slash::Slash(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_Slash", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(70, 70);
	m_img.SetCenter(35, 35);
	m_rect = CRect(-35, -35, 35, 35);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}
void Slash::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}
void Slash::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

Slash2::Slash2(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_Slash2", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(70, 70);
	m_img.SetCenter(35, 35);
	m_rect = CRect(-35, -35, 35, 35);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}
void Slash2::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}
void Slash2::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

Slash3::Slash3(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_Slash3", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(70, 70);
	m_img.SetCenter(35, 35);
	m_rect = CRect(-35, -35, 35, 35);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}
void Slash3::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}
void Slash3::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

ESlash1::ESlash1(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_ESlash1", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(70, 70);
	m_img.SetCenter(35, 35);
	m_rect = CRect(-35, -35, 35, 35);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}
void ESlash1::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}
void ESlash1::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

ESlash2::ESlash2(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_ESlash2", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(70, 70);
	m_img.SetCenter(35, 35);
	m_rect = CRect(-20, -20, 35, 20);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}
void ESlash2::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}
void ESlash2::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

ESlash3::ESlash3(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_ESlash3", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(70, 70);
	m_img.SetCenter(35, 35);
	m_rect = CRect(-35, -35, 35, 35);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}
void ESlash3::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}
void ESlash3::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}