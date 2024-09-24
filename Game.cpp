#include "Game.h"

void Game::InitItems()
{
	availableItems.push_back(Item("��", "����", 10, 0));
	availableItems.push_back(Item("����", "��", 0, 20));
	availableItems.push_back(Item("����", "��", 0, 30));
	availableItems.push_back(Item("�����", "�Ǽ��縮", 0, 5));
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
			cout << "����\n";
			return;
			break;
		default:
			cout << "�ٽ� �õ�\n";
			break;
		}
		cout << "\n";
	}
	
}

void Game::ShowMenu()
{
	cout << "1. ������ �����ϱ�\n";
	cout << "2. ������ Ż���ϱ�\n";
	cout << "3. ������ ������ ���\n";
	cout << "4. ��� ������ ������ ���\n";
	cout << "5. ����\n";
	cout << "�޴��� �����ϼ��� : ";
}

void Game::EquipItem()
{
	cout << "������ �������� �����ϼ��� (1-" << availableItems.size() << ") : \n";

	player->displayAvailableItems(availableItems);

	int itemIdx;
	cin >> itemIdx;

	// ������ ������ �ε����� ��ȿ����
	if (itemIdx >= 1 && itemIdx <= availableItems.size()) {
		Item& selectItem = availableItems[itemIdx - 1];
		player->equipItem(selectItem);
	}
	else {
		cout << "�ٽ� �õ�\n";
	}
}

void Game::UnEquipItem()
{
	player->displayEquippedItems();

	cout << "Ż���� �������� �����ϼ��� (1-" << player->getEquippedItemCount() << ")";

	int itemIdx;
	cin >> itemIdx;

	if (itemIdx >= 1 && itemIdx <= player->getEquippedItemCount()) {
		Item& selectItem = player->getEquippedItem(itemIdx - 1);
		player->UnEquipItem(selectItem);
	}
	else {
		cout << "�ٽ� �õ�\n";
	}
}