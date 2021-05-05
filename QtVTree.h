#ifndef QTVTREE_H
#define QTVTREE_H
#pragma once
#include <QColor>
#include <QFile>
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QtCore/qmath.h>
#include <QTextStream>
#include "VTree.h"

template <typename T>
class QtVTree : public VTree<T>
{
public:
    QtVTree(unsigned int treeSize = 0) : VTree<T>(treeSize) {}

    QtVTree(vector<T> vec) : VTree<T>(vec) {}

    void Draw(QGraphicsScene* scene)
    {        
        if (QtVTree<T>::_root != nullptr)
        {
            //Draw_R(QtVTree<T>::_root, scene, scene->width() / 2, 1, scene->width());
            Draw_R(QtVTree<T>::_root, scene, 0, 1, 0);
        }
    }
};

// draw function
template <typename T>
void Draw_R(VNode<T>* cur, QGraphicsScene* scene, int centerX, int deepLevel, int oldX)
{
    // go to down elements
    if (cur->left != nullptr)
    {
        // formula for 1st layer is different
        int newX;
        if (cur->parent == nullptr)
        {
            newX = -1 * scene->width() / 2;
        }
        else
        {
            newX = centerX - abs(oldX - centerX) / 2;
        }

        Draw_R(cur->left, scene, newX, deepLevel + 1, centerX);
    }
    if (cur->right != nullptr)
    {
        int newX;
        if (cur->parent == nullptr)
        {
            newX = scene->width() / 2;
        }
        else
        {
            newX = centerX + abs(oldX - centerX) / 2;
        }

        Draw_R(cur->right, scene, newX, deepLevel + 1, centerX);
    }

    // distance between levels
    int levelSize = 60;
    int startY = -1 * scene->height() * 5;

    // drawing line to parent
    // root node dont need line to parent
    if (deepLevel > 1)
    {
        // node coords, then parents coords
        QGraphicsItem *line = scene->addLine(centerX, startY + deepLevel * levelSize,
                                             oldX, startY + (deepLevel - 1) * levelSize,
                                             QPen(Qt::black));
        scene->addItem(line);
    }

    // draw ellipse
    int r = 19;
    QGraphicsEllipseItem *ell = scene->addEllipse(centerX - r, startY + deepLevel * levelSize - r,
                                                  r * 2, r * 2, QPen(Qt::black), QBrush(Qt::darkYellow));
    scene->addItem(ell);

    // draw text
    QFont font("Times");
    QGraphicsTextItem *txt = scene->addText(QString::number(cur->data), font);
    txt->setPos(centerX - r, startY + deepLevel * levelSize - r);
}
#endif // QTVTREE_H
