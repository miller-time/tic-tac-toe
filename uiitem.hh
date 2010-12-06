// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// uiitem.hh
// UiItem is a class that has been slightly generalized. I had already created
// the GameGrid and GameSquare class, as QGraphicsItem objects, and had multiple
// other objects that needed to be added to the scene. This class handles the
// rest using an id system to differentiate between different types of ui items.

#ifndef _WF_UIITEM_H
#define _WF_UIITEM_H

#include <QtGui>
#include "gameengine.hh"

class UiItem
    : public QObject
    , public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    UiItem(char, GameEngine*);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void needToUpdate();            // the ui item needs to run update()
signals:
    void clicked();                 // tell the board it got clicked
    void selectChanged(char);       // fancier version of clicked()
private:
    char id;                        // what type of ui item this is
    int xSize;                      // width of image used for this item
    int ySize;                      // height
    QString imageFile;              // filename for the image
    GameEngine *engine;             // direct contact to the engine
};

#endif // UIITEM_H
