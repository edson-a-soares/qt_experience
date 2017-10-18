#include "Core/Engine.h"

namespace QtCalculator {
namespace Core {


    Engine::Engine()
        : result(0)
    { }

    double Engine::getResult()
    {
        return result;
    }

    void Engine::setOperand(double operand)
    { }

    void Engine::setOperation(Action action)
    { }


} }
