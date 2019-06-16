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

//如果需要不同的上下文，只需修改glContextAttrs的值
//它将在所有平台上生效
void AppDelegate::initGLContextAttrs() 
{
  //设置OpenGL上下文属性，现在只能设置6个属性:
  //红,绿,蓝,α,深度、模板
  GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

  GLView::setGLContextAttrs(glContextAttrs);
}

// 如使用包管理器安装更多的包，
// 不要修改或删除此函数
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

  // 关闭显示FPS
  director->setDisplayStats(false);

  // FPS。如果不调用这个函数，默认值是1.0/60
  director->setAnimationInterval(1.0f / 60);

  // 设置设计分辨率
  glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
  Size frameSize = glview->getFrameSize();
  // 如果框架的高度大于中等尺寸的高度。
  if (frameSize.height > mediumResolutionSize.height) 
  {
    director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
  }
  // 如果框架的高度大于小尺寸的高度。
  else if (frameSize.height > smallResolutionSize.height) 
  {
    director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
  }
  // 如果框架的高度小于中等尺寸的高度。
  else 
  {
    director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
  }

  register_all_packages();

  // 创建一个场景。它是一个自动释放对象
  auto scene = HitBrick::createScene();
  //auto scene = Wonderland::createScene();

  // run
  director->runWithScene(scene);

  return true;
}

// 当应用程序处于非活动状态时，将调用此函数。当引用的时候，它也被调用了
void AppDelegate::applicationDidEnterBackground() 
{
  Director::getInstance()->stopAnimation();

  //如果使用SimpleAudioEngine，则必须暂停
  SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//当应用程序再次激活时，将调用此函数
void AppDelegate::applicationWillEnterForeground() 
{
  Director::getInstance()->startAnimation();

  // 如果使用SimpleAudioEngine，它必须在这里继续
  SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
