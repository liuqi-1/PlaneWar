#include "EnemyPlane.h"

EnemyPlane::EnemyPlane()
{
    //初始化位置
    this->m_X = 0;
    this->m_Y = 0;
    //设置空闲状态
    this->m_Free = true;
    //加载资源图片
    this->m_Plane.load(ENEMY_PATH);
    //设置移动速度
    this->m_Speed = ENEMY_SPEED;
    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X, m_Y);
}

void EnemyPlane::updatePosition()
{
    //如果是空闲状态不计算坐标
    if(m_Free)
    {
        return ;
    }

    //更新y坐标
    m_Y += ENEMY_SPEED;

    //更新矩形框的位置
    m_Rect.moveTo(m_X, m_Y);

    //如果跑出地图就释放飞机
    if(m_Y >= GAME_HEIGHT + m_Rect.height()){
        m_Free = true;
    }

}

