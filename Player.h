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

	// 장착
	void equipItem(Item& item);
	// 탈착
	void UnEquipItem(Item& item);
	// 장착된 아이템 보여주기
	void displayEquippedItems()const;
	// 사용가능한 아이템 보여주기
	void displayAvailableItems(const vector<Item>& availableItems)const;
	// Get(아이템 카운트)
	int getEquippedItemCount()const { return equippedItems.size(); }
	// 아이템 Get
	Item& getEquippedItem(int index) { return equippedItems[index]; }
	// 아이템 장착함?
	bool isItemEquipped(const Item& item)const;
};