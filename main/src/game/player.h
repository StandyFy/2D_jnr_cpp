#pragma once
#include "raylib.h"

class Player {
public:
	Vector2 Pos;
	Vector2 Size;

	void Draw();
	void Update();
};