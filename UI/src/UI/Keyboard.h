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

#ifndef QTCALCULATOR_UI_KEYBOARD_H
#define QTCALCULATOR_UI_KEYBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

#include "Core/Action.h"
#include "UI/ActionButton.h"

using QtCalculator::Core::Action;
using QtCalculator::UI::ActionButton;

namespace QtCalculator {
namespace UI {


    class Keyboard : public QObject
    {

    Q_OBJECT

    public:
        virtual ~Keyboard();

        void init();
        void setContainer(QWidget *);
        void setLayout(QGridLayout *);

    signals:
        void actionClicked(Core::Action);
        void digitClicked(const QString &);

    private:
        QWidget * container;
        QGridLayout * layout;
        QSignalMapper * digitMapper;

        void addDigitButton(const QString &, int, int, int width = 50, int height = 50);
        void addActionButton(Core::Action, const QString &, int, int, int width = 50, int height = 50);

    };


} }

#endif
