#include "game/GameApplication.h"
#include <engine/Engine.h>


FromHeLL::Engine* GetApplication( int iWidth=500, int iHeight=500, const char* pAppNam="Tic Tac Toe" )
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
        std::cout << "Game Running" <<std::endl;
        while (!glfwWindowShouldClose( GetWindowManager()->GetWindow() ))
        {
            
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                glfwSwapBuffers(GetWindowManager()->GetWindow());
                glfwPollEvents();
            

        }
        
    }
    GameApplication::~GameApplication()
    {
    }
} // namespace FromHeLL
