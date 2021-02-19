#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "izoRender.h"
#include "izoTexture.h"
#include "izoMap.h"
#include "time.h"
#include <iostream>
using namespace sf;
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 900), "SFML works!");
    window.setFramerateLimit(60);

    izoRender render(&window);
    izoTexture textures(10);
    izoMap map(6, 6);
    render.setTextureMaster(&textures);
    render.setMapMaster(&map);
    map.setCellSize(128, 64, 150);
    ///
    textures.loadTexture(1, "texture.png");
    textures.loadTexture(2, "texture1.png");
    textures.loadTexture(3, "texture2.png");
    textures.loadTexture(4, "texture3.png");
    ///
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 6; x++) {
            izoMapCell cell{ 0 };
            //cell.floor = ((x + y) % 2) + 1;
            cell.floor = 1;
            map.setCell(x, y, cell);
        }
    }
    izoMapCell cell{ 0 };
    cell.floor = 1;
    cell.wall[1] = 3;
    cell.wall[0] = 0;
    map.setCell(1, 1, cell);
    map.setCell(2, 1, cell);
    map.setCell(3, 1, cell);

    map.setCell(1, 4, cell);
    map.setCell(2, 4, cell);
    map.setCell(3, 4, cell);

    cell.wall[1] = 0;
    cell.wall[0] = 4;
    map.setCell(1, 2, cell);
    map.setCell(4, 2, cell);
    map.setCell(1, 3, cell);
    map.setCell(4, 3, cell);
    map.setCell(4, 4, cell);
    cell.wall[1] = 3;
    map.setCell(1, 4, cell);
    sf::Clock clock;
    float lastTime = 0;
    ///
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - lastTime);
        cout << "FPS :" << fps << endl;
        currentTime = clock.restart().asSeconds();
        lastTime = currentTime;
        window.clear();
        render.draw();
        window.display();
    }

    return 0;
}