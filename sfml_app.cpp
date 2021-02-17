#include <SFML/Graphics.hpp>
#include "izoRender.h"
#include "izoTexture.h"
#include "izoMap.h"
#include <iostream>
using namespace sf;
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 900), "SFML works!");

    Sprite floor;
    Texture texture;
    texture.loadFromFile("texture.png");
    floor.setTexture(texture);
    floor.scale(0.3, 0.3);
    izoRender render(&window);
    izoTexture textures(10);
    izoMap map(10, 10);
    map.setParent(&render);

    render.setTextureMaster(&textures);
    render.setMapMaster(&map);
    ///
    izoTextureObject _izoTexture;
    _izoTexture.textureObject = texture;
    textures.loadTexture(1, _izoTexture);
    ///
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            izoMapCell cell;
            cell.floor = 1;
            map.setCell(x, y, cell);
        }
    }
    ///
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        render.draw();
        window.display();
    }

    return 0;
}