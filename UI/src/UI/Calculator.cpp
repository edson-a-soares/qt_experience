#include <UI/Calculator.h>

namespace QtCalculator {
namespace UI {


    Calculator::Calculator(QWidget * widget)
        : QWidget(widget),
          engine (nullptr)
    {

        this->move(400, 100);
        this->setFixedSize(300, 350);
        this->setWindowTitle("QtCalculator");

        layout = new QGridLayout();
        setLayout(layout);

    }

    void Calculator::init()
    {

        buildMenu();

        keyboard->setLayout(layout);
        keyboard->setContainer(this);
        keyboard->init();

        layout->addWidget(display, 0, 0, 2, 4, Qt::AlignTop);

        connect(keyboard, SIGNAL(digitClicked(const QString &)), this, SLOT(onDigitButton(const QString &)));
        connect(keyboard, SIGNAL(actionClicked(Core::Action)), this, SLOT(onActionButton(Core::Action)));

    }

    void Calculator::setDisplay(Display * _display)
    {
        display = _display;
    }

    void Calculator::setKeyboard(Keyboard * _keyboard)
    {
        keyboard = _keyboard;
    }

    void Calculator::buildMenu()
    {
        this->layout->setMenuBar(new MenuBar(this));
    }

    void Calculator::onDigitButton(const QString & digit)
    {
        display->setValue(digit);
        display->setOverwriteMode(false);
    }

    void Calculator::onActionButton(Core::Action action)
    {

        if ( display->getValue() != "" ) {

            engine->setOperand(display->getValue().toDouble());
            engine->setOperation(action);

            display->setOverwriteMode(true);
            display->setValue(QString::number(engine->getResult()));

        }

    }

    void Calculator::setEngine(Core::Engine * _engine)
    {
        engine = _engine;
    }


} }
