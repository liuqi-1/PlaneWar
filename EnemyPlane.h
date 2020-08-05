#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include "config.h"
#include <QPixmap>
#include <QRect>
class EnemyPlane
{
public:
    EnemyPlane();

    void updatePosition();


public:

    int m_X;

    int m_Y;

    int m_Speed;

    bool m_Free;

    QPixmap m_Plane;

    QRect m_Rect;
};

#endif // ENEMYPLANE_H
