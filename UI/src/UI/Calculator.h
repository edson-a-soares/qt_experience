/*
 * (C) Copyright 2017 Edson (http://edsonaraujosoares.com) and others.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Contributors:
 *     Edson Araújo Soares
 */

#ifndef QTCALCULATOR_UI_CALCULATOR_H
#define QTCALCULATOR_UI_CALCULATOR_H

#include <QWidget>
#include <QGridLayout>

#include "UI/MenuBar.h"
#include "UI/Display.h"
#include "UI/Keyboard.h"
#include "Core/Action.h"
#include "Core/Engine.h"

namespace QtCalculator {
namespace UI {


    class Calculator : public QWidget
    {

    Q_OBJECT

    public:
        Calculator(QWidget * widget = nullptr);

        void init();
        void setDisplay(Display *);
        void setKeyboard(Keyboard *);
        void setEngine(Core::Engine *);

    public slots:
        void onActionButton(Core::Action);
        void onDigitButton(const QString &);

    private:
        Display * display;
        Keyboard * keyboard;
        QGridLayout * layout;
        Core::Engine * engine;

        void buildMenu();

    };


} }

#endif
