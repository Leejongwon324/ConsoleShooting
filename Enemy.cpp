#include "include.h"
Enemy enemys[D_ENEMY_MAX];

DWORD creatEnemyTime = 0;

void EnemyInit()
{

	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		enemys[i].x = 0;
		enemys[i].y = 0;
		enemys[i].isAlive = false;
	}

}

void EnemyUpdate()
{

	if (creatEnemyTime < GetTickCount())
	{
		creatEnemyTime = GetTickCount() + 200;
		CreatEnemy(rand() % 120, 3);
	}
	/*CreatEnemy(rand() % 120, -1);*/

	EnemyMove();

	EnemyClipping();

	BulletEnemyCollision();

	EnemyPlayerCollision();

}

void EnemyDraw()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive == true)
			DrawChar(enemys[i].x, enemys[i].y, ' ', RED_BOX);
	}
}

void EnemyMove()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive == true)
			enemys[i].y++;
	}


}

void EnemyClipping()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive && enemys[i].y > 29)
		{
			enemys[i].isAlive = false;
		}
	}
}

void CreatEnemy(int x, int y)
{

	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive == false)
		{
			enemys[i].x = x;
			enemys[i].y = y;
			enemys[i].isAlive = true;
			break;
		}
	}

}

void BulletEnemyCollision()
{

	/*for (int i = 0; i < D_BULLET_MAX; i++)
	{
		for (int j = 0; j < D_ENEMY_MAX; j++)
		{
			if (bullets[i].x == enemys[j].x && bullets[i].y == enemys[j].y)
			{
				bullets[i].isAlive = false;
				enemys[j].isAlive = false;


			}
		}
	}*/

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive)
		{
			for (int j = 0; j < D_ENEMY_MAX; j++)
			{
				if (enemys[j].isAlive &&
					bullets[i].x == enemys[j].x &&
					(bullets[i].y == enemys[j].y || bullets[i].y + 1 == enemys[j].y))
				{
					CreateEffect(enemys[j].x, enemys[j].y);
					bullets[i].isAlive = false;
					enemys[j].isAlive = false;
					score++;
					break;
				}
			}
		}
	}
}

void EnemyPlayerCollision()
{

	if (player.isAlive)
	{
		for (int j = 0; j < D_ENEMY_MAX; j++)
		{
			if (enemys[j].isAlive &&
				player.x == enemys[j].x &&
				player.y == enemys[j].y)
			{

				enemys[j].isAlive = false;
				player.hp--;
				break;
			}
		}
	}

}
