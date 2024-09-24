//#include"Game.h"
#include"SceneManager.h"
int main() {
	/*Game g;
	g.Run();*/

	SceneManager::GetInstance().AddScene("메뉴", "시작, 옵션, 종료");
	SceneManager::GetInstance().AddScene("던전1", "던전 1 시작");

	SceneManager::GetInstance().SetCurrentScene("던전1");
	SceneManager::GetInstance().ShowCurrentScene();
}