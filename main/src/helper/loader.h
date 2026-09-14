#pragma once

#include <iostream>
#include "raylib.h"

#define ERR_FONT_NOT_VALID "Font is not Valid and couldn't be loaded. Loaded Default font instead."
#define ERR_TEXTURE_NOT_VALID "Texture is not valid and couldn't be loaded"
#define WARN_FONT_NOT_VALID_UNLOADED "Font wasn't valid and cloudn't be unloaded"
#define DEBUG_FONT_VALID "Font loaded!"
#define DEBUG_FONT_UNLOADED "Font unloaded!"

class HFont {
public:
    HFont(
        const char *fileName, 
        bool isTtf,
        int textLineSpacing,
        int fontSize = 12, 
        int *codepoints = (int*)128,
        int codepointCount = 0
    );
    ~HFont();

    Font getFont();

private:
    Font loadedFont;
    Font defaultFont = GetFontDefault();
};

class HTexture {
public:
    HTexture(const char *fileName);
    ~HTexture();

    Texture2D getTexture();

private: 
    Texture2D loadedTexture;
};