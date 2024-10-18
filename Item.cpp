#include "include.h"

Item items[D_ITEM_MAX];

DWORD ItemCreatTime = 0;

void ItemInit()
{
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		items[i].x = 0;
		items[i].y = 0;
		items[i].isAlive = false;
		items[i].ItemNumber = 0;
	}


}

void ItemUpdate()
{
	if (ItemCreatTime < GetTickCount())
	{
		ItemCreatTime = GetTickCount() + 1500;
		CreatItem(rand() % 120, rand() % 30);
	}
	ItemPickUp();
	ItemUse();
	ItemClipping();
}

void CreatItem(int x, int y)
{
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		if (items[i].isAlive == false)
		{
			items[i].x = x;
			items[i].y = y;
			items[i].isAlive = true;
		}
	}
}

void ItemDraw()
{
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		if (items[i].isAlive == true)
			DrawChar(items[i].x, items[i].y, ' ', GREEN_BOX);
	}
}

void ItemPickUp()
{
	if (player.isAlive)
	{
		for (int i = 0; i < D_ITEM_MAX; i++)
		{
			if (items[i].isAlive &&
				player.x == items[i].x &&
				(player.y == items[i].y || player.y - 1 == items[i].y) &&
				(player.y == items[i].y || player.y + 1 == items[i].y))
			{
				items[i].isAlive = false;
				items[i].ItemNumber++;

			}
		}
	}
}

void ItemUse()
{
	if (GetAsyncKeyState('C') & 0x8000)
	{

		for (int i = 0; i < D_ITEM_MAX; i++)
		{

			if (items[i].isAlive && items[i].ItemNumber > 0)
			{
				items[i].ItemNumber--;
				enemys[i].isAlive = false;

			}

		}
	}

}

void ItemClipping()
{
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		if (items[i].x < 1)
			items[i].x = 1;
		if (items[i].x > 118)
			items[i].x = 118;
		if (items[i].y > 15)
			items[i].y = 15;
		if (items[i].y < 5)
			items[i].y = 5;
	}

}
