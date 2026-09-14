#include "loader.h"

// ==============================================//
//                      Font                     //
// ==============================================//

// Add more utf encoding support default is UTF-8
HFont::HFont(
    const char *fileName, 
    bool isTtf,
    int textLineSpacing,
    int fontSize, 
    int *codepoints,
    int codepointCount
) {
    SetTextLineSpacing(textLineSpacing);

    if (isTtf) {
        loadedFont = LoadFontEx(fileName, fontSize, codepoints, codepointCount);
        return;
    }

    loadedFont = LoadFont(fileName);
}

HFont::~HFont() {
    if (IsFontValid(loadedFont)) {
        UnloadFont(loadedFont);
        TraceLog(LOG_DEBUG, DEBUG_FONT_UNLOADED);
        return;
    } else if (IsFontValid(defaultFont)) {
        UnloadFont(defaultFont);
        TraceLog(LOG_DEBUG, DEBUG_FONT_UNLOADED " | default font");
        return;
    }

    TraceLog(LOG_WARNING, WARN_FONT_NOT_VALID_UNLOADED);
}

Font HFont::getFont() {
    if (!IsFontValid(loadedFont)) {
        TraceLog(LOG_ERROR, ERR_FONT_NOT_VALID);
        return defaultFont;
    }

    TraceLog(LOG_DEBUG, DEBUG_FONT_VALID);
    return loadedFont;
}

// ==============================================//
//                    Texture                    //
// ==============================================//

HTexture::HTexture(const char *fileName) {
    Image image = LoadImage(fileName); // <- Load texture into the ram first
    loadedTexture = LoadTextureFromImage(image); // <- turns loaded image into texture that now sits in th vram 
    UnloadImage(image); // <- instantly free the RAM
}

HTexture::~HTexture() {
    UnloadTexture(loadedTexture);
}

Texture2D HTexture::getTexture() {
    if (IsTextureValid(loadedTexture)) {
        return loadedTexture;
    }

    TraceLog(LOG_ERROR, ERR_TEXTURE_NOT_VALID);
    return LoadTexture("missing_texture.");
}