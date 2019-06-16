#include "AppDelegate.h"
#include "HitBrick.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1200, 640);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

//�����Ҫ��ͬ�������ģ�ֻ���޸�glContextAttrs��ֵ
//����������ƽ̨����Ч
void AppDelegate::initGLContextAttrs() 
{
  //����OpenGL���������ԣ�����ֻ������6������:
  //��,��,��,��,��ȡ�ģ��
  GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

  GLView::setGLContextAttrs(glContextAttrs);
}

// ��ʹ�ð���������װ����İ���
// ��Ҫ�޸Ļ�ɾ���˺���
static int register_all_packages() 
{
  return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
  // initialize director
  auto director = Director::getInstance();
  auto glview = director->getOpenGLView();
  if (!glview) 
  {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    glview = GLViewImpl::createWithRect("HitBirck", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
    glview->setIMEKeyboardState(false);
#else
    glview = GLViewImpl::create("HitBirck");
#endif
    director->setOpenGLView(glview);
  }

  // �ر���ʾFPS
  director->setDisplayStats(false);

  // FPS��������������������Ĭ��ֵ��1.0/60
  director->setAnimationInterval(1.0f / 60);

  // ������Ʒֱ���
  glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
  Size frameSize = glview->getFrameSize();
  // �����ܵĸ߶ȴ����еȳߴ�ĸ߶ȡ�
  if (frameSize.height > mediumResolutionSize.height) 
  {
    director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
  }
  // �����ܵĸ߶ȴ���С�ߴ�ĸ߶ȡ�
  else if (frameSize.height > smallResolutionSize.height) 
  {
    director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
  }
  // �����ܵĸ߶�С���еȳߴ�ĸ߶ȡ�
  else 
  {
    director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
  }

  register_all_packages();

  // ����һ������������һ���Զ��ͷŶ���
  auto scene = HitBrick::createScene();
  //auto scene = Wonderland::createScene();

  // run
  director->runWithScene(scene);

  return true;
}

// ��Ӧ�ó����ڷǻ״̬ʱ�������ô˺����������õ�ʱ����Ҳ��������
void AppDelegate::applicationDidEnterBackground() 
{
  Director::getInstance()->stopAnimation();

  //���ʹ��SimpleAudioEngine���������ͣ
  SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//��Ӧ�ó����ٴμ���ʱ�������ô˺���
void AppDelegate::applicationWillEnterForeground() 
{
  Director::getInstance()->startAnimation();

  // ���ʹ��SimpleAudioEngine�����������������
  SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
