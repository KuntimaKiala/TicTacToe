add_executable(${GAME_TARGET_NAME}  
               ${CMAKE_CURRENT_SOURCE_DIR}/src/game/GameApplication.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/include/game/GameApplication.h
)

target_include_directories(${GAME_TARGET_NAME} PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${GAME_TARGET_NAME} PUBLIC ${ENGINE_TARGET_NAME} )