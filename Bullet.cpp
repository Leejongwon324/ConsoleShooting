#include "include.h"

Bullet bullets[D_BULLET_MAX];


void BulletInit()
{

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		bullets[i].x = 0;
		bullets[i].y = 0;
		bullets[i].isAlive = false;

	}


}

void BulletUpdate()
{
	BulletMove();
	BulletClipping();

}

void BulletDraw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive == true)
			DrawChar(bullets[i].x, bullets[i].y, '|', BLUE);
	}
}

void BulletMove()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive == true)
			bullets[i].y--;
		if (bullets[i].y < 5)
			bullets[i].isAlive = false;
	}


}

void BulletClipping()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive && bullets[i].y < 0)
		{
			bullets[i].isAlive = false;
		}
	}


}

void CreatBullets(int x, int y)
{
	if (bulletscount > 0)
	{
		for (int i = 0; i < D_BULLET_MAX; i++)
		{
			if (bullets[i].isAlive == false)
			{
				bullets[i].x = x;
				bullets[i].y = y;
				bullets[i].isAlive = true;
				bulletscount--;
				break;
			}
		}
	}


}

void BulletReload()
{

	if (bulletscount == 0)
	{
		bulletscount = 0;
	}
	if (GetAsyncKeyState('R') & 0x8000)
	{
		BulletInit();
		bulletscount = D_BULLET_MAX;
	}


}
