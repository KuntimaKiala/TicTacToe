#include "game/GameApplication.h"
#include <engine/WindowManager.h>

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
       
        weak<WindowManager> pWindowManager = GetWindowManager();
        oRenderer.SetWindowSize( pWindowManager.lock()->GetWindowWidth(), pWindowManager.lock()->GetWindowHeight() );
        GLFWwindow* pWindow = pWindowManager.lock()->GetWindow();
        
        while (!glfwWindowShouldClose( pWindow ))
        {
            glClearColor(0.f, 0.f, 0.f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            //TODO : Input Handler
            oRenderer.RenderGame();

            glfwSwapBuffers( pWindow );
            glfwPollEvents();
            
            

        }
        
    }
    GameApplication::~GameApplication()
    {
    }
} // namespace FromHeLL
