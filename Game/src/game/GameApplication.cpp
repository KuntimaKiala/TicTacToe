#include "game/GameApplication.h"


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
        
        Renderer oRenderer( GetResourceDir() );
        std::cout << std::endl;
        while (!glfwWindowShouldClose( GetWindowManager()->GetWindow() ))
        {
            glClearColor(1.f, 1.f, 1.f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(GetWindowManager()->GetWindow());
            glfwPollEvents();
            

        }
        
    }
    GameApplication::~GameApplication()
    {
    }
} // namespace FromHeLL
