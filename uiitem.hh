// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


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
    void needToUpdate();
signals:
    void clicked();
    void selectChanged(char);
private:
    char id;
    int xSize;
    int ySize;
    QString imageFile;
    GameEngine *engine;
};

#endif // UIITEM_H
