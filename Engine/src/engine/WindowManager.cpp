#include "engine/WindowManager.h"
#include "engine/Core.h"


namespace FromHeLL
{
    

    WindowManager::WindowManager(int iWidth, int iHeight, const char* pAppName)
    : m_iWidth(iWidth)
    , m_iHeight(iHeight)
    , m_pAppName(pAppName)
    , m_pWindow(NULL)
    {
    }
    

    bool WindowManager::IsWindowCreated()
    {
        
        m_pWindow = glfwCreateWindow(m_iWidth,m_iHeight, m_pAppName, NULL, NULL);
        if (!m_pWindow)
        {
            LOG("GLFW Could Not Create Window");
            glfwTerminate();
            return false;
        }
        LOG("Window Creation");
        glfwMakeContextCurrent(m_pWindow);
        ResizeWindow();

        if (!IsGladSucceded())
        {
           return false;
        }
        


        return true;
    }

    void WindowManager::Init()
    {
        if(!glfwInit())
        {
            LOG("OpenGL FrameWork Failed To Initialize");
        }
        glfwInitHint( GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwInitHint( GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwInitHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        
    }

    bool WindowManager::IsGladSucceded() 
    {
        if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG("GLAD Failed");
            return false;
        }
        LOG("GLAD Succeded");
        return true;
    }

    void WindowManager::ResizeWindow()
    {
        glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);
    }

    void WindowManager::framebuffer_size_callback(GLFWwindow*, int iWidth, int iHeight)
    {
        glViewport(0,0,iWidth, iHeight);
    }

    WindowManager::~WindowManager()
    {

    }
} // namespace FromHeLL
