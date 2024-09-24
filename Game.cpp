#include "Game.h"

void Game::InitItems()
{
	availableItems.push_back(Item("검", "무기", 10, 0));
	availableItems.push_back(Item("방패", "방어구", 0, 20));
	availableItems.push_back(Item("갑옷", "방어구", 0, 30));
	availableItems.push_back(Item("목걸이", "악세사리", 0, 5));
}

void Game::Run()
{
	while (true) {
		ShowMenu();

		int choice;
		cin >> choice;

		Menu::Option op = static_cast<Menu::Option>(choice);

		switch (op)
		{
		case Menu::Option::EQUIP_ITEM:
			EquipItem();
			break;
		case Menu::Option::UNEQUIP_ITEM:
			UnEquipItem();
			break;
		case Menu::Option::DISPLAY_EQUIPPED:
			player->displayEquippedItems();
			break;
		case Menu::Option::DISPLAY_AVAILABLE:
			player->displayAvailableItems(availableItems);
			break;
		case Menu::Option::EXIT:
			cout << "종료\n";
			return;
			break;
		default:
			cout << "다시 시도\n";
			break;
		}
		cout << "\n";
	}
	
}

void Game::ShowMenu()
{
	cout << "1. 아이템 장착하기\n";
	cout << "2. 아이템 탈착하기\n";
	cout << "3. 장착된 아이템 목록\n";
	cout << "4. 사용 가능한 아이템 목록\n";
	cout << "5. 종료\n";
	cout << "메뉴를 선택하세요 : ";
}

void Game::EquipItem()
{
	cout << "장착할 아이템을 선택하세요 (1-" << availableItems.size() << ") : \n";

	player->displayAvailableItems(availableItems);

	int itemIdx;
	cin >> itemIdx;

	// 선택한 아이템 인덱스가 유효한지
	if (itemIdx >= 1 && itemIdx <= availableItems.size()) {
		Item& selectItem = availableItems[itemIdx - 1];
		player->equipItem(selectItem);
	}
	else {
		cout << "다시 시도\n";
	}
}

void Game::UnEquipItem()
{
	player->displayEquippedItems();

	cout << "탈착할 아이템을 선택하세요 (1-" << player->getEquippedItemCount() << ")";

	int itemIdx;
	cin >> itemIdx;

	if (itemIdx >= 1 && itemIdx <= player->getEquippedItemCount()) {
		Item& selectItem = player->getEquippedItem(itemIdx - 1);
		player->UnEquipItem(selectItem);
	}
	else {
		cout << "다시 시도\n";
	}
}