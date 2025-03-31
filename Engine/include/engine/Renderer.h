#ifndef RENDERER_H
#define RENDERER_H
#include "engine/Shader.h"
#include "Core.h"


namespace FromHeLL
{
    class Renderer
    {
    private:
    
    unique<Shader> m_pShader;
    GLuint m_uiVBO;
    GLuint m_uiVAO;
    int m_iWidth;
    int m_iHeight;

    void setupGrid() ;
    void RenderBoard();
    void RenderO(float x, float y);
    void RenderX(float x, float y);
    
    public:
        Renderer() = delete;
        Renderer( const String& sPath );
        void SetWindowSize( int iWidth, int iHeight ) ;
        void RenderGame(/*const Board& board*/) ;
        
        ~Renderer();
    };
    
   
    
} // namespace FromHeLL



#endif
