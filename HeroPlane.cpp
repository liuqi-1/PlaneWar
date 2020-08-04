#include "HeroPlane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    //初始化加载飞机图片资源
    m_Plane.load(HERO_PATH);
            
     //初始化飞机
    plane_x = (GAME_WIDTH-m_Plane.width()) * 0.5;
    plane_y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(plane_x,plane_y);
}

void HeroPlane::setPosition(int x, int y)
{
    plane_x = x;
    plane_y = y;
    m_Rect.moveTo(plane_x,plane_y);
}

void HeroPlane::shoot()
{
    //累加时间间隔记录变量
    m_Recoder ++;

    //未达到时间间隔
    if(m_Recoder < BULLET_INTERVAL){
        return ;
    }

    //达到发射时间
    m_Recoder = 0;

    //发射子弹
    for(int i = 0;i < BULLET_NUM; i++){
        //如果是空闲的子弹就发射
        if(m_Bullets[i].m_Free){
            //改变状态
            m_Bullets[i].m_Free = false;
            //设置坐标
            m_Bullets[i].m_X = plane_x + m_Rect.width()*0.5 - m_Bullets[i].m_Rect.width()*0.5;
            m_Bullets[i].m_Y = plane_y - m_Bullets[i].m_Rect.height();
            break;
        }
    }
}
