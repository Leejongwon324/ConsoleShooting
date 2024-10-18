#pragma once
struct Boss
{
	bool isAlive;
	int x;
	int y;

	int hp;

	int index;

};




void BossInit();
void BossUpdate();
void BossDraw();

void BossMove();
void BossHp();
void CreatBoss(int x, int y);
void BossClipping();

//void BossAttack(int x, int y); 

void BulletBossCollision();