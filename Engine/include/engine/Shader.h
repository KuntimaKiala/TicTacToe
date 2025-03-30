#pragma once 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "engine/Core.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace FromHeLL
{
    class Shader
    {
    private:
        GLuint ID;
        const std::string& sVertexShaderErrorMessage = "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n";
        const std::string& sFragmentShaderErrorMessage = "ERROR::FRAGMENT::VERTEX::COMPILATION_FAILED\n";
    public:
        Shader() = delete;
        Shader( const String& sDirectoryPath );
        void CompileShader(   GLuint& shader,
                              const std::string& sShaderSourceCode, 
                              const std::string& sErrorMessage = "ERROR::SHADER::UNKNOW::COMPILATION_FAILED\n");
        void  ShaderProgram(const GLuint& vertexShader, const GLuint& framentShader);
        void Use() const ;
        ~Shader();
    };
    
    
} // namespace FromHeLL
