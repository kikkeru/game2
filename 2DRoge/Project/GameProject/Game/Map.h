#pragma once
#include"../Base/Base.h"
//�}�b�v�̉�
#define MAP_WIDTH 40
//�}�b�v�̏c
#define MAP_HEIGHT 22
//�}�b�v�`�b�v�̑傫��
#define MAP_TIP_SIZE 128

class Map :public Base {
private:
	CImage m_img;
	CImage m_Dungeon;

	int m_stage_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Map(int area);
	void Draw();
	//�w����W�̃`�b�v�ԍ����擾
	int GetTip(const CVector2D& pos);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int row);
	//�}�b�v�Ƃ̓����蔻��
	int CollisionPoint(const CVector2D& pos);
	int CollisionRect(const CVector2D& pos, const CRect& rect);
};

