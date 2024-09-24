#pragma once
#include<string>
using namespace std;
class Item
{
	string name;
	string type;
	int attack, defense;
	bool equipped;
public:
	Item(const string& name, const string& type, int attack, int defense);

	string getName()const { return name; }
	string getType()const { return type; }
	int getAttack()const { return attack; }
	int getDefense()const { return defense; }
	int isEquipped()const { return equipped; }
	void setEquipped(bool value) { equipped = value; }
};