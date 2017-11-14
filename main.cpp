#include "DxLib.h"
#include "keyboard.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "circle.h"

//�E�B���h�E�T�C�Y
#define WINDOW_SIZE_X 640
#define WINDOW_SIZE_Y 480

//���[�v�ŕK���s���������܂Ƃ߂�
int ProcessLoop() {
	if (ProcessMessage() != 0) return -1;  //�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0) return -1;  //��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	return 0;
}



//-------------------------------------------------------------------------------------------------------------------
//�G���g���[�|�C���g
//-------------------------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);  //�E�B���h�E���[�h
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;  //�������Ɨ���ʉ������s������I��
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, DEFAULT_COLOR_BITDEPTH, DEFAULT_ZBUFFER_BITDEPTH);  //�E�B���h�E�T�C�Y���w�肷��

	//unsigned int color;
	Circle circle;

	while (ProcessLoop() == 0) {  //���C�����[�v
		Keyboard_Update();

		//color = GetColor(0, 0, 255);
		//DrawCircle(100, 100, 50, color, true);
		//circle.Update();
		
		circle.move.MoveInput();
		circle.Render();
		if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1) break;  //Esc�L�[�������ꂽ��I��
		ScreenFlip();  //����ʔ��f
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}