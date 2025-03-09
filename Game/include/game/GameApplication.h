
#pragma once 
#include <engine/Engine.h>
#include <iostream>
#include <engine/WindowManager.h>
namespace FromHeLL
{
    
    class GameApplication : public Engine
    {
    private:
        /* data */
    public:
        GameApplication(int iWidth=500, int iHeight=500, const char* pAppName="TIC TAC TOE");
        virtual void Run() override;
        ~GameApplication();
    };
    
    
    
} // namespace FromHeLL


