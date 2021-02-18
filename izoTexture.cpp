#include "izoTexture.h"


izoTexture::izoTexture() {
    textureListCreatedByConstruct = false;
    textureListLenght = 0;
    textureList = 0;
}

izoTexture::~izoTexture() {
    if (textureListCreatedByConstruct) {
        delete[] textureList;
    }
}

izoTexture::izoTexture(int32_t textureListLenght) {
    textureListCreatedByConstruct = true;
    izoTexture::textureListLenght = textureListLenght;
    textureList = new izoTextureObject[textureListLenght];
}

izoTexture::izoTexture(int32_t textureListLenght, izoTextureObject* textureList) {
    izoTexture::textureList = textureList;
    izoTexture::textureListLenght = textureListLenght;
    textureListCreatedByConstruct = false;
}

void izoTexture::setTextureList(int32_t textureListLenght, izoTextureObject* textureList) {
    izoTexture::textureList = textureList;
    izoTexture::textureListLenght = textureListLenght;
    textureListCreatedByConstruct = false;
}

izoTextureObject* izoTexture::getTextureList() {
    return textureList;
}

int32_t izoTexture::getTextureListLenght() {
    return textureListLenght;
}

void izoTexture::loadTexture(int32_t ID, izoTextureObject textureObject) {
    if (textureList == 0)
        throw NULL_POINTER_LIST;
    else if (ID >= textureListLenght)
        throw ID_OUT_OF_RANGE;
    else {
        textureList[ID] = textureObject;
    }
 }

void izoTexture::loadTexture(int32_t ID, string filePath) {
    if (textureList == 0)
        throw NULL_POINTER_LIST;
    else if (ID >= textureListLenght)
        throw ID_OUT_OF_RANGE;
    else {
        izoTextureObject textureObject;
        textureObject.textureImage.loadFromFile(filePath);
        textureObject.textureObject.loadFromImage(textureObject.textureImage);
        textureList[ID] = textureObject;
    }
}



izoTextureObject* izoTexture::getTexture(int32_t ID) {
    if (textureList == 0)
        throw NULL_POINTER_LIST;
    else if (ID >= textureListLenght)
        throw ID_OUT_OF_RANGE;
    else
        return &textureList[ID];
}