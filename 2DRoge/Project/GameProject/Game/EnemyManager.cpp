#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager() : Base(eType_EnemyManager)
{
	//“GoŒ»‚Ü‚Å‚ÌŠÔ
	m_cnt = 0;
}

void EnemyManager::Update()
{
	m_cnt--;
	//“GoŒ»
	if (m_cnt <= 0) {
		//X²‚Í12`1800‚ÌŠÔ‚Åƒ‰ƒ“ƒ_ƒ€
		Base::Add(new Enemy(CVector2D(3000,Utility::Rand(12.0f, 1800.0f)),true));
		//Ÿ‚ÌoŒ»ŠÔ
		m_cnt = Utility::Rand(120, 360);
	}
}
