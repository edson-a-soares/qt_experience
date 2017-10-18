#include "UI/MenuBar.h"

namespace QtCalculator {
namespace UI {


    MenuBar::MenuBar(QWidget * parent)
        : QMenuBar(parent)
    {

        fileMenu = new QMenu(tr("&File"), parent);
        fileMenu->addAction("E&xit");

        helpMenu = new QMenu(tr("&Help"), parent);
        helpMenu->addAction(tr("&About"));

        this->addMenu(fileMenu);
        this->addMenu(helpMenu);

    }


} }
