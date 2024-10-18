#pragma once
struct Enemy
{
	int x;
	int y;
	bool isAlive;
};


void EnemyInit();
void EnemyUpdate();
void EnemyDraw();

void EnemyMove();
void EnemyClipping();
void CreatEnemy(int x, int y);

void BulletEnemyCollision();
void EnemyPlayerCollision();