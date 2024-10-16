#include <stdio.h>
#include <Windows.h>	//win32 API
#include <time.h>
#include "Define.h"

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Effect.h"
#include "Boss.h"
#include "Item.h"

#include "UI.h"

extern Player player;
extern Bullet bullets[D_BULLET_MAX];
extern Enemy enemys[D_ENEMY_MAX];
extern int score;
extern int bulletscount;

extern Item items[D_ITEM_MAX];

extern Boss bosses;


void Init();
void Update();
void Draw();
void Release();

void DrawStr(int x, int y, const char* str, WORD color);
void DrawChar(int x, int y, const char c, WORD color);
void EngineSync(int fps);
void ClearScreen();
void Flip();