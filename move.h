#pragma once
#include "DxLib.h"
#include "keyboard.h"

class Move {
public:
	int x, y;

public:
	Move():
	x(100),
	y(100)
	{}
	~Move(){}
	
	void MoveInput() {
		if (Keyboard_Get(KEY_INPUT_LEFT) == 1) x -= 10;
		if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) x += 10;
		if (Keyboard_Get(KEY_INPUT_UP) == 1) y -= 10;
		if (Keyboard_Get(KEY_INPUT_DOWN) == 1) y += 10;
	}
	void MoveAuto() {}
};