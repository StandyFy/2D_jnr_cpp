#include <iostream>
#include "raylib.h"
#include "./src/game/player.h"
#include "./src/dependencies/globals.h"
#include "./src/game/titleScreen/titleScreen.h"
#include "./src/helper/loader.h"

int main() {
    const char *title = "2D Jump And Run in C++";
    InitWindow(0, 0, title);
    ToggleBorderlessWindowed();
    // InitWindow(1280, 720, "DEBUG");

    ClearWindowState(FLAG_WINDOW_TOPMOST); // Fix z ordern when tapped out

    SetTargetFPS(60);

    // Screen
    Screen::Var::mainScreenId = Screen::Fn::getMainScreen();
    Screen::Var::screenDimension = Screen::Fn::getScreenDimensions(Screen::Var::mainScreenId);

    // title screen
    TitleScreen ts;
    
    // Load Font for title
    const char *titleText = "2D Jump And Run in C++";
    const char *fileName = "../src/assets/fonts/PressStart2P-Regular.ttf";
    int textLineSpacing = 10;
    bool isTtf = true;
    int fontSize = 25;
    int codepointCount = 0;
    int *codePoints = LoadCodepoints(titleText, &codepointCount);
    
    // Load the font Texture
    HFont titleFont(
        fileName,
        isTtf,
        textLineSpacing,
        fontSize,
        codePoints,
        codepointCount
    );

    Color fontColor = { 255, 178, 92, 255};
    ts.setFontProperties(
        titleText,
        titleFont.getFont(),
        {0,0},
        fontSize,
        textLineSpacing,
        fontColor
    );

    //BackGround
    HTexture background(
      "../src/assets/textures/main-menu/background.jpg"  
    );

    ts.background = background.getTexture();
    ts.source = {
        0, 
        0, 
        (float)ts.background.width, 
        (float)ts.background.height
    };
    ts.dest = {
        0,
        0,
        Screen::Var::screenDimension.x,
        Screen::Var::screenDimension.y,
    };

    
    // Button
    HTexture buttonBG(
        "../src/assets/textures/main-menu/button.png"
    );
    
    ts.buttonBG = buttonBG.getTexture();
    ts.buttonPos = Screen::Fn::getScreenCenter(Screen::Fn::getScreenDimensions(Screen::Fn::getMainScreen()));
    ts.buttonRotation = 0.0f;
    ts.buttonScale = 5.0f;
    ts.ButtonTint = WHITE;

    float buttonScale = 5.0f;
    ts.button.BG = buttonBG.getTexture();
    ts.button.Destination = { 
        (Screen::Var::screenDimension.x - ts.button.BG.width * buttonScale) / 2.0f, 
        (Screen::Var::screenDimension.y - ts.button.BG.height * buttonScale) / 2.0f, 
        (float)ts.button.BG.width*buttonScale, 
        (float)ts.button.BG.height*buttonScale 
    };
    ts.button.HolderRect = { 0, 0, (float)ts.button.BG.width, (float)ts.button.BG.height };
    ts.button.Origin = { 0, 0 };
    ts.button.Rotation = 0.0f;
    ts.button.Tint = WHITE;
    ts.button.onClick = []() {
        Globals::currentScene = Globals::Menu::Game;
    };

    Vector2 center = Screen::Fn::getScreenCenter(Screen::Var::screenDimension);

    while (!WindowShouldClose()) {
        BeginDrawing(); 

            if (Globals::currentScene == Globals::Menu::TitleScreen) {
                ts.Draw();
            }
            if (Globals::currentScene == Globals::Menu::Game) {
                ClearBackground(RAYWHITE);
            }

            DrawFPS(10,10);
        EndDrawing();
    }

    return 0;
}
