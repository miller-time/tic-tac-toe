#include "uiitem.h"

UiItem::UiItem(char identifier, GameEngine *eng) : id (identifier), engine (eng)
{
    switch(identifier)
    {
    case 'x':
        // The X selection indicator
        xSize = 100;
        ySize = 100;
        imageFile = "images/grey-x.png";
        break;
    case 'o':
        // The O selection indicator
        xSize = 100;
        ySize = 100;
        imageFile = "images/grey-o.png";
        break;
    case 'a':
        // The arrow for turn indicator
        xSize = 50;
        ySize = 100;
        imageFile = "images/arrow.png";
        break;
    case 'w':
        // The turn indicator letter
        xSize = 100;
        ySize = 100;
        imageFile = "images/red-x.png";
        break;
    case 'q':
        // The quit button
        xSize = 75;
        ySize = 75;
        imageFile = "images/quit.png";
        break;
    default:
        xSize = 0;
        ySize = 0;
        imageFile = "";
    }
}

QRectF UiItem::boundingRect() const
{
    return QRectF(0,0,xSize,ySize);
}

void UiItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // check to see if a piece got placed, deselect that letter
    if ((id == 'x') && (engine->whatIsSelected() == ' '))
        imageFile = "images/grey-x.png";
    if ((id == 'o') && (engine->whatIsSelected() == ' '))
        imageFile = "images/grey-o.png";
    // check whose turn it is
    if (id == 'w')
    {
        if (engine->whoseTurnIsIt() == 'X')
            imageFile = "images/red-x.png";
        else
            imageFile = "images/red-o.png";
    }

    QPixmap token(imageFile, 0, Qt::AutoColor);
    painter->drawPixmap(0,0,token);
}

QPainterPath UiItem::shape () const
{
    QPainterPath path;
    path.addRect(0,0,xSize,ySize);
    return path;
}

void UiItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!event)
        return;
    if (id == 'x')
    {
        // clicked on select X
        imageFile == "images/x.png";
        QRect target(0,0,xSize,ySize);
        update(target);
        emit selectChanged('X');
        //engine->changeSelect('X');
    }
    else if (id == 'o')
    {
        // clicked on select O
        imageFile == "images/o.png";
        QRect target(0,0,xSize,ySize);
        update(target);
        emit selectChanged('O');
        //engine->changeSelect('O');
    }
    else if (id == 'q')
    {
        emit clicked();
    }
    //emit tokenChange(this);
}
