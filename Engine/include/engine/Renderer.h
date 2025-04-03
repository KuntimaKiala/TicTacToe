#ifndef RENDERER_H
#define RENDERER_H
#include "engine/Shader.h"
#include "Core.h"
#include <glm/glm.hpp>

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
        float m_fxPos;
        float m_fyPos;
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
        inline void setXCursorPos( double xpos) { m_fXCursorPos =(float) xpos;}
        inline float getXCursorPos() const { return m_fXCursorPos;};
        
        inline void setYCursorPos( double ypos) { m_fYCursorPos =(float) ypos;}
        inline float getYCursorPos() const { return m_fYCursorPos;};
        inline void setMouseClickedState( bool bState) { bIsMouseCliked = bState; }
        inline bool getMouseClickedState() const { return bIsMouseCliked; }
        void NormalizedDeviceCoordinate() ;
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        inline void ResetNDCoordinate();
        glm::vec2 GetCellPosition( int row, int col);
    public:
        Renderer() = delete;
        explicit Renderer( const String& sPath );
        void SetWindowSize( int iWidth, int iHeight ) ;
        void RenderGame( Board& board ) ;
        
        
        inline void SetWindow( GLFWwindow* pWindow) { m_pWindow = pWindow ;}

        

        ~Renderer();
    };
    
   
    
} // namespace FromHeLL



#endif
