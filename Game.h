#pragma once
#include"Player.h"
#include"Item.h"
#include"Menu.h"
class Game
{
	Player* player;
	vector<Item>availableItems;
public:
	Game() {
		InitItems();
		player = new Player();
	}
	~Game() {
		delete player;
	}
	void InitItems();
	void Run();
	void ShowMenu();
	void EquipItem();
	void UnEquipItem();
};