#ifndef RENDERER_H
#define RENDERER_H
#include "engine/Shader.h"
#include "Core.h"

namespace Data
{
    static float Vertices[16] = {
        // Vertical lines
        -0.33f,  1.0f,   -0.33f, -1.0f, 
         0.33f,  1.0f,    0.33f, -1.0f,  
        // Horizontal lines
        -1.0f,  0.33f,    1.0f,  0.33f, 
        -1.0f, -0.33f,    1.0f, -0.33f 
                      } ;
} 

namespace FromHeLL
{
    class Renderer
    {
    private:
    
    unique<Shader> m_pShader;
    GLuint m_uiVBO;
    GLuint m_uiVAO;

    void setupGrid() ;
    void RenderBoard();

    public:
        Renderer() = delete;
        Renderer( const String& sPath );
        
        void RenderGame(/*const Board& board*/) ;
        void RenderO(float x, float y);
        void RenderX(float x, float y);
        ~Renderer();
    };
    
   
    
} // namespace FromHeLL



#endif
