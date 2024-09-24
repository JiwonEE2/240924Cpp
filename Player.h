#pragma once
#include"Item.h"
#include<vector>
#include<iostream>
using namespace std;
class Player
{
	vector<Item>equippedItems;
	int attack;
	int defense;
public:
	Player();

	// ����
	void equipItem(Item& item);
	// Ż��
	void UnEquipItem(Item& item);
	// ������ ������ �����ֱ�
	void displayEquippedItems()const;
	// ��밡���� ������ �����ֱ�
	void displayAvailableItems(const vector<Item>& availableItems)const;
	// Get(������ ī��Ʈ)
	int getEquippedItemCount()const { return equippedItems.size(); }
	// ������ Get
	Item& getEquippedItem(int index) { return equippedItems[index]; }
	// ������ ������?
	bool isItemEquipped(const Item& item)const;
};