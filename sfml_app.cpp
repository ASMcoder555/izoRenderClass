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

    izoRender render(&window);
    izoTexture textures(10);
    izoMap map(6, 6);
    render.setTextureMaster(&textures);
    render.setMapMaster(&map);
    map.setCellSize(128, 64);
    ///
    textures.loadTexture(1, "texture.png");
    textures.loadTexture(2, "texture1.png");
    textures.loadTexture(3, "texture2.png");
    textures.loadTexture(4, "texture3.png");
    ///
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            izoMapCell cell{ 0 };
            cell.floor = ((x + y) % 2) + 1;
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