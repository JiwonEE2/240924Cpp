#include "SceneManager.h"

SceneManager::SceneManager()
{
	cout << "씬 매니저 인스턴스 생성\n";
}

SceneManager::~SceneManager()
{
	for (auto& pair : scenes) {
		delete pair.second;
	}
}

void SceneManager::AddScene(const string& name, const string& desc)
{
	scenes[name] = new Scene(name, desc);
}

void SceneManager::SetCurrentScene(const string& name)
{
	if (scenes.find(name) != scenes.end()) {
		currentScene = scenes[name];
		cout << "현재 씬이 " << name << "설정 \n";
	}
	else {
		cout << "찾을 수 없다\n";
	}
}

void SceneManager::ShowCurrentScene() const
{
	if (currentScene) {
		currentScene->Print();
	}
	else {
		cout << "설정된 씬이 없음\n";
	}
}