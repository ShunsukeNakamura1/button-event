#pragma once
#include "DxLib.h"
#include "options.h"

#define BUTTON_SIZE 50
#define BUTTON_SPACE 10
#define WIDTH 5
#define HEIGHT 5
#define TOTAL WIDTH*HEIGHT

void setting();
void disp(std::vector<Button> &buttons, Button post, bool *x);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	setting();
	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}

	//�ϐ���
	std::vector<Button> buttons;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			XY pos1(j * (BUTTON_SIZE + BUTTON_SPACE), i * (BUTTON_SIZE + BUTTON_SPACE));
			XY pos2(j * (BUTTON_SIZE + BUTTON_SPACE) + BUTTON_SIZE, i * (BUTTON_SIZE + BUTTON_SPACE) + BUTTON_SIZE);
			buttons.push_back(Button(pos1, pos2));
		}
	}
	XY pos1(WIDTH * (BUTTON_SIZE + BUTTON_SPACE), 0);
	XY pos2(WIDTH * (BUTTON_SIZE + BUTTON_SPACE) + 40, 30);
	Button post(pos1, pos2, "���M");
	bool x[TOTAL];
	bool isChanged1;
	bool isChanged2;
	/*
	//�ʐM�֌W
	HANDLE hPipe;
	DWORD dwNumberOfBytesRead;
	DWORD dwNumberofBytesWritten;
	hPipe = CreateFile("\\\\.\\pipe\\mypipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hPipe == INVALID_HANDLE_VALUE) {
		return 1;
	}
	*/
	disp(buttons, post, x);
	//���C�����[�v
	while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) {
		isChanged1 = selectButtonEvent(buttons);//�{�^���̏�Ԃ��ω����Ă�����`�悷��
		isChanged2 = clickButtonEvent(post);
		if (isChanged1 || isChanged2) {
			disp(buttons, post, x);
		}
	}

	DxLib_End();        // �c�w���C�u�����g�p�̏I������

	return 0;        // �\�t�g�̏I��
}

void setting() {
	// �E�C���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(800, 600, 32);
}
//�`��
void disp(std::vector<Button> &buttons, Button post, bool *x) {
	clsDx();
	ClearDrawScreen();
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].disp();
		x[i] = buttons[i].isSelected();
	}
	post.disp();
	printfDx("%d\n", buttons[0].isSelected() ? 1 : 0);
	ScreenFlip();
}