#pragma once
#include <iostream>
#include "raylib.h"
#include "../../helper/utils/button/button.h"

#define BG_COLOR { 189, 189, 189, 255 }

class TitleScreen {
public:
    Texture2D buttonBG;
    Vector2 buttonPos;
    float buttonRotation;
    float buttonScale;
    Color ButtonTint;
    Button button;


    
    void setFontProperties(
        const char *text,
        Font font,
        Vector2 position,
        float fontSize,
        float spacing,
        Color fontColor
    );

    void Draw();

private:
    const char *Text;
    Font _Font;
    Vector2 Position;
    float FontSize;
    float Spacing;
    Color FontColor;
};