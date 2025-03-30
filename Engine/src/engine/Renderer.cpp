#include "engine/Renderer.h"

namespace FromHeLL
{
    Renderer::Renderer(const String& sPath)
    : m_pShader( new Shader( sPath ) )
    {
        //std::unique_ptr<Shader> o =  std::make_unique<Shader>(sPath); only on c14

        setupGrid();

    }

    void Renderer::setupGrid() 
    {
        glGenVertexArrays(1, &m_uiVAO);
        glGenBuffers(1, &m_uiVBO);

        glBindVertexArray(m_uiVAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_uiVBO);


        glBufferData(GL_ARRAY_BUFFER,sizeof(Data::Vertices), Data::Vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }
    void Renderer::RenderBoard()
    {
        
        m_pShader->Use();
        glBindVertexArray(m_uiVAO);
        glDrawArrays(GL_LINES, 0, 8);

    }
    
    void Renderer::RenderO(float x, float y)
    {
    }
    
    void Renderer::RenderX(float x, float y)
    {
    }
    
    Renderer::~Renderer()
    {
       
    }
} // namespace FromHeLL
