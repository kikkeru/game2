#include"Door.h"


Door::Door(const CVector2D& pos, const CVector2D& next) :Base(eType_Door) {
	m_img = COPY_RESOURCE("Door", CImage);
	m_img.SetCenter(64, 128);
	m_img.SetSize(128, 128);
	m_pos = pos;
	m_next_pos = next;
	m_rect = CRect(-64, -128, 64, 0);
}

void Door::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}