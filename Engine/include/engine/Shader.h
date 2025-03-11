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
    public:
        Shader() = delete;
        Shader( const String& sDirectoryPath );
        void Use() const ;
        ~Shader();
    };
    
    
} // namespace FromHeLL
