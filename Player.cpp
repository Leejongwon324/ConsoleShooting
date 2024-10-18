#include "include.h"

Player player;

void PlayerInit()
{
	player.x = 60;
	player.y = 28;
	player.hp = 10;
	player.isAlive = true;

}

void PlayerUpdate()
{

	PlayerMove();
	PlayerClipping();

	/*while(true)
	{
		int random = rand();

		int interval = 128;

		random = random % (interval + 1) + 1;
		CreatEnemy(random, -1);
		break;
	}*/

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		CreatBullets(player.x, player.y);
	}

	BulletReload();

	PlayerHp();

	if (player.isAlive == false)
	{

		for (int i = 0; i < D_ENEMY_MAX; i++)
			enemys[i].isAlive = false;

		for (int i = 0; i < D_BULLET_MAX; i++)
			bullets[i].isAlive = false;
		if (GetAsyncKeyState('G') & 0x8000)
			PlayerInit();
	}

}

void PlayerDraw()
{
	DrawChar(player.x, player.y, 'b', WHITE);
}

void PlayerMove()
{
	if (GetAsyncKeyState('W') & 0x8000)
		player.y--;

	if (GetAsyncKeyState('A') & 0x8000)
		player.x--;

	if (GetAsyncKeyState('S') & 0x8000)
		player.y++;

	if (GetAsyncKeyState('D') & 0x8000)
		player.x++;
}

void PlayerClipping()
{
	if (player.x > 118)
		player.x = 118;

	if (player.x < 1)
		player.x = 1;

	if (player.y > 28)
		player.y = 28;

	if (player.y < 5)
		player.y = 5;



}

void PlayerHp()
{
	if (player.hp == 0)
		player.isAlive = false;
}

void GameOver()
{

}
