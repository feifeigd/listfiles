
cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.24.tar.gz"
    SHA1 "75f3b4507be7375370b25fa183c9c955e80ccf9c"
)

project(listfiles)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

aux_source_directory(src SRC)

# Tell CMake to create the helloworld executable
add_executable(
    listfiles
    
    #main.cpp
    #MainWindow.cpp
    #MainWindow.ui
	${SRC}
)

target_link_libraries(listfiles
    Boost::filesystem
    Boost::system
)