#pragma once
#include "../Base/Base.h"

class EnemyManager : public Base {
private:
	int m_cnt;
public:
	EnemyManager();
	void Update();
};