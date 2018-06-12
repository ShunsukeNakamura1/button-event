#include "options.h"

XY::XY() {}
XY::XY(int x, int y) {
	this->x = x;
	this->y = y;
}
void XY::set(int x, int y) {
	this->x = x;
	this->y = y;
}
void XY::setX(int x) {
	this->x = x;

}
void XY::setY(int y) {
	this->y = y;
}
int XY::getX() {
	return x;
}
int XY::getY() {
	return y;
}

Button::Button(XY pos1, XY pos2) {
	this->pos1 = pos1;
	this->pos2 = pos2;
	selected = false;
	selected = false;
	white = GetColor(255, 255, 255);
	red = GetColor(255, 0, 0);
}
void Button::set(XY pos1, XY pos2) {
	this->pos1 = pos1;
	this->pos2 = pos2;
}
XY Button::getPos1() {
	return pos1;
}
XY Button::getPos2() {
	return pos2;
}
bool Button::isIn() {
	int mouse_x, mouse_y;
	GetMousePoint(&mouse_x, &mouse_y);
	if (pos1.getX() <= mouse_x && mouse_x <= pos2.getX() && pos1.getY() <= mouse_y && mouse_y <= pos2.getY()) {
		return true;
	}
	else {
		return false;
	}
}
bool Button::isSelected() {
	return selected;
}
bool Button::isClicked() {
	return clicked;
}
void Button::disp() {
	if (clicked) {
		DrawBox(pos1.getX(), pos1.getY(), pos2.getX(), pos2.getY(), red, FALSE);
	}
	else if (selected) {
		DrawBox(pos1.getX(), pos1.getY(), pos2.getX(), pos2.getY(), white, TRUE);
	}
	else {
		DrawBox(pos1.getX(), pos1.getY(), pos2.getX(), pos2.getY(), white, FALSE);
	}
}
void Button::select() {
	selected = true;
}
void Button::unselect() {
	selected = false;
}
void Button::toggleSelect() {
	selected = !selected;
}
void Button::click() {
	clicked = true;
}
void Button::unclick() {
	clicked = false;
}

void mouseEvent(std::vector<Button> &buttons) {
	static bool click = false;
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !click) {
		for (int i = 0; i < (int)buttons.size(); i++) {
			if (buttons[i].isIn()) {
				buttons[i].click();
			}
		}
		click = true;
	}
	else if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && click) {

	}
	else {
		for (int i = 0; i < (int)buttons.size(); i++) {
			if (buttons[i].isClicked()) {
				if (buttons[i].isIn()) {
					buttons[i].toggleSelect();
				}
				buttons[i].unclick();
			}
		}
		click = false;
	}
}