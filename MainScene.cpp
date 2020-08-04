#include "MainScene.h"
#include "config.h"
#include "QIcon"
#include <QPainter>
#include <QMouseEvent>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化窗口
    initScene();

    //开启游戏
    playGame();
}


MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    //设置窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器的初始化
    map_timer.setInterval(GAME_RATE);


}

void MainScene::playGame()
{
    //启动定时器
    map_timer.start();

    //播放背景音乐
    QSound::play(SOUND_BACKGROUND);

    //监听计时器的信号
    connect(&map_timer, &QTimer::timeout, [=]{

       //更新坐标
        updatePosition();

        //绘制到屏幕中
        update();//注意不是直接调用paintEvent

    });
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_Map.mapPosition();

    //发射子弹
    m_Hero.shoot();

    //更新所有非空闲子弹的坐标
    for(int i = 0 ;i<BULLET_NUM; i++){
        if( !m_Hero.m_Bullets[i].m_Free ){
            m_Hero.m_Bullets[i].updatePosition();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *)
{
    //画家对象
    QPainter painter(this);

    //画地图
    painter.drawPixmap(0,m_Map.m_map1_posY,m_Map.m_map1);
    painter.drawPixmap(0,m_Map.m_map2_posY,m_Map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_Hero.plane_x, m_Hero.plane_y, m_Hero.m_Plane);

    //绘制子弹
    for(int i = 0 ;i<BULLET_NUM; i++){
        if( !m_Hero.m_Bullets[i].m_Free ){
            painter.drawPixmap(m_Hero.m_Bullets[i].m_X, m_Hero.m_Bullets[i].m_Y, m_Hero.m_Bullets[i].m_Bullet);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent * event)
{
    int x = event->x() - m_Hero.m_Rect.width()*0.5;
    int y = event->y() - m_Hero.m_Rect.height()*0.5;
    if(x >= GAME_WIDTH - m_Hero.m_Rect.width()) x = GAME_WIDTH - m_Hero.m_Plane.width();
    else if(x <= 0) x = 0;
    if(y >= GAME_HEIGHT - m_Hero.m_Rect.height()) y = GAME_HEIGHT - m_Hero.m_Plane.height();
    else if(y <= 0) y = 0;
    m_Hero.setPosition(x,y);
}

