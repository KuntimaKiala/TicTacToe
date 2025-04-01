

add_library(${ENGINE_TARGET_NAME} STATIC 
            ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h

            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Engine.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Engine.h

            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/glad.c
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Core.h


            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/WindowManager.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/WindowManager.h
            
            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Renderer.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Renderer.h

            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Shader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Shader.h

            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Board.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Board.h
            )




target_include_directories(  ${ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries( ${ENGINE_TARGET_NAME} PUBLIC glfw GL dl)


set(SHADER_FOLDER_NAME "shader")
set(SHADER_FOLDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${SHADER_FOLDER_NAME}")

configure_file(
    "Config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h"
    ESCAPE_QUOTES
)