#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "izoRender.h"
#include "izoTexture.h"
#include "izoMap.h"
#include "izoObject.h"
#include "time.h"
#include <iostream>
using namespace sf;
using namespace std;


const int map_width = 100, map_height = 100;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 900), "izoRender");
    window.setFramerateLimit(0);

    izoRender render(&window);
    izoTexture textures(10);
    izoMap map(map_width, map_width);
    render.setTextureMaster(&textures);
    render.setMapMaster(&map);
    map.setCellSize(64, 32, 64);
    ///
    textures.loadTexture(1, "texture1.png");
    textures.loadTexture(2, "floor.jpg");
    textures.loadTexture(3, "wall.jpg");
    textures.loadTexture(4, "wall.jpg");

    textures.loadTexture(9, "grass.png");
    ///
    for (int y = 0; y < map_width; y++) {
        for (int x = 0; x < map_width; x++) {
            izoMapCell cell{ 0 };
            //cell.floor = ((x + y) % 2) + 1;
            cell.floor = 1;
            map.setCell(x, y, cell);
        }
    }

    for (int y = 1; y < 4; y++) {
        for (int x = 1; x < 4; x++) {
            izoMapCell cell{ 0 };
            //cell.floor = ((x + y) % 2) + 1;
            cell.floor = 2;
            map.setCell(x, y, cell);
        }
    }

    izoMapCell cell{ 0 };
    cell.floor = 2;
    cell.wall[1] = 3;
    cell.wall[0] = 0;
    map.setCell(1, 1, cell);
    map.setCell(2, 1, cell);
    map.setCell(3, 1, cell);

    cell.floor = 1;

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
    double lastTime = 0;
    ///
    izoObject testObject;
    testObject.combination = false;
    testObject.coordinate_x = 0;
    testObject.coordinate_y = 0;
    testObject.ID = 100;
    testObject.objectSprite.setTexture(textures.getTexture(9)->textureObject);
    testObject.objectSprite.setScale(0.20, 0.20);
    testObject.number = 1;
    izoObjectList* ptrObjectList = new izoObjectList;
    ptrObjectList->addObject(testObject);

    map.setObjectList(0, 5, ptrObjectList);
    ///
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        double currentTime = clock.restart().asSeconds();
        double fps = 1.f / (currentTime - lastTime);
        cout << "FPS :" << fps << endl;
        currentTime = clock.restart().asSeconds();
        lastTime = currentTime;
        window.clear();
        render.draw();
        window.display();
    }

    return 0;
}