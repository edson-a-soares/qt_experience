#include <UI/Display.h>

namespace QtCalculator {
namespace UI {


    Display::Display(QWidget * parent)
        : QLineEdit(parent),
          overwriteMode(false)
    {

        this->setMaxLength(15);
        this->setReadOnly(true);
        this->setFixedWidth(278);
        this->setPlaceholderText("0");
        this->setAlignment(Qt::AlignRight);
        this->setStyleSheet(QString("background-color: white"));

        QPalette palette;
        palette.setColor(QPalette::Text, Qt::black);
        this->setPalette(palette);

    }

    QString Display::getValue() const
    {
        return this->text();
    }

    void Display::setValue(const QString & value)
    {
        if ( overwriteMode ) {
            setText("");
        }
        insert(value);
    }

    void Display::setOverwriteMode(bool flag)
    {
        overwriteMode = flag;
    }


} }
