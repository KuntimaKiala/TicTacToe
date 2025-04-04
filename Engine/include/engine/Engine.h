#pragma once
#include "engine/Core.h"

namespace FromHeLL
{
    class WindowManager;
    class Engine
    {
    private:
        shared<WindowManager>  m_pWindowManager;
        
    protected :
        char m_cPlayer;
        
    public:
        Engine(int iWidth, int iHeight, const char* pAppName);
        void Setup();
        weak<WindowManager> GetWindowManager()  ;
        virtual void Run() = 0;
        void InputHandler();
        bool Init() const;
        void Exit() const;
        

        ~Engine();
    };
    
    
    
} // namespace FromHeLL

