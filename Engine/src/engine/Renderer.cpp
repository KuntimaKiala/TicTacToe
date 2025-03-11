#include "engine/Renderer.h"

namespace FromHeLL
{
    Renderer::Renderer(const String& sPath)
    : m_pShader( new Shader( sPath ) )
    {
        //std::unique_ptr<Shader> o =  std::make_unique<Shader>(sPath); only on c14
    }
    void Renderer::RenderBoard()
    {
        
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
