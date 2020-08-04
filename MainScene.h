#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QTimer>
#include "Map.h"
#include "HeroPlane.h"
#include "Bullet.h"

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


    //更新所有游戏元素的坐标
    void updatePosition();

    //绘制到屏幕中  函数名不可以更改
    void paintEvent(QPaintEvent* );

    //重写鼠标移动事件  函数名不可更改
    void mouseMoveEvent(QMouseEvent*);

    //地图对象
    Map m_Map;
    
    //飞机对象
    HeroPlane m_Hero;

    //子弹对象

    //地图定时器
    QTimer map_timer;

private:


};
#endif // MAINSCENE_H
