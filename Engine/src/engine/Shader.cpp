#include "engine/Shader.h"


namespace FromHeLL
{
    Shader::Shader( const String& sDirectoryPath )
    {
        const String& sVertexShaderPath   =  sDirectoryPath + "vShader.glsl";
        const String& sFragmentShaderPath =  sDirectoryPath + "fShader.glsl";
        String sVertexShaderSourceCode, sFragmentShaderSourceCode;
        std::ifstream oVertexShaderFile, oFragmentShaderFile ;
        oVertexShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        oFragmentShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

        try
        {
            oVertexShaderFile.open(sVertexShaderPath);
            oFragmentShaderFile.open(sFragmentShaderPath);
            
            std::stringstream oVertexStream, oFragmentStream ; 
            oVertexStream << oVertexShaderFile.rdbuf();
            oFragmentStream << oFragmentShaderFile.rdbuf();
            

            oVertexShaderFile.close();
            oFragmentShaderFile.close();

            sVertexShaderSourceCode   = oVertexStream.str();
            sFragmentShaderSourceCode = oFragmentStream.str();

        }
        catch(std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        
    }

    void Shader::Use() const 
    {
        glUseProgram(ID);
    }
    Shader::~Shader()
    {

    }

} // namespace FromHeLL
