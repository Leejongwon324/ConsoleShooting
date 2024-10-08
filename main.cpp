#include "include.h"

int main()
{
	Init();            // 초기화

	while (true)
	{
		Update();       // 연산, 입력장치 처리
		Draw();         // 렌더링

		EngineSync(30); //초당 30번 반복할 수 있도록 고정
	}

	Release();     //해제, 메모리 돌려주기

	return 0;
}