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
    Transform floorTransform;
    //-----------------------
    int32_t wall[4];
    Transform wall_transform[4];
    Sprite wallSprite[4];
};

/*      1
     _______
     |\2  /3|
  0  |  /\  |  
     |/____\|
       
        
    */


#define NULL_POINTER_MAP -1
#define COORD_OUT_OF_RANGE -2

class izoMap {
    izoRender* render;
    izoMapCell* cellObjectArray;
    int32_t width, height;
    int16_t cell_width, cell_height, cell_longitude;
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
    void setCellWidth(int16_t cellWidth);
    void setCellHeight(int16_t cellHeight);
    void setCellSize(int16_t cellWidth, int16_t cellHeight);
    int16_t getCellWidth();
    int16_t getCellHeight();
    void setCell(int32_t x, int32_t y, izoMapCell cell);
    izoMapCell getCell(int32_t x, int32_t y);
};

