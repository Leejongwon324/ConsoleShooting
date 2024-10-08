#pragma once


//구조체 선언
struct Player   // 구조체(또는 사용자 정의 데이터 타입)
{
	int x; // 멤버 변수
	int y; // 멤버 변수

};

void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void PlayerMove();
void PlayerClipping();