#pragma once
struct Item
{
	int x;

	int y;

	int ItemNumber;

	bool isAlive;
};

void ItemInit();

void ItemUpdate();

void CreatItem(int x, int y);

void ItemDraw();

void ItemPickUp();

void ItemUse();

void ItemClipping();
