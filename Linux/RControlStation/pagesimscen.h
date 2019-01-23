/*
    Copyright 2019 Benjamin Vedder	benjamin@vedder.se

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef PAGESIMSCEN_H
#define PAGESIMSCEN_H

#include <QWidget>
#include <QTimer>

#include "mapwidget.h"

#include "ScenarioEngine.hpp"
#include "RoadManager.hpp"
#include "CommonMini.hpp"

namespace Ui {
class PageSimScen;
}

class PageSimScen : public QWidget, public MapModule
{
    Q_OBJECT

public:
    explicit PageSimScen(QWidget *parent = 0);
    ~PageSimScen();

    void processPaint(QPainter &painter, int width, int height, bool highQuality,
                      QTransform drawTrans, QTransform txtTrans, double scale);
    bool processMouse(bool isPress, bool isRelease, bool isMove, bool isWheel,
                      QPoint widgetPos, LocPoint mapPos, double wheelAngleDelta,
                      bool ctrl, bool shift, bool ctrlShift,
                      bool leftButton, bool rightButton);

private slots:
    void timerSlot();

    void on_openScenarioButton_clicked();

private:
    Ui::PageSimScen *ui;
    scenarioengine::ScenarioEngine *mScenarioEngine;
    roadmanager::OpenDrive *mOdrManager;
    scenarioengine::ScenarioGateway *mScenarioGateway;
    double mSimTime;
    QTimer *mTimer;

};

#endif // PAGESIMSCEN_H
