cmake_minimum_required(VERSION 3.17.3) #Change version back to 3.19.1 or something when at work, and back to 3.17.3 at home.
project(SwordStory)

set(CMAKE_CXX_STANDARD 14)

add_executable(SwordStory main.cpp Database.cpp Database.h NewGame.cpp NewGame.h Player.cpp Player.h Weapons.cpp Weapons.h Shop.cpp Shop.h Combat.cpp Combat.h Enemy.cpp Enemy.h Abilities.cpp Abilities.h Spells.cpp Spells.h Game.cpp Game.h Items.cpp Items.h Market.cpp Market.h Embark.cpp Embark.h Mission.cpp Mission.h Library.cpp Library.h sound/my_header.h)



# Path to WinMM.Lib
#link_directories(C:\\ICloud)
#target_link_libraries(template PUBLIC
 #       ${GLFW_LIBRARIES}
 #      ${GLEW_LIBRARIES}
 #      ${OPENGL_LIBRARIES}
 #     winMM.Lib)

#find_package(winMM.lib)
#target_link_libraries(winMM.lib)