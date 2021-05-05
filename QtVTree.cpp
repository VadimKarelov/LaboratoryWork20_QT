#include "QtVTree.h"

/*
template <typename T>
void QtVTree<T>::Draw(QGraphicsScene* scene)
{
    if (QtVTree<T>::_root != nullptr)
    {
        Draw_R(QtVTree<T>::_root, scene, scene->width() / 2, 1, scene->width());
    }
}

template <typename T>
void Draw_R(VNode<T>* cur, QGraphicsScene* scene, int centerX, int deepLevel, int oldX)
{
    // go to down elements
    if (cur->left != nullptr)
    {
        int newX = centerX - abs(centerX - scene->width() / 2);
        Draw_R(cur->left, scene, newX, deepLevel + 1, centerX);
    }
    if (cur->right != nullptr)
    {
        int newX = centerX + abs(centerX - scene->width() / 2);
        Draw_R(cur->right, scene, newX, deepLevel + 1, centerX);
    }

    // distance between levels
    int levelSize = 40;

    // drawing line to parent
    // root node dont needed in line to parent
    if (deepLevel > 1)
    {
        // node coords, then parents coords
        QGraphicsItem *line = scene->addLine(centerX, deepLevel * levelSize,
                                             oldX, (deepLevel - 1) * levelSize,
                                             QPen(Qt::black));
        scene->addItem(line);
    }

    // draw ellipse
    int r = 10;
    QGraphicsEllipseItem *ell = scene->addEllipse(centerX - r, deepLevel * levelSize - r,
                                                  r * 2, r * 2, QPen(Qt::yellow));
    scene->addItem(ell);
}
*/
