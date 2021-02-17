#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "izoRender.h"
class izoRender;
using namespace std;
using namespace sf;

struct izoMapCell {
    int32_t floor;
    Sprite floorSprite;
};


#define NULL_POINTER_MAP -1
#define COORD_OUT_OF_RANGE -2

class izoMap {
    izoRender* render;
    izoMapCell* cellObjectArray;
    int32_t width, height;
    bool mapArrayCreatedByConstruct;
public:
    izoMap();
    ~izoMap();
    izoMap(int32_t width, int32_t height);
    izoMap(int32_t width, int32_t height, izoMapCell* cellObjectArray);
    void setParent(izoRender* parent);
    void setCellObjectArray(int32_t width, int32_t height, izoMapCell* cellObjectArray);
    izoMapCell* getCellObjectArray();
    int32_t getWidth();
    int32_t getHeight();
    void setCell(int32_t x, int32_t y, izoMapCell cell);
    izoMapCell getCell(int32_t x, int32_t y);
};

