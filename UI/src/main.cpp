#include <QApplication>

#include "UI/Display.h"
#include "UI/Keyboard.h"
#include "Core/Engine.h"
#include "UI/Calculator.h"

int main(int argc, char * argv[]) {

    QApplication app(argc, argv);

    // Calculator main component
    QtCalculator::UI::Calculator calculatorView;

    QtCalculator::Core::Engine engine;
    calculatorView.setEngine(&engine);

    calculatorView.setDisplay(new QtCalculator::UI::Display());
    calculatorView.setKeyboard(new QtCalculator::UI::Keyboard());

    calculatorView.init();
    calculatorView.show();

    return app.exec();

}
