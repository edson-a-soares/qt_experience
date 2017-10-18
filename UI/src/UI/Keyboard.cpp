#include <UI/Keyboard.h>

namespace QtCalculator {
namespace UI {


    Keyboard::~Keyboard()
    {
        delete layout;
        delete container;
        delete digitMapper;
    }

    void Keyboard::setLayout(QGridLayout * layout)
    {
        this->layout = layout;
    }

    void Keyboard::setContainer(QWidget * container)
    {
        this->container = container;
    }

    void Keyboard::init()
    {

        digitMapper = new QSignalMapper(this);
        connect(digitMapper, SIGNAL(mapped(const QString &)), this, SIGNAL(digitClicked(const QString &)));

        addActionButton(Core::Action::REDO,      "Redo",  2, 0);
        addActionButton(Core::Action::UNDO,      "Undo",  2, 1);
        addActionButton(Core::Action::SQRT,      "Sqrt",  2, 2);
        addActionButton(Core::Action::CLEAR,     "Clear", 2, 3);
        addActionButton(Core::Action::BACKSPACE, "Back",  2, 4);

        addDigitButton("7", 3, 0);
        addDigitButton("8", 3, 1);
        addDigitButton("9", 3, 2);
        addActionButton(Core::Action::DIVIDE,     "/", 3, 3);
        addActionButton(Core::Action::PERCENTAGE, "%", 3, 4);

        addDigitButton("4",     4, 0);
        addDigitButton("5",     4, 1);
        addDigitButton("6",     4, 2);
        addActionButton(Core::Action::MULTIPLY,      "*",   4, 3);
        addActionButton(Core::Action::PLUS_OR_MINUS, "+/-", 4, 4);

        addDigitButton("1",     5, 0);
        addDigitButton("2",     5, 1);
        addDigitButton("3",     5, 2);
        addActionButton(Core::Action::SUBTRACT, "-", 5, 4);

        addDigitButton("0", 6, 0, 110, 50);
        addActionButton(Core::Action::DOT,    ".", 6, 2);
        addActionButton(Core::Action::SUM,    "+", 5, 3, 50, 104);
        addActionButton(Core::Action::EQUALS, "=", 6, 4);

    }

    void Keyboard::addActionButton(Core::Action action, const QString & label, int line, int column, int width, int height)
    {

        ActionButton * button = new ActionButton(container);

        button->setText(label);
        button->setAction(action);
        button->setFixedSize(width, height);
        layout->addWidget(button, line, column);

        connect(button, SIGNAL(onAction(Core::Action)), this, SIGNAL(actionClicked(Core::Action)));

    }

    void Keyboard::addDigitButton(const QString & label, int line, int column, int width, int height)
    {

        QPushButton * button = new QPushButton(label, container);

        button->setFixedSize(width, height);
        layout->addWidget(button, line, column);

        digitMapper->setMapping(button, label);
        connect(button, SIGNAL(clicked()), digitMapper, SLOT(map()));

    }


} }
