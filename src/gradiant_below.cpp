#include "gradiant_below.h"
#include <iostream>
#include <cmath>

GradiantBelow::GradiantBelow(double height, sf::Color color): _height(height), _color(color)
{
}

sf::Color GradiantBelow::handle(double height)
{
    if(height < _height)
      return _color;
    else
      if (getNext())
        return getNext()->handle(height, _height, _color);

    return GradiantBase::handle(height);
}

sf::Color GradiantBelow::handle(double height, double previousHeight, sf::Color previousColor)
{
    if(height < _height)
    {
      auto delta = std::abs(previousHeight - height) / std::abs(previousHeight - _height);
      return sf::Color(
        cap(interpolate(delta, previousColor.r, _color.r)),
        cap(interpolate(delta, previousColor.g, _color.g)),
        cap(interpolate(delta, previousColor.b, _color.b))
      );
    }
    else
      if (getNext())
        return getNext()->handle(height, _height, _color);

    return GradiantBase::handle(height);
}

int GradiantBelow::interpolate(double t, int a, int b)
{
  return a+t*(b-a);
}

int GradiantBelow::cap(int value)
{
  if (value < 0)
    return 0;
  if (value > 255)
    return 255;

  return value;
}

void GradiantBelow::addBelow(double height, sf::Color color)
{
  add(std::make_shared<GradiantBelow>(height, color));
}
