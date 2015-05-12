#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "terrain_generator.h"

int main()
{
  unsigned int seed = 104, width = 256, height = 256;

  auto terrain = TerrainGenerator(seed, width, height);
  auto t = 10;
  sf::Texture texture;

  // if (!image->saveToFile("result.png"))
  //   return -1;

  sf::RenderWindow window(sf::VideoMode(width, height), "My window");
  sf::Sprite sprite;
  sprite.setPosition(0,0);

  terrain.generate(t);
  sprite.setTexture(*terrain.getTexture());

  auto dir = 1;

  // run the program as long as the window is open
  while (window.isOpen())
  {
      // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
      while (window.pollEvent(event))
      {
        switch(event.type)
        {
          case sf::Event::Closed:
          {
            window.close();
            break;
          }
          case sf::Event::KeyReleased:
          {
            switch(event.key.code)
            {
              case sf::Keyboard::Escape:
              {
                window.close();
                break;
              }
            }
          }
        }
      }

      // clear the window with black color
      window.clear(sf::Color::Black);

      // draw everything here...
      t += dir;
      terrain.generate(t);

      window.draw(sprite);

      // end the current frame
      window.display();
  }


  return 0;
}
