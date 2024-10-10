#pragma once
struct Boss
{
	bool isAlive;
	int x;
	int y;

	int hp;

	int index;
	DWORD indexupdatetime;
};




void BossInit();
void BossUpdate();
void BossDraw();

void BossHp();

void BossMove();
void BossClipping();
void CreatBoss(int x, int y);

void BulletBossCollision();