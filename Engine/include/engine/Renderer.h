#ifndef RENDERER_H
#define RENDERER_H
#include "engine/Shader.h"
#include "Core.h"


namespace FromHeLL
{   
    class Board;
        
    class Renderer
    {
        private:
        
        unique<Shader> m_pShader;
        GLuint m_uiVBO;
        GLuint m_uiVAO;
        int m_iWidth;
        int m_iHeight;
        GLFWwindow* m_pWindow;

        static float m_fXCursorPos;
        static float m_fYCursorPos;
        static bool bIsMouseCliked;

        void setupGrid() ;
        void RenderBoard();
        void RenderO(float x, float y);
        void RenderX(float x, float y);
        GLFWwindow* GetWindow() { return m_pWindow;}
        void HandleMouseClick(double xpos, double ypos) ;
        void SetMouseCallback( GLFWwindow* pWindow );
        
    public:
        Renderer() = delete;
        Renderer( const String& sPath );
        void SetWindowSize( int iWidth, int iHeight ) ;
        void RenderGame( Board& board ) ;
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        
        inline void SetWindow( GLFWwindow* pWindow) { m_pWindow = pWindow ;}

        inline void setXCursorPos( double xpos) { m_fXCursorPos =(float) xpos;}
        inline float getXCursorPos() const { return m_fXCursorPos;};

        inline void setYCursorPos( double ypos) { m_fYCursorPos =(float) ypos;}
        inline float getYCursorPos() const { return m_fYCursorPos;};
        inline void setMouseClickedState( bool bState) { bIsMouseCliked = bState; }
        inline bool getMouseClickedState() const { return bIsMouseCliked; }

        ~Renderer();
    };
    
   
    
} // namespace FromHeLL



#endif
