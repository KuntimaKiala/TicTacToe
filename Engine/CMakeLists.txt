

add_library(${ENGINE_TARGET_NAME} STATIC 
            ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h

            ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Engine.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Engine.h

            #${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Renderer.cpp
            #${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Renderer.h
            
            #${CMAKE_CURRENT_SOURCE_DIR}/src/engine/Board.cpp
            #${CMAKE_CURRENT_SOURCE_DIR}/include/engine/Board.h

            #${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c
            )

target_include_directories(  ${ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries( ${ENGINE_TARGET_NAME} PUBLIC glfw GL dl)