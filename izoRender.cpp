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
    for (int y = 0; y < mapMaster->getHeight(); y++) {
        for (int x = 0; x < mapMaster->getWidth(); x++) {
            izoMapCell cell = mapMaster->getCell(x, y);

            state.transform = cell.floorTransform;
            cell.floorSprite.move(x * mapMaster->getCellWidth(), y * mapMaster->getCellHeight());
            renderWindow->draw(cell.floorSprite, state);
            cell.floorSprite.move(-x * mapMaster->getCellWidth(), -y * mapMaster->getCellHeight());
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
