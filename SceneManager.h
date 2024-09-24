#pragma once
#include"singleton.h"
#include"Scene.h"
#include<iostream>
#include<map>

class SceneManager :public CSingleton<SceneManager>
{
	map<string, Scene*>scenes;
	Scene* currentScene = nullptr;
public:
	SceneManager();
	~SceneManager();

	void AddScene(const string& name, const string& desc);
	void SetCurrentScene(const string& name);
	void ShowCurrentScene()const;
};