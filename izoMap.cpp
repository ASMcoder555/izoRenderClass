#include "izoMap.h"
#include "izoRender.h"

izoMap::izoMap() {
    width = 0;
    height = 0;
}

izoMap::~izoMap() {
    if (mapArrayCreatedByConstruct) {
        delete[] cellObjectArray;
    }
}

izoMap::izoMap(int32_t width, int32_t height) {
    izoMap::width = width;
    izoMap::height = height;
    cellObjectArray = new izoMapCell[width * height];
    mapArrayCreatedByConstruct = true;
}

izoMap::izoMap(int32_t width, int32_t height, izoMapCell* cellObjectArray) {
    izoMap::width = width;
    izoMap::height = height;
    izoMap::cellObjectArray = cellObjectArray;
    mapArrayCreatedByConstruct = false;
}

void izoMap::setParent(izoRender* parent) {
    render = parent;
}

void izoMap::setCellObjectArray(int32_t width, int32_t height, izoMapCell* cellObjectArray) {
    izoMap::width = width;
    izoMap::height = height;
    izoMap::cellObjectArray = cellObjectArray;
    mapArrayCreatedByConstruct = false;
}

izoMapCell* izoMap::getCellObjectArray() {
    return cellObjectArray;
}

int32_t izoMap::getWidth() {
    return width;
}

int32_t izoMap::getHeight() {
    return height;
}

void izoMap::setCell(int32_t x, int32_t y, izoMapCell cell) {
    if (cellObjectArray == 0)
        throw NULL_POINTER_MAP;
    else if (x >= width || y >= height)
        throw COORD_OUT_OF_RANGE;
    else {
        Texture* texture;
        texture = render->getTexture(cell.floor);
        cell.floorSprite.setTexture(*texture);
        cellObjectArray[x + y * width] = cell;
    }
}

izoMapCell izoMap::getCell(int32_t x, int32_t y) {
    if (cellObjectArray == 0)
        throw NULL_POINTER_MAP;
    else if (x >= width || y >= height)
        throw COORD_OUT_OF_RANGE;
    else {
        return cellObjectArray[x + y * width];
    }
}