#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "izoTexture.h"
#include "izoMap.h"
class izoMap;
class izoTexture;
using namespace std;
using namespace sf;


#define TEXTURE_MASTER_NULL_POINTER -1;
class izoRender {
    RenderWindow* renderWindow;
    izoTexture* textureMaster;
    izoMap* mapMaster;
public:
    izoRender(RenderWindow* renderWindow);

    void setTextureMaster(izoTexture* _textureMaster);
    void setMapMaster(izoMap* _mapMaster);
    void draw();
    Texture* getTexture(int32_t ID);
};

