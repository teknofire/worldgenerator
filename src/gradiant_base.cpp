#include "gradiant_base.h"

void GradiantBase::add(std::shared_ptr<GradiantBase> next)
{
    if (_next)
        _next->add(next);
    else
        _next = next;
}

std::shared_ptr<GradiantBase> GradiantBase::getNext()
{
    return _next;
}

sf::Color GradiantBase::handle(double number)
{
    return sf::Color(255, 255, 255);
}
