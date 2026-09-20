#pragma once
#include <iostream>
#include "raylib.h"
#include "../../helper/utils/button/button.h"

#define BG_COLOR { 189, 189, 189, 255 }
#define BG_TEXTURE_NOT_LOADED "Background image could not be loaded!\nReplacing with BG_COLOR"
#define ZERO_TINT { 0, 0, 0, 0 }

class TitleScreen {
public:
    // Background
    Texture2D background;
    Rectangle source;
    Rectangle dest;
    // Pos, Rotation, origin and tint is not needed to be defined.
    // They will always be default

    // Button
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