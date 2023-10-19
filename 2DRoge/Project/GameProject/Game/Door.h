#pragma once

#include"../Base/Base.h"

class Door :public Base {
private:
	CImage m_img;
	CVector2D m_next_pos;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">位置</param>
	/// <param name="next">移動先</param>
	Door(const CVector2D& pos, const CVector2D& next);
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// 移動先の位置を取得
	/// </summary>
	/// <returns></returns>
	CVector2D GetNextPos() {
		return m_next_pos;
	}
};

