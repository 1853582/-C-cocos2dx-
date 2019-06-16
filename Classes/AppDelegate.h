#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"
#include <string>
using namespace std;
/**
@brief    The cocos2d Application.

����ʵ��Ϊ˽�м̳е�ԭ����Ϊ������Director��һЩ�ӿڵ��á�
*/
class  AppDelegate : private cocos2d::Application 
{
public:
  AppDelegate();
  virtual ~AppDelegate();

  virtual void initGLContextAttrs();

  /**
  @brief    ������ʵ�ֵ��ݺͳ�����ʼ�����롣
  @return true    ��ʼ���ɹ���app������
  @return false   ��ʼ��ʧ�ܣ�app��ֹ��
  */
  virtual bool applicationDidFinishLaunching();

  /**
  @brief  ��Ӧ�ó�������̨ʱ���øú���
  @param  Ӧ�ó����ָ��
  */
  virtual void applicationDidEnterBackground();

  /**
  @brief  ��Ӧ�ó������ǰ̨ʱ���øú���
  @param  Ӧ�ó����ָ��
  */
  virtual void applicationWillEnterForeground();
};

#endif // _APP_DELEGATE_H_

