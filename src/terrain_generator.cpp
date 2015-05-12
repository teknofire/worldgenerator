#include "terrain_generator.h"
#include <math.h>
#include <iostream>

TerrainGenerator::TerrainGenerator(unsigned int seed, int width, int height):_seed(seed),
  _width(width), _height(height), _perlin(seed), _image(std::make_shared<sf::Image>()),
  _texture(std::make_shared<sf::Texture>())
{
  _gradiant = std::make_shared<GradiantBelow>(-1.0f,    sf::Color(0,    0,    128));    //deeps
                          _gradiant->addBelow(-0.25f,   sf::Color(0,    0,    255));    //shallows
                          _gradiant->addBelow(0.f,      sf::Color(0,    128,  255));    //shore
                          _gradiant->addBelow(0.0625f,  sf::Color(240,  240,  64));     //sand
                          _gradiant->addBelow(0.1250f,  sf::Color(32,   160,  0));      //grass
                          _gradiant->addBelow(0.6750f,  sf::Color(128,  224,  0));      //dirt
                          _gradiant->addBelow(0.850f,   sf::Color(128,  128,  128));    //rock
                          _gradiant->addBelow(1.0f,     sf::Color(255,  255,  255));    //snow
  _image->create(width, height, sf::Color::Black);
}

void TerrainGenerator::generate(int z)
{
  auto t = z / 100.f;
  auto amp = 5.0;

  for(auto x=0; x<_width; ++x)
    for(auto y=0; y<_height; ++y)
    {
      double i = (double)x / (double)_width;
      double j = (double)y / (double)_height;
      double n = _perlin.noise(amp * i, amp * j, t);
      _image->setPixel(x, y, color(n));
    }

  _texture->loadFromImage(*_image);
}

sf::Color TerrainGenerator::grayscale(double z)
{
  auto color = floor(128 * z)+128;
  if (color < 0)
    color = 0;
  if (color > 255)
    color = 255;

  return sf::Color(color, color, color);
}

sf::Color TerrainGenerator::color(double z)
{
  return _gradiant->handle(z);
}

std::shared_ptr<sf::Image> TerrainGenerator::getImage()
{
  return _image;
}

std::shared_ptr<sf::Texture> TerrainGenerator::getTexture()
{
  return _texture;
}
