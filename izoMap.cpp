#include "izoMap.h"
#include "izoRender.h"

izoMap::izoMap() : cell_width(64), cell_height(64), cell_longitude(64) {
    width = 0;
    height = 0;
}

izoMap::~izoMap() {
    if (mapArrayCreatedByConstruct) {
        delete[] cellObjectArray;
    }
}

izoMap::izoMap(int32_t width, int32_t height) : cell_width(64), cell_height(64), cell_longitude(64){
    izoMap::width = width;
    izoMap::height = height;
    cellObjectArray = new izoMapCell[width * height];
    mapArrayCreatedByConstruct = true;
}

izoMap::izoMap(int32_t width, int32_t height, izoMapCell* cellObjectArray) : cell_width(64), cell_height(64), cell_longitude(64) {
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

void izoMap::setCellWidth( int16_t cellWidth ) {
    cell_width = cellWidth;
}

void izoMap::setCellHeight(int16_t cellHeight ) {
    cell_height = cellHeight;
}

void izoMap::setCellSize(int16_t cellWidth, int16_t cellHeight) {
    cell_width = cellWidth;
    cell_height = cellHeight;
}

int16_t izoMap::getCellWidth() {
    return cell_width;
}

int16_t izoMap::getCellHeight() {
    return cell_height;
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
        if (cell.floor != 0) {
            texture = render->getTexture(cell.floor);
            float scale_x = static_cast<float>(cell_width) / static_cast<float>(texture->getSize().x);
            float scale_y = static_cast<float>(cell_height) / static_cast<float>(texture->getSize().y);
            cell.floorSprite.scale(scale_x, scale_y);
            const float* matrix = cell.floorTransform.getMatrix();
            cell.floorTransform = Transform(matrix[0], -1.0, 650, matrix[4], matrix[5], 200, matrix[8], matrix[9], matrix[10]);
            if (cell.floor != 0)
                cell.floorSprite.setTexture(*texture);
        }
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