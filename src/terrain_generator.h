#ifndef __TERAIN_GENERATOR_H__
#define __TERAIN_GENERATOR_H__

#include <memory>
#include <SFML/Graphics.hpp>
#include "simplex_noise.h"
#include "perlin_noise.h"
#include "gradiant_below.h"

class TerrainGenerator
{
public:
  TerrainGenerator(unsigned int, int, int);
  ~TerrainGenerator() = default;

  void generate(int);
  sf::Color grayscale(double);
  sf::Color color(double);
  std::shared_ptr<sf::Image> getImage();
  std::shared_ptr<sf::Texture> getTexture();
private:
  unsigned int _seed;
  unsigned int _width;
  unsigned int _height;
  PerlinNoise _perlin;
  std::shared_ptr<sf::Image> _image;
  std::shared_ptr<sf::Texture> _texture;
  std::shared_ptr<GradiantBelow> _gradiant;
};

#endif
