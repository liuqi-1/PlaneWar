#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QTimer>
#include "Map.h"
#include "HeroPlane.h"
#include "Bullet.h"
#include "EnemyPlane.h"
#include "Bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:

    MainScene(QWidget *parent = nullptr);

    ~MainScene();

    //初始化场景
    void initScene();


    //启动游戏
    void playGame();

    //结束游戏
    void stopGame();

    //发射敌机
    void launchEnemy();

    //更新所有游戏元素的坐标
    void updatePosition();

    //绘制到屏幕中  函数名不可以更改
    void paintEvent(QPaintEvent* );

    //重写鼠标移动事件  函数名不可更改
    void mouseMoveEvent(QMouseEvent*);

    //碰撞检测函数
    void collisionDetc();

public:

    //地图对象
    Map m_Map;
    
    //飞机对象
    HeroPlane m_Hero;

    //敌机对象
    EnemyPlane enemies[ENEMY_NUM];

    //爆炸对象
    Bomb bomb[BOMB_NUM];

    //地图定时器
    QTimer timer;

    int m_Recoder;

private:


};
#endif // MAINSCENE_H
