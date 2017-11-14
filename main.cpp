#include "DxLib.h"
#include "keyboard.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "circle.h"

//ウィンドウサイズ
#define WINDOW_SIZE_X 640
#define WINDOW_SIZE_Y 480

//ループで必ず行う処理をまとめる
int ProcessLoop() {
	if (ProcessMessage() != 0) return -1;  //プロセス処理がエラーなら-1を返す
	if (ClearDrawScreen() != 0) return -1;  //画面クリア処理がエラーなら-1を返す
	return 0;
}



//-------------------------------------------------------------------------------------------------------------------
//エントリーポイント
//-------------------------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);  //ウィンドウモード
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;  //初期化と裏画面化が失敗したら終了
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, DEFAULT_COLOR_BITDEPTH, DEFAULT_ZBUFFER_BITDEPTH);  //ウィンドウサイズを指定する

	//unsigned int color;
	Circle circle;

	while (ProcessLoop() == 0) {  //メインループ
		Keyboard_Update();

		//color = GetColor(0, 0, 255);
		//DrawCircle(100, 100, 50, color, true);
		//circle.Update();
		
		circle.move.MoveInput();
		circle.Render();
		if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1) break;  //Escキーが押されたら終了
		ScreenFlip();  //裏画面反映
	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}