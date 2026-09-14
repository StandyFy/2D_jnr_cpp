#pragma once
#include "raylib.h"

namespace Globals {
    enum class Menu {
        TitleScreen,
        Game
    };

    inline Menu currentScene = Menu::TitleScreen;
}

namespace Screen {
    class Fn {
    public:
        static int getMainScreen();
        static Vector2 getScreenDimensions(int ScreenId);
        static Vector2 getScreenCenter(Vector2 screenResolution);
    };
    
    namespace Var
    {
        extern int mainScreenId;
        extern Vector2 screenDimension;
    }
}