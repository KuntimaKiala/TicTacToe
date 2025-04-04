#include "engine/Engine.h"
#include "engine/WindowManager.h"
#include "engine/Core.h"


namespace FromHeLL
{
    
    Engine::Engine(int iWidth, int iHeight, const char* pAppName)
    : m_pWindowManager( new WindowManager(iWidth, iHeight, pAppName) )
    , m_cPlayer('X')
    {
      
    }
    

    bool Engine::Init() const
    {
        
        m_pWindowManager->Init();
        if (m_pWindowManager->IsWindowCreated())
        {
            
            LOG("Engine Initialization Succeded");
            return true;
        }
        LOG("Engine Failed To Init");
        return false;

    }

    void Engine::InputHandler()
    {
        GLFWwindow* pWindow = m_pWindowManager->GetWindow();
        if( glfwGetKey( pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS )
        {
            glfwSetWindowShouldClose( pWindow,true );
        }
        
    }

    void Engine::Setup()
    {

    }

    weak<WindowManager> Engine::GetWindowManager()
    {
        return m_pWindowManager;
    }

    Engine::~Engine()
    {
        
    }
} // namespace FromHeLL

