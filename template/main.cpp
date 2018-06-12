#pragma once
#include "DxLib.h"
#include "options.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�C���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(800, 600, 32);
	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}

	XY a(100, 100);
	XY b(200, 200);
	std::vector<Button> buttons;
	buttons.push_back(Button(a, b));

	while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) {
		//DrawBox(a.getX(), a.getY(), b.getX() , b.getY(), white, TRUE);
		clsDx();
		ClearDrawScreen();
		mouseEvent(buttons);
		buttons[0].disp();
		printfDx("%d\n", buttons[0].isSelected() ? 1 : 0);
		ScreenFlip();
	}

	DxLib_End();        // �c�w���C�u�����g�p�̏I������

	return 0;        // �\�t�g�̏I��
}
