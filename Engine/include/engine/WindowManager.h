#pragma once 
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace FromHeLL
{
    
    class WindowManager
    {
    private:
        int m_iWidth; 
        int m_iHeight; 
        const char* m_pAppName;
        GLFWwindow* m_pWindow;
        
        static void framebuffer_size_callback(GLFWwindow*, int iWidth, int iHeight) ;
        bool IsGladSucceded() ;
        void ResizeWindow();

    public:
        WindowManager() = delete;
        WindowManager(int iWidth, int iHeight, const char* pAppName);
        inline GLFWwindow* GetWindow() {return m_pWindow;}
        inline int GetWindowHeight() const {return m_iHeight;}
        inline int GetWindowWidth()  const {return m_iWidth;}
        bool IsWindowCreated() ;
        
        void Init() ;
        ~WindowManager();
    };
    
    
} // namespace FromHeLL
