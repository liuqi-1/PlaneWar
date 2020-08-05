#include "MainScene.h"
#include "config.h"
#include "QIcon"
#include <QPainter>
#include <QMouseEvent>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化敌机刷新记录变量
    m_Recoder= 0;

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
    timer.setInterval(GAME_RATE);


}

void MainScene::playGame()
{
    //启动定时器
    timer.start();

    //播放背景音乐
    QSound::play(SOUND_BACKGROUND);

    //监听计时器的信号
    connect(&timer, &QTimer::timeout, [=]{

       //更新坐标
        updatePosition();

        //绘制到屏幕中
        update();//注意不是直接调用paintEvent

    });
}

void MainScene::stopGame()
{

    timer.stop();
}

void MainScene::launchEnemy()
{
    m_Recoder ++;

    //如果还没达到间隔时间，不发射敌机，return掉该函数
    if(m_Recoder < ENEMY_INTERVAL){
        return ;
    }

    //充值记录变量
    m_Recoder = 0;

    //发射敌机
    for(int i = 0;i < ENEMY_NUM; i++){
        if(enemies[i].m_Free){
            //如果是空闲状态就发射
            //设置状态
            enemies[i].m_Free = false;
            //初始化位置
            enemies[i].m_Y = 0;
            //srand(time(NULL));
            enemies[i].m_X = rand()%GAME_WIDTH;
            if(enemies[i].m_X >= GAME_WIDTH - enemies[i].m_Rect.width()){
                enemies[i].m_X = GAME_WIDTH - enemies[i].m_Rect.width();
            }
            break;
        }
    }
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_Map.mapPosition();

    //发射子弹
    m_Hero.shoot();

    //发射敌机
    launchEnemy();

    //碰撞检测
    collisionDetc();

    //更新所有非空闲子弹的坐标
    for(int i = 0 ;i<BULLET_NUM; i++){
        if( !m_Hero.m_Bullets[i].m_Free ){
            m_Hero.m_Bullets[i].updatePosition();
        }
    }

    //更新所有非空闲敌机的坐标
    for(int i = 0 ;i<ENEMY_NUM; i++){
        if(!enemies[i].m_Free){
            enemies[i].updatePosition();
        }
    }

    //更新所有非空闲爆炸特效
    for(int i = 0 ;i < BOMB_NUM; i++){
        if(!bomb[i].m_Free){
            bomb[i].updateInfo();
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

    //绘制敌机
    for(int i = 0 ;i<ENEMY_NUM; i++){
        if(!enemies[i].m_Free){
            painter.drawPixmap(enemies[i].m_X, enemies[i].m_Y,enemies[i].m_Plane);
        }
    }

    //绘制爆炸特效
    for(int i = 0 ;i < BOMB_NUM; i++){
        if(!bomb[i].m_Free){
            painter.drawPixmap(bomb[i].m_X, bomb[i].m_Y, bomb[i].m_PixArr[bomb[i].m_Index]);
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

void MainScene::collisionDetc()
{
    //遍历所有飞机
    for(int i = 0; i < ENEMY_NUM ; i++){


        //空闲飞机不检测碰撞
        if( enemies[i].m_Free){
            continue;
        }

        //检测是否与英雄飞机碰撞
        if(enemies[i].m_Rect.intersects(m_Hero.m_Rect)){
            //释放爆炸效果
            for(int i = 0; i < BOMB_NUM; i++){
                if(bomb[i].m_Free){
                    bomb[i].m_Free = false;
                    bomb[i].m_X = enemies[i].m_Rect.x();
                    bomb[i].m_Y = enemies[i].m_Rect.y();
                    break;
                }
            }
            stopGame();
        }

        //检测是否和子弹碰撞
        for(int j = 0; j < BULLET_NUM; j++){
            //空闲子弹不检测碰撞
            if(m_Hero.m_Bullets[j].m_Free)
                continue;
            if(enemies[i].m_Rect.intersects(m_Hero.m_Bullets[j].m_Rect)){
                //跟新空闲状态
                enemies[i].m_Free = true;
                m_Hero.m_Bullets[j].m_Free = true;
                //释放爆炸效果
                for(int i = 0; i < BOMB_NUM; i++){
                    if(bomb[i].m_Free){
                        bomb[i].m_Free = false;
                        bomb[i].m_X = enemies[i].m_Rect.x();
                        bomb[i].m_Y = enemies[i].m_Rect.y();
                        break;
                    }
                }
                //播放爆炸音效
                QSound::play(SOUND_BOMB);
            }
        }
    }
}

