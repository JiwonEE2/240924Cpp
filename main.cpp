//#include"Game.h"
#include"SceneManager.h"
int main() {
	/*Game g;
	g.Run();*/

	SceneManager::GetInstance().AddScene("�޴�", "����, �ɼ�, ����");
	SceneManager::GetInstance().AddScene("����1", "���� 1 ����");

	SceneManager::GetInstance().SetCurrentScene("����1");
	SceneManager::GetInstance().ShowCurrentScene();
}