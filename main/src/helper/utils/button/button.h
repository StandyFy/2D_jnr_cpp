#pragma once

#include <iostream>
#include<functional>
#include "raylib.h"

class Button {
public:
    Texture2D BG;
    Rectangle HolderRect;
    Rectangle Destination;
    Vector2 Origin;
    float Rotation;
    Color Tint;
    void (*onClick)() = []() {};

    void Draw();
private:
    bool isMouseOverButton();
    bool ClickEvent();
};