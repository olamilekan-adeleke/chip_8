cmake_minimum_required(VERSION 3.21)

project(chip8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")




include_directories(.)

# add_subdirectory(3rdParty/SDL EXCLUDE_FROM_ALL)
# include_directories(3rdParty/SDL/include)

# include(${CMAKE_SOURCE_DIR}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)


find_package(fmt CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)



add_executable(chip8  src/main.cpp src/Chip8.cpp)
target_compile_options(chip8 PRIVATE -Wall)

target_link_libraries(chip8 PRIVATE 
  fmt::fmt
  imgui::imgui
  $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
  $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)





# target_link_libraries(chip8 SDL2-static SDL2main)
# target_link_libraries(chip8 PRIVATE glad SDL2 imgui)
# target_link_libraries(chip8 ${binary_dir}/libSDL2.a ${binary_dir}/libSDL2main.a)
# target_link_libraries(my_game PRIVATE SDL2::SDL2)

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})

# INCLUDE(FetchContent)
# include(ExternalProject)
# ExternalProject_Add(
#     SDL2
#     GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#     GIT_TAG release-2.26.5
#     CMAKE_ARGS -DSDL_STATIC=ON -DSDL_SHARED=OFF
# )
#
# ExternalProject_Get_Property(SDL2 source_dir binary_dir)
# include_directories(${source_dir}/include)
#

# message("CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
# message("Fetcing 3rd party libs...")
#
# FetchContent_Declare(
#   SDL
#   GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#   GIT_TAG        release-2.0.20
#   GIT_PROGRESS ON
#   LOG_DOWNLOAD ON
# )
# FetchContent_MakeAvailable(sdl)
#
# # Find SDL2
# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})
# add_subdirectory(3rdParty/SDL2 EXCLUDE_FROM_ALL)

# CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/Users/kod_enimga/vcpkg/scripts/buildsystems/vcpkg.cmake"

