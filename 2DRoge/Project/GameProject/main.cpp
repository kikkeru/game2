#include "Base/Base.h"
#include "Game/AnimData.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Field.h"
#include "Game/Effect.h"
#include "Game/Bullet.h"
#include "Game/Goal.h"
#include "Title/Title.h"

//--------------------------------------------
//グローバル変数領域
//--------------------------------------------






void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::CollisionAll();
	Base::DrawAll();

}
void Init(void)
{

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'J');
	CInput::SetButton(0, CInput::eButton4, 'K');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eButton11, 'W');
	CInput::SetButton(0, CInput::eButton12, 'A');
	CInput::SetButton(0, CInput::eButton13, 'S');
	CInput::SetButton(0, CInput::eButton14, 'D');
	CInput::SetButton(0, CInput::eButton15, 'I');
	CInput::SetButton(0, CInput::eButton16, 'E');
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();



	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	//画像の読み込みと登録　”リソース名”　　　　”ファイル名” , アニメーションデータ , 幅 , 高さ
	ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png", player_anim_data, 200,200));
	ADD_RESOURCE("Boss", CImage::CreateImage("Image/Boss.png", boss_anim_data, 200, 200));

	ADD_RESOURCE("Enemy", CImage::CreateImage("Image/Enemy.png", enemy_anim_data, 200, 200));
	ADD_RESOURCE("Dungeon", CImage::CreateImage("Image/Dungeon.png"));
	ADD_RESOURCE("Town", CImage::CreateImage("Image/Town.png"));
	ADD_RESOURCE("ForeGround", CImage::CreateImage("Image/ForeGround.png"));
	ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));
	ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal.png"));
	ADD_RESOURCE("Door", CImage::CreateImage("Image/Door.png"));
	ADD_RESOURCE("Title", CImage::CreateImage("Image/Title.png"));
	ADD_RESOURCE("Effect_Slash", CImage::CreateImage("Image/Effect_Slash.png", effect_slash_anim_data, 128, 128));
	//ADD_RESOURCE("Effect_Slash2", CImage::CreateImage("Image/Effect_Slash.png2", effect_slash2_anim_data, 128, 128));
	//ADD_RESOURCE("Effect_Slash3", CImage::CreateImage("Image/Effect_Slash.png3", effect_slash3_anim_data, 128, 128));
	ADD_RESOURCE("Effect_ESlash1", CImage::CreateImage("Image/Effect_ESlash1.png", effect_eslash1_anim_data, 128, 128));
	ADD_RESOURCE("Effect_ESlash2", CImage::CreateImage("Image/Effect_ESlash2.png", effect_eslash2_anim_data, 128, 128));
	ADD_RESOURCE("Effect_ESlash3", CImage::CreateImage("Image/Effect_ESlash3.png", effect_eslash3_anim_data, 128, 128));
	ADD_RESOURCE("Effect_Rock", CImage::CreateImage("Image/Effect_Rock.png", effect_Rock_anim_data, 128, 128));

	ADD_RESOURCE("Guard", CImage::CreateImage("Image/Guard.png", Guard_anim_data, 50, 50));
	ADD_RESOURCE("Block", CImage::CreateImage("Image/block2.png"));
	ADD_RESOURCE("Block4", CImage::CreateImage("Image/block4.png"));


	Base::Add(new Title());
	








}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "summer");
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}