#include "SceneManager.h"

SceneManager::SceneManager()
{
	cout << "�� �Ŵ��� �ν��Ͻ� ����\n";
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
		cout << "���� ���� " << name << "���� \n";
	}
	else {
		cout << "ã�� �� ����\n";
	}
}

void SceneManager::ShowCurrentScene() const
{
	if (currentScene) {
		currentScene->Print();
	}
	else {
		cout << "������ ���� ����\n";
	}
}