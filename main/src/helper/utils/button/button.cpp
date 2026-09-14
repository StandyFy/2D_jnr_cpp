#include "button.h"

bool Button::isMouseOverButton() {
    if (CheckCollisionPointRec(GetMousePosition(), Destination)) {
        return true;
    }

    return false;
}

bool Button::ClickEvent() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return true;
    }

    return false;
}

void Button::Draw() {
    DrawTexturePro(
        BG,
        HolderRect,
        Destination,
        Origin,
        Rotation,
        Tint
    );

    if (isMouseOverButton() && ClickEvent()) {
        TraceLog(LOG_DEBUG, "Button clicked!");
        onClick();
    }
}   