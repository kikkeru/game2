#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager() : Base(eType_EnemyManager)
{
	//�G�o���܂ł̎���
	m_cnt = 0;
}

void EnemyManager::Update()
{
	m_cnt--;
	//�G�o��
	if (m_cnt <= 0) {
		//X����12�`1800�̊ԂŃ����_��
		Base::Add(new Enemy(CVector2D(3000,Utility::Rand(12.0f, 1800.0f)),true));
		//���̏o������
		m_cnt = Utility::Rand(120, 360);
	}
}
