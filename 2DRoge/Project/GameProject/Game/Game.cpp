#include"Game.h"
#include"Field.h"
#include"Player.h"
#include"Enemy.h"
#include"Goal.h"
#include"Map.h"
#include"../Title/Title.h"

Game::Game() :Base(eType_Scene) {
	//Base::Add(new Field());
	Base::Add(new Player(CVector2D(256, 540), false));
	//Base::Add(new Enemy(CVector2D(600 ,540), true));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 3, 540), true));
	Base::Add(new Goal(CVector2D(3000,540)));
	Base::Add(new Map(1));

}
Game::~Game() {
	//���ׂẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}
void Game::Update() {
	if (Base* b = Base::FindObject(eType_Goal)) {
		Goal* g = dynamic_cast<Goal*>(b);
		if (g->GetGoal())
			SetKill();
	}
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}