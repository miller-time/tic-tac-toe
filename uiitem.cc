// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// uiitem.cc
// UiItem's implementation.

#include "uiitem.hh"
#include <QDebug>

// Probably the craziest constructor ever.
// Since this class has an id system, upon construction its fate is decided, and
// its path is chosen. If it was destined to just be the arrow next to the turn
// indicator, then it'll just load its image and sit there. Each of the different
// cases is a different ui item that is loaded.
UiItem::UiItem(char identifier, GameEngine *eng) : id (identifier), engine (eng)
{
    switch(identifier) {
    case 'x':
        // The X selection indicator
        xSize = 100;
        ySize = 100;
        imageFile = ":/images/grey-x.png";
        break;
    case 'o':
        // The O selection indicator
        xSize = 100;
        ySize = 100;
        imageFile = ":/images/grey-o.png";
        break;
    case 'a':
        // The arrow for turn indicator
        xSize = 30;
        ySize = 60;
        imageFile = ":/images/arrow.png";
        break;
    case 'w':
        // The turn indicator letter
        xSize = 60;
        ySize = 60;
        imageFile = ":/images/red-x.png";
        break;
    case 'q':
        // The quit button
        xSize = 50;
        ySize = 50;
        imageFile = ":/images/quit.png";
        break;
    default:
        xSize = 0;
        ySize = 0;
        imageFile = "";
    }
}

// 1st requirement for creating custom QGraphicsItem.
// Describes a rectangular shape around the object
QRectF
UiItem::boundingRect() const
{
    return QRectF(0,0,xSize,ySize);
}

// 2nd requirement. This is what is drawn on the screen.
// Each type of item has a different filename. Normally they will just use
// the drawPixmap function to load that image. Notice that the selection
// buttons and turn indicator change constantly so re-painting the correct
// image is how that is done.
void
UiItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // check to see if a piece got placed, deselect that letter
    if ((id == 'x') && (engine->whatIsSelected() == ' '))
        imageFile = ":/images/grey-x.png";
    if ((id == 'o') && (engine->whatIsSelected() == ' '))
        imageFile = ":/images/grey-o.png";
    // check whose turn it is
    if (id == 'w') {
        //qDebug() << engine->whoseTurnIsIt();
        if (engine->whoseTurnIsIt() == 'X')
            imageFile = ":/images/red-x.png";
        else
            imageFile = ":/images/red-o.png";
    }

    QPixmap token(imageFile, 0, Qt::AutoColor);
    painter->drawPixmap(0,0,token);
}

// 3rd requirement. Not sure what the difference is between
// this and boundingRect
QPainterPath
UiItem::shape () const
{
    QPainterPath path;
    path.addRect(0,0,xSize,ySize);
    return path;
}

// When Ui Items get clicked on different things can happen. The only
// interesting ones are the selection buttons and the cool little exit button.
// The exit button uses the simple clicked signal, the selection buttons
// have to tell the board what got clicked. Note that they also change blue
// and repaint themselves.
void
UiItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!event)
        return;
    if (id == 'x') {
        // clicked on select X
        emit selectChanged('X');
        imageFile = ":/images/blue-x.png";
        QRect target(0,0,xSize,ySize);
        update(target);
    } else if (id == 'o') {
        // clicked on select O
        emit selectChanged('O');
        imageFile = ":/images/blue-o.png";
        QRect target(0,0,xSize,ySize);
        update(target);
    } else if (id == 'q') {
        emit clicked();
    }
}

// The board has asked for a repaint.
void
UiItem::needToUpdate()
{
    //qDebug() << "Got the 'need to update' signal!";
    QRect target(0,0,xSize,ySize);
    update(target);
}
