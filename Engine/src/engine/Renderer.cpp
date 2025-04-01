#include "engine/Renderer.h"

namespace FromHeLL
{
    Renderer::Renderer(const String& sPath)
    : m_pShader( new Shader( sPath ) )
    , m_uiVBO(0)
    , m_uiVAO(0)
    , m_iWidth(0)
    , m_iHeight(0)
    {
        //std::unique_ptr<Shader> o =  std::make_unique<Shader>(sPath); only on c14
        setupGrid();

    }

    void Renderer::setupGrid() 
    {

        float Vertices[16] = {
            // Vertical lines
            -0.33f,  1.0f,   -0.33f, -1.0f, 
             0.33f,  1.0f,    0.33f, -1.0f,  
            // Horizontal lines
            -1.0f,  0.33f,    1.0f,  0.33f, 
            -1.0f, -0.33f,    1.0f, -0.33f 
                             };

        glGenVertexArrays(1, &m_uiVAO);
        glGenBuffers(1, &m_uiVBO);

        glBindVertexArray(m_uiVAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_uiVBO);


        glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices), Vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }

    void Renderer::RenderGame(/*const Board& board*/)
    {
        RenderBoard();
    }
    void Renderer::RenderBoard()
    {
        
        m_pShader->Use();
        glBindVertexArray(m_uiVAO);
        glDrawArrays(GL_LINES, 0, 8); // there are 8 vertices in 

    }
    
    void Renderer::RenderO(float x, float y)
    {
    }
    
    void Renderer::RenderX(float x, float y)
    {
    }
    
    void Renderer::SetWindowSize(int iWidth, int iHeight)
    { 
        if (this !=NULL && this->m_pShader != NULL) 
        { 
            m_iWidth =  iWidth; 
            m_iHeight = iHeight;
        } 
    }
    Renderer::~Renderer()
    {
       
    }
} // namespace FromHeLL
