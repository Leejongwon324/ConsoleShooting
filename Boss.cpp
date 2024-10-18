#include "include.h"

Boss bosses;

DWORD moveBossTime = 0;


char bossshape[3][5] =
{
	{' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' '}



};

void BossInit()
{

	bosses.isAlive = false;
	bosses.x = 0;
	bosses.y = 0;
	bosses.index = 0;
	bosses.hp = 0;


}

void BossUpdate()
{

	if (score >= 20 && score % 20 == 0)
	{


		CreatBoss(60, 7);
		bosses.isAlive = true;


		for (int i = 0; i < D_ENEMY_MAX; i++)
		{
			enemys[i].isAlive = false;
		}
	}

	if (bosses.isAlive == true)
	{
		BulletBossCollision();

		/*BossMove();*/

		BossHp();

		BossClipping();
	}
}

void BossDraw()
{

	if (bosses.isAlive == true)
	{


		DrawChar(bosses.x - 2, bosses.y - 1, bossshape[0][0], WHITE_BOX);
		DrawChar(bosses.x - 1, bosses.y - 1, bossshape[0][0], WHITE_BOX);
		DrawChar(bosses.x, bosses.y - 1, bossshape[0][1], WHITE_BOX);
		DrawChar(bosses.x + 1, bosses.y - 1, bossshape[0][2], WHITE_BOX);
		DrawChar(bosses.x + 2, bosses.y - 1, bossshape[0][2], WHITE_BOX);

		DrawChar(bosses.x - 2, bosses.y, bossshape[0][0], WHITE_BOX);
		DrawChar(bosses.x - 1, bosses.y, bossshape[0][0], WHITE);
		DrawChar(bosses.x, bosses.y, bossshape[0][1], GREEN_BOX);
		DrawChar(bosses.x + 1, bosses.y, bossshape[0][2], WHITE);
		DrawChar(bosses.x + 2, bosses.y, bossshape[0][2], WHITE_BOX);

		DrawChar(bosses.x - 2, bosses.y + 1, bossshape[0][0], WHITE_BOX);
		DrawChar(bosses.x - 1, bosses.y + 1, bossshape[0][0], WHITE);
		DrawChar(bosses.x, bosses.y + 1, bossshape[0][1], BLUE_BOX);
		DrawChar(bosses.x + 1, bosses.y + 1, bossshape[0][2], WHITE);
		DrawChar(bosses.x + 2, bosses.y + 1, bossshape[0][2], WHITE_BOX);






	}
}



void BossMove()
{

	if (bosses.isAlive == true)
	{
		bosses.x = rand() % 120;

	}
}

void BossHp()
{

	if (bosses.isAlive && bosses.hp <= 0)
	{
		bosses.isAlive = false;

		score++;
	}

}

void CreatBoss(int x, int y)
{


	if (bosses.isAlive == false)
	{
		bosses.x = x;
		bosses.y = y;
		bosses.isAlive = true;
		bosses.hp = 10;
	}

}

void BossClipping()
{
	if (bosses.x < 1)
		bosses.x = 1;
	if (bosses.x > 118)
		bosses.x = 118;
	if (bosses.y > 15)
		bosses.y = 15;
	if (bosses.y < 5)
		bosses.y = 5;
}



void BulletBossCollision()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{

		if (bullets[i].isAlive)
		{

			if (bosses.isAlive &&
				bullets[i].x == bosses.x &&
				bullets[i].y == bosses.y)
			{
				bullets[i].isAlive = false;
				bosses.hp--;
				break;
			}

		}
	}
}
