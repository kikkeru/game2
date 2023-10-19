#include"Bullet.h"

Bullet::Bullet(const CVector2D& pos, bool flip, int type, int attack_no) :Base(type) {
	m_img = COPY_RESOURCE("Effect_Bullet", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(50, 50);
	m_img.SetCenter(25, 25);
	m_rect = CRect(-25, -25, 25, 25);
	m_img.ChangeAnimation(0, true);
	m_attack_no = attack_no;
	m_cnt = 0;
}
void Bullet::Update() {
	m_img.UpdateAnimation();
	if (m_flip) {
		const int move_speed = 10;
		m_pos.x -= move_speed;
	}
	else {
		const int move_speed = 10;
		m_pos.x += move_speed;

	}
	m_cnt++;
	if (m_cnt >= 30) {
		SetKill();
	}
	
}
void Bullet::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}