#pragma once
#include<iostream>
using namespace std;
class Scene
{
	string name, desc;
public:
	Scene(const string& name, string dest) :name(name), desc(desc) {}

	void Print()const;
};