#ifndef __CS372_ChainOfResponsibility__NegativeHandler__
#define __CS372_ChainOfResponsibility__NegativeHandler__

#include "gradiant_base.h"

class GradiantBelow : public GradiantBase
{
public:
  GradiantBelow(double height, sf::Color color);
  virtual sf::Color handle(double) override;
  virtual sf::Color handle(double, double, sf::Color) override;
  void addBelow(double height, sf::Color color);
  int interpolate(double, int, int);
  int cap(int);
private:
  double _height;
  sf::Color _color;
};

#endif /* defined(__CS372_ChainOfResponsibility__NegativeHandler__) */
