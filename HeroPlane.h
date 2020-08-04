#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include "Bullet.h"
#include "config.h"
class HeroPlane
{
public:
    HeroPlane();
    
    //设置飞机位置
    void setPosition(int x, int y);
    
    //发射子弹
    void shoot();
    
    //飞机资源对象
    QPixmap m_Plane;
    
    //飞机坐标
    int plane_x;
    int plane_y;
    
    //飞机的矩形框
    QRect m_Rect;

    //弹匣
    Bullet m_Bullets[BULLET_NUM];

    //发射时间间隔
    int m_Recoder = 0;
};

#endif // HEROPLANE_H
