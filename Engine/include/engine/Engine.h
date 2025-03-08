#pragma once

namespace FromHeLL
{
    class Engine
    {
    private:
        /* data */
    public:
        Engine(int iWidth, int iHeight, const char* pAppName);
        virtual void Run() = 0;
        ~Engine();
    };
    
    
    
} // namespace FromHeLL

