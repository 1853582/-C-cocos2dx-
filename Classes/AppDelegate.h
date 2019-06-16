#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"
#include <string>
using namespace std;
/**
@brief    The cocos2d Application.

将其实现为私有继承的原因是为了隐藏Director的一些接口调用。
*/
class  AppDelegate : private cocos2d::Application 
{
public:
  AppDelegate();
  virtual ~AppDelegate();

  virtual void initGLContextAttrs();

  /**
  @brief    在这里实现导演和场景初始化代码。
  @return true    初始化成功，app继续。
  @return false   初始化失败，app终止。
  */
  virtual bool applicationDidFinishLaunching();

  /**
  @brief  当应用程序进入后台时调用该函数
  @param  应用程序的指针
  */
  virtual void applicationDidEnterBackground();

  /**
  @brief  当应用程序进入前台时调用该函数
  @param  应用程序的指针
  */
  virtual void applicationWillEnterForeground();
};

#endif // _APP_DELEGATE_H_

