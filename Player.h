#pragma once


//����ü ����
struct Player   // ����ü(�Ǵ� ����� ���� ������ Ÿ��)
{
	int x; // ��� ����
	int y; // ��� ����
	int hp;
	bool isAlive;
};

void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void PlayerMove();
void PlayerClipping();

void PlayerHp();

void GameOver();