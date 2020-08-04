#include "Bullet.h"

Bullet::Bullet()
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH);

    //子弹的坐标
    m_X= 0;
    m_Y = 0;

    //子弹的状态
    m_Free = true;

    //子弹速度
    m_Speed = BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());

    //子弹位置
    m_Rect.moveTo(m_X, m_Y);
}

void Bullet::updatePosition()
{
    if(m_Free){
        //空闲状态的子弹不计算坐标
        return;
    }

    //子弹向上移动
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    //子弹位置超出屏幕
    if(m_Y <= -m_Rect.height()){
        m_Free = true;
    }
}
