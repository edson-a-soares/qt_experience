#include "UI/ActionButton.h"

namespace QtCalculator {
namespace UI {


    ActionButton::ActionButton(QWidget * parent)
        : QPushButton(parent)
    {
        registerEvents();
    }

    void ActionButton::registerEvents()
    {
        connect(this, SIGNAL(clicked()), this, SLOT(clickedEventWrapper()));
    }

    void ActionButton::setAction(Core::Action _action)
    {
        action = _action;
    }

    void ActionButton::clickedEventWrapper()
    {
        emit onAction(action);
    }


} }
