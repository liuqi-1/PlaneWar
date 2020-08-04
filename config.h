#ifndef CONFIG_H
#define CONFIG_H

/**************  游戏配置数据  ***************/
#define GAME_WIDTH   512            //宽度
#define GAME_HEIGHT  768            //高度
#define GAME_TITLE  "PlaneWar"  //标题
#define GAME_RES_PATH "./plane.rcc" //游戏资源路径
#define GAME_RATE 4               //定时器刷新时间间隔  ms为单位
#define GAME_ICON ":/res/app.ico"
#define SOUND_BACKGROUND ":/res/bg.wav"

/**************  地图配置数据  ***************/
#define MAP_PATH ":/res/img_bg_level_2"  //地图路径
#define MAP_SCROLL_SPEED 1         //地图滚动速度


/*************  英雄飞机配置数据  ************/
#define HERO_PATH ":/res/hero.png"

/***************  子弹配置数据  **************/
#define BULLET_PATH ":/res/bullet_11.png"  //子弹图片路径
#define BULLET_SPEED 20     //子弹移动速度
#define BULLET_NUM 100   //子弹总个数
#define BULLET_INTERVAL 2  //子弹发送的时间间隔  单位10ms

/*************** 敌机配置数据  **************/
#define SOUND_BOMB ":/res/bomb.wav"

#endif // CONFIG_H
