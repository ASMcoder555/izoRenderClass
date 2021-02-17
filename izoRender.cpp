#include "izoRender.h"

izoRender::izoRender(RenderWindow* renderWindow) : renderWindow(renderWindow) {

}

void izoRender::draw() {
    for (int y = 0; y < mapMaster->getHeight(); y++) {
        for (int x = 0; x < mapMaster->getWidth(); x++) {
            izoMapCell cell = mapMaster->getCell(x, y);
            cell.floorSprite.move(x * 255, y * 255);
            renderWindow->draw(cell.floorSprite);
            cell.floorSprite.move(-x * 10, -y * 10);
        }
    }
}

void izoRender::setTextureMaster( izoTexture* _textureMaster ) {
    izoRender::textureMaster = _textureMaster;
}

void izoRender::setMapMaster( izoMap* _mapMaster ) {
    izoRender::mapMaster = _mapMaster;
}

Texture* izoRender::getTexture(int32_t ID) {
    return &(textureMaster->getTexture(ID)->textureObject);
}
