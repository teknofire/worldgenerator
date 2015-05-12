#ifndef __CS372_ChainOfResponsibility__BaseChain__
#define __CS372_ChainOfResponsibility__BaseChain__

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

class GradiantBase
{
public:
    GradiantBase() = default;
    virtual ~GradiantBase() = default;
    virtual void add(std::shared_ptr<GradiantBase>);
    virtual sf::Color handle(double);
    virtual sf::Color handle(double, double, sf::Color) = 0;
    virtual std::shared_ptr<GradiantBase> getNext();
private:
    std::shared_ptr<GradiantBase> _next;
};

#endif /* defined(__CS372_ChainOfResponsibility__BaseChain__) */
