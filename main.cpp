#include "include.h"

int main()
{
	Init();            // �ʱ�ȭ

	while (true)
	{
		Update();       // ����, �Է���ġ ó��
		Draw();         // ������

		EngineSync(30); //�ʴ� 30�� �ݺ��� �� �ֵ��� ����
	}

	Release();     //����, �޸� �����ֱ�

	return 0;
}