#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    /*ѡ�����ص�*/
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    /*�ֶ�ʵ��*/
    CREATE_FUNC(HelloWorld);
};

#endif