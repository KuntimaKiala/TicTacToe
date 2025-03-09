#include "engine/Engine.h"
#include "engine/WindowManager.h"
#include "engine/Core.h"

namespace FromHeLL
{
    
    Engine::Engine(int iWidth, int iHeight, const char* pAppName)
    : m_pWindowManager( new WindowManager(iWidth, iHeight, pAppName) )
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
    void Engine::Setup()
    {

    }
    WindowManager* Engine::GetWindowManager()
    {
        return m_pWindowManager;
    }
    Engine::~Engine()
    {
        delete m_pWindowManager;
    }
} // namespace FromHeLL

