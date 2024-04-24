cmake_minimum_required(VERSION 3.10)
project(data-aquisition-system)

file(GLOB_RECURSE ECO_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_THREAD_PREFER_PTHREAD ON)                                                                                                                                                                                                           
set(THREADS_PREFER_PTHREAD_FLAG ON)                                                                                                                                                                                                           
find_package(Threads REQUIRED)                                                                                                                                                                                                                
find_package(Boost 1.65.1 REQUIRED COMPONENTS system)

# include directories
include_directories(${Boost_INCLUDE_DIRS} src)

# target executable and its source files
add_executable(ecosim ${ECO_SRCS})

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/public
        ${CMAKE_CURRENT_BINARY_DIR}/public
        COMMENT "Copying resources into binary directory")

add_dependencies(ecosim copy_resources)

# link Boost libraries to the target executable
target_link_libraries(ecosim ${Boost_LIBRARIES})
target_link_libraries(ecosim  Threads::Threads)                                                                                                 