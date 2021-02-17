#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

struct izoTextureObject {
    Texture textureObject;
};


#define NULL_POINTER_LIST -1
#define ID_OUT_OF_RANGE -2
class izoTexture {
    int32_t textureListLenght;
    izoTextureObject* textureList;
    bool textureListCreatedByConstruct;

public:
    izoTexture();
    ~izoTexture();
    izoTexture(int32_t textureListLenght);
    izoTexture(int32_t textureListLenght, izoTextureObject* textureList);
    void setTextureList(int32_t textureListLenght, izoTextureObject* textureList);
    izoTextureObject* getTextureList();
    int32_t getTextureListLenght();
    void loadTexture(int32_t ID, izoTextureObject textureObject);
    izoTextureObject* getTexture(int32_t ID);
};