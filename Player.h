#pragma once


//����ü ����
struct Player   // ����ü(�Ǵ� ����� ���� ������ Ÿ��)
{
	int x; // ��� ����
	int y; // ��� ����

};

void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void PlayerMove();
void PlayerClipping();