#ifndef CONFIG_H
#define CONFIG_H

/**************  游戏配置数据  ***************/
#define GAME_WIDTH   512            //宽度
#define GAME_HEIGHT  768            //高度
#define GAME_TITLE  "PlaneWar"  //标题
#define GAME_RES_PATH "./plane.rcc" //游戏资源路径
#define GAME_RATE 4               //定时器刷新时间间隔  ms为单位
#define GAME_ICON ":/res/app.ico"  //游戏图标

/**************   游戏音效配置   ***************/
#define SOUND_BACKGROUND ":/res/bg.wav"   //背景音乐
#define SOUND_BOMB ":/res/bomb.wav"   //爆炸音效

/**************  地图配置数据  ***************/
#define MAP_PATH ":/res/img_bg_level_5"  //地图路径
#define MAP_SCROLL_SPEED 1         //地图滚动速度


/*************  英雄飞机配置数据  ************/
#define HERO_PATH ":/res/hero2.png"

/***************  子弹配置数据  **************/
#define BULLET_PATH ":/res/bullet_12.png"  //子弹图片路径
#define BULLET_SPEED 20     //子弹移动速度
#define BULLET_NUM 20   //子弹总个数
#define BULLET_INTERVAL 20  //子弹发送的时间间隔  单位10ms

/*************** 敌机配置数据  **************/
#define ENEMY_PATH ":/res/img-plane_6.png"   //资源路径
#define ENEMY_NUM 20  //敌机总数量
#define ENEMY_SPEED 2  //移动速度
#define ENEMY_INTERVAL 50  //发射时间间隔  单位10ms

/*****************爆炸数据配置**************/
#define BOMB_PATH ":/res/bomb-%1.png"  //爆炸图片资源
#define BOMB_NUM 20   //爆炸数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 10  //爆炸切图时间间隔

#endif // CONFIG_H
