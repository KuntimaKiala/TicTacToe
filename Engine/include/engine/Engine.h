#pragma once
#include "engine/Core.h"

namespace FromHeLL
{
    class WindowManager;
    class Engine
    {
    private:
    shared<WindowManager>  m_pWindowManager;
    public:
        Engine(int iWidth, int iHeight, const char* pAppName);
        void Setup();
        weak<WindowManager> GetWindowManager()  ;
        virtual void Run() = 0;
        bool Init() const;
        void Exit() const;
        

        ~Engine();
    };
    
    
    
} // namespace FromHeLL

