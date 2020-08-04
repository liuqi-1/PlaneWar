#include "Map.h"
#include "config.h"
Map::Map()
{
    //初始化加载地图对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //初始化y轴坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    //地图的滚动速度
    map_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{

    //计算map1位置
    m_map1_posY += map_scroll_speed;
    if(m_map1_posY>=0){
        m_map1_posY = -GAME_HEIGHT;
    }

    //计算map2位置
    m_map2_posY += map_scroll_speed;
    if(m_map2_posY>=GAME_HEIGHT){
        m_map2_posY = 0;
    }


}
