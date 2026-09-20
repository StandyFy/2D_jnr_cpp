#include "titleScreen.h"
#include "../../dependencies/globals.h"
#include "../../helper/loader.h"

void TitleScreen::setFontProperties(
    const char *text,
    Font font,
    Vector2 position,
    float fontSize,
    float spacing,
    Color fontColor
) {
    Text = text;
    _Font = font;
    Position = position;
    FontSize = fontSize;
    Spacing = spacing;
    FontColor = fontColor;
}

void TitleScreen::Draw() {
    // BackGround

    // FIX!!! BACKGROUND IS BLACK AND FPS ARE LAYERING
    if (!IsTextureValid(background)) {
        TraceLog(LOG_ERROR, BG_TEXTURE_NOT_LOADED);
        DrawRectangleV({ 0, 0 }, Screen::Var::screenDimension, BG_COLOR);   
    } else {
        DrawTexturePro(background, source, dest, {0,0}, 0.0f, WHITE);
        TraceLog(LOG_DEBUG, "BACKGROUND LOADED");
    }

    // Do some magic for the title pos
    Vector2 center = Screen::Fn::getScreenCenter(Screen::Var::screenDimension);
    Vector2 textSize = MeasureTextEx(_Font, Text, FontSize, Spacing);
    Vector2 fontPos = {
        center.x - textSize.x / 2.0f,
        (center.y - textSize.y / 2.0f) - 300
    };

    // Title
    DrawTextEx(_Font, Text, fontPos, FontSize, Spacing, FontColor);

    // start button
    if (!IsTextureValid(buttonBG)) {
        TraceLog(LOG_WARNING, "Button BG could't be loaded!");
        ButtonTint = {255, 255, 255};
    }
    
    button.Draw();
}