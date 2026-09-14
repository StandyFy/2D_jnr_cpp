#include <iostream>
#include "globals.h"

// Initialize Variables
int Screen::Var::mainScreenId = 0;
Vector2 Screen::Var::screenDimension = { 0.0f, 0.0f };

int Screen::Fn::getMainScreen() {
    return GetCurrentMonitor();
}

Vector2 Screen::Fn::getScreenDimensions(int ScreenId) {
    return { 
        static_cast<float>(GetMonitorWidth(ScreenId)),
        static_cast<float>(GetMonitorHeight(ScreenId)),
    };
}

Vector2 Screen::Fn::getScreenCenter(Vector2 ScreenResolution) {
    int width = ScreenResolution.x;
    int height = ScreenResolution.y;

    return Vector2{
        static_cast<float>(width) / 2.0f,
        static_cast<float>(height) / 2.0f
    };
}