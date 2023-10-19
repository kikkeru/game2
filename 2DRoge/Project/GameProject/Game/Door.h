#pragma once

#include"../Base/Base.h"

class Door :public Base {
private:
	CImage m_img;
	CVector2D m_next_pos;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos">�ʒu</param>
	/// <param name="next">�ړ���</param>
	Door(const CVector2D& pos, const CVector2D& next);
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	/// <summary>
	/// �ړ���̈ʒu���擾
	/// </summary>
	/// <returns></returns>
	CVector2D GetNextPos() {
		return m_next_pos;
	}
};

