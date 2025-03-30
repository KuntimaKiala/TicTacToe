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
        GLuint iVertexShader =  glCreateShader(GL_VERTEX_SHADER);
        CompileShader(iVertexShader,sVertexShaderSourceCode, sVertexShaderErrorMessage);

        GLuint iFramentShader = glCreateShader(GL_FRAGMENT_SHADER);
        CompileShader(iFramentShader,sFragmentShaderSourceCode, sFragmentShaderErrorMessage);


        ShaderProgram(iVertexShader, iFramentShader);
        

    }

    void  Shader::ShaderProgram(const GLuint& vertexShader, const GLuint& framentShader)
    {
        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, framentShader);
        glLinkProgram(ID);

        int iSuccess;
        char cInfoLog[512];
        glGetProgramiv(ID, GL_LINK_STATUS, &iSuccess);
        if (!iSuccess)
        {
            glGetProgramInfoLog(ID, sizeof(cInfoLog)/sizeof(char), NULL, cInfoLog);
            std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << cInfoLog << std::endl;
        }
        
        glDeleteShader(vertexShader);
        glDeleteShader(framentShader);
    }
    void Shader::CompileShader(GLuint& shader, const std::string& sShaderSourceCode, const std::string& sErrorMessage)
    {
        int iSucess;
        char cInfoLog[512];
        const char* pShaderSource = sShaderSourceCode.c_str();
        glShaderSource(shader,1, &pShaderSource, NULL); 
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &iSucess);

        if (!iSucess)
        {
            glGetShaderInfoLog(shader, sizeof(cInfoLog)/sizeof(char), NULL, cInfoLog);
            std::cout << sErrorMessage << cInfoLog << std::endl;
        }

        
    }

    void Shader::Use()const
    {
        glUseProgram(ID);
    }
    Shader::~Shader()
    {

    }

} // namespace FromHeLL
