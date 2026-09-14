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
    DrawRectangleV({ 0, 0 }, Screen::Var::screenDimension, BG_COLOR);

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
    
    // TODO: Draw the button with texture here just get an instance of Button
    button.Draw();
}