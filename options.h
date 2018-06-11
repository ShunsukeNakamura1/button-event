#pragma once
#include "DxLib.h"
#include <vector>

struct XY {
private:
	int x, y;
public:
	XY();
	XY(int x, int y);
	void set(int x, int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

struct Button {
private:
	XY pos1;
	XY pos2;
	bool selected;
	bool clicked;
	unsigned int white;
	unsigned int red;
public:
	Button(XY pos1, XY pos2);
	void set(XY pos1, XY pos2);
	XY getPos1();
	XY getPos2();
	bool isIn();
	bool isSelected();
	bool isClicked();
	void disp();
	void select();
	void unselect();
	void toggleSelect();
	void click();
	void unclick();
};

void mouseEvent(std::vector<Button> &buttons);