#include "include.h"

Boss bosses;

DWORD moveBossTime = 0;

char bossshape[3][3] =
{
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	
	
};

void BossInit()
{
	
		bosses.isAlive = false;
		bosses.x = 0;
		bosses.y = 0;
		bosses.index = 0;
		bosses.hp = 0;
		bosses.indexupdatetime = 0;
	
}

void BossUpdate()
{
	
		if (score >= 5)
		{
			score = 0;
			CreatBoss(60, 15);
			
		}

		

	BulletBossCollision();

	BossMove();

	BossClipping();

	BossHp();
}

void BossDraw()
{

	if (bosses.isAlive == true)
	{
		
		DrawChar(bosses.x - 1, bosses.y - 1, bossshape[0][0], WHITE_BOX);
		DrawChar(bosses.x, bosses.y - 1, bossshape[0][1], WHITE_BOX);
		DrawChar(bosses.x + 1, bosses.y - 1, bossshape[0][2], WHITE_BOX);

		DrawChar(bosses.x - 1, bosses.y, bossshape[1][0], WHITE_BOX);
		DrawChar(bosses.x, bosses.y, bossshape[1][1], GREEN_BOX);
		DrawChar(bosses.x + 1, bosses.y, bossshape[1][2], WHITE_BOX);

		DrawChar(bosses.x - 1, bosses.y + 1, bossshape[2][0], WHITE_BOX);
		DrawChar(bosses.x, bosses.y + 1, bossshape[2][1], WHITE_BOX);
		DrawChar(bosses.x + 1, bosses.y + 1, bossshape[2][2], WHITE_BOX);

		
	}
}

void BossHp()
{

	if (BulletBossCollision)
		bosses.hp--;

	

	
}

void BossMove()
{
	/*for (int i = 0; i < D_BOSS_MAX; i++)
	{
		if (bosses.isAlive == true)
			bosses.x = rand() % 120;
	}*/
}

void BossClipping()
{
	
		if (bosses.isAlive && bosses.hp <= 0)
		{
			bosses.isAlive = false;
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
