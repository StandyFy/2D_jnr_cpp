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

    ts.setFontProperties(
        titleText,
        titleFont.getFont(),
        {0,0},
        fontSize,
        textLineSpacing,
        GREEN
    );

    HTexture buttonBG(
        "../src/assets/textures/main-menu/button.jpg"
    );
    
    ts.buttonBG = buttonBG.getTexture();
    ts.buttonPos = Screen::Fn::getScreenCenter(Screen::Fn::getScreenDimensions(Screen::Fn::getMainScreen()));
    ts.buttonRotation = 0.0f;
    ts.buttonScale = 2.0f;
    ts.ButtonTint = WHITE;

    ts.button.BG = buttonBG.getTexture();
    ts.button.Destination = { 100.0f, 100.0f, (float)ts.button.BG.width*2.0f, (float)ts.button.BG.height*2.0f };
    ts.button.HolderRect = { 0, 0, (float)ts.button.BG.width, (float)ts.button.BG.height };
    ts.button.Origin = { 0, 0 };
    ts.button.Rotation = 0.0f;
    ts.button.Tint = WHITE;
    ts.button.onClick = []() {
        Globals::currentScene = Globals::Menu::Game;
    };


    // TODO: Place start button at correct location
    // TODO: Add bg image to start screen!

    // Player
    // Player player;
    // player.Pos = { 400, 600 };
    // player.Size = { 50, 50 };

    // Camera
    // Camera2D camera = { 0 };
    // camera.target = (Vector2){ player.Pos.x + player.Size.x / 2, player.Pos.y + player.Size.y / 2 };
    // camera.offset = (Vector2){ 640, 360 };
    // camera.zoom = 1.0f;


    Vector2 center = Screen::Fn::getScreenCenter(Screen::Var::screenDimension);

    while (!WindowShouldClose()) {
        BeginDrawing();

            if (Globals::currentScene == Globals::Menu::TitleScreen) {
                ts.Draw();
            }
            if (Globals::currentScene == Globals::Menu::Game) {
                ClearBackground(RED);
            }

            DrawFPS(10,10);
        EndDrawing();     
    }

    return 0;
}
