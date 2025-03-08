#include "game/GameApplication.h"
#include <engine/Engine.h>

FromHeLL::Engine* GetApplication( int iWidth=500, int iHeight=500, const char* pAppNam="LEARN OPENGL" )
{
    return new FromHeLL::GameApplication(iWidth, iHeight, pAppNam);
}

namespace FromHeLL
{
    GameApplication::GameApplication(int iWidth, int iHeight, const char* pAppName)
    :Engine(iWidth, iHeight, pAppName)
    {
    }
    
    void GameApplication:: Run()
    {
        std::cout << "RUNNING" <<std::endl;
    }
    GameApplication::~GameApplication()
    {
    }
} // namespace FromHeLL
