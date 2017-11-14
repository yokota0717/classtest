#pragma once
#include "move.h"

class Circle {
public:
	int r;
	unsigned int color;
	Move move;

public:
	Circle() :
		r(50),
		color(GetColor(0,0,225))
	{}
	~Circle() {}
	void Update() {
		move.MoveInput();
	}
	void Render() {
		DrawCircle(move.x, move.y, r, color, true);
	}
};