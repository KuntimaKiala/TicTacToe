#include "game/GameApplication.h"
#include <engine/WindowManager.h>
#include <engine/Board.h>

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
        oRenderer.SetWindow( pWindow );

        Board oBoard;
        
        while (!glfwWindowShouldClose( pWindow ))
        {
            glClearColor(0.f, 0.f, 0.f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            InputHandler();
            
            oRenderer.RenderGame( oBoard );
            

            glfwSwapBuffers( pWindow );
            glfwPollEvents();
            
        }
        glfwTerminate();
        
    }
    GameApplication::~GameApplication()
    {
    }
} // namespace FromHeLL
