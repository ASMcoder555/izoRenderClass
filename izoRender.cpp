#include "izoRender.h"

Transform matrixSum(const float* Matrix0, float* Matrix1) {
    return Transform(Matrix0[0] + Matrix1[0], Matrix0[1] + Matrix1[1], Matrix0[2] + Matrix1[2], Matrix0[4] + Matrix1[4], Matrix0[5] + Matrix1[5], Matrix0[6] + Matrix1[6], Matrix0[8] + Matrix1[8], Matrix0[9] + Matrix1[9], Matrix0[10] + Matrix1[10]);
}

Transform matrixSum(float* Matrix0, float* Matrix1) {
    return Transform(Matrix0[0] + Matrix1[0], Matrix0[1] + Matrix1[1], Matrix0[2] + Matrix1[2], Matrix0[4] + Matrix1[4], Matrix0[5] + Matrix1[5], Matrix0[6] + Matrix1[6], Matrix0[8] + Matrix1[8], Matrix0[9] + Matrix1[9], Matrix0[10] + Matrix1[10]);
}

izoRender::izoRender(RenderWindow* renderWindow) : renderWindow(renderWindow) {

}

void izoRender::draw() {
    RenderStates state;
    int32_t width = mapMaster->getWidth(), height = mapMaster->getHeight();
    izoMapCell* ptr = mapMaster->getCellObjectArray();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            izoMapCell cell = ptr[x + y * width];
            if (cell.floor != 0) {
                state.transform = cell.floorTransform;
                renderWindow->draw(cell.floorSprite, state);
            }
            if (cell.wall[0] != 0) {
                state.transform = cell.wall_transform[0];
                renderWindow->draw(cell.wallSprite[0], state);
            }
            if (cell.wall[1] != 0) {
                state.transform = cell.wall_transform[1];
                renderWindow->draw(cell.wallSprite[1], state);
            }
        }
    }


}

void izoRender::setTextureMaster( izoTexture* _textureMaster ) {
    izoRender::textureMaster = _textureMaster;
}

void izoRender::setMapMaster( izoMap* _mapMaster ) {
    izoRender::mapMaster = _mapMaster;
    mapMaster->setParent(this);
}

Texture* izoRender::getTexture(int32_t ID) {
    return &(textureMaster->getTexture(ID)->textureObject);
}
