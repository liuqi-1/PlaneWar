#include "Bomb.h"
#include "config.h"
Bomb::Bomb()
{
    //坐标
    this->m_X = 0;
    this->m_Y = 0;

    //初始化空闲状态
    this->m_Free = true;

    //当前图片的下标
    this->m_Index = 0;

    //播放爆炸的间隔记录
    m_Recoder = 0;

    //初始化图片
    for(int i = 1 ;i <= BOMB_MAX; i++){
        // %1  占位  用i补位
        QString str = QString(BOMB_PATH).arg(i);
        m_PixArr.push_back(QPixmap(str));
    }

}

void Bomb::updateInfo()
{
    //记录自增
    m_Recoder++;

    //没有达到时间间隔
    if(m_Recoder < BOMB_INTERVAL){
        return ;
    }

    //达到时间间隔
    m_Index ++;
    m_Recoder = 0;

    //判断超出了最大索引范围
    if(m_Index == BOMB_MAX){
        m_Free = true;
        m_Index = 0;
    }
}
