cmake_minimum_required(VERSION 3.5)
project(PigRobotNode VERSION 0.1.0)

# 定义编译模式 Release/Debug
# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-std=c++14)
add_definitions("-g")

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

message(STATUS "cmake_home_path " ${CMAKE_HOME_DIRECTORY})

# 检查zeromq_factory是否存在
if(EXISTS "${CMAKE_HOME_DIRECTORY}/../zeromq_factory/CMakeLists.txt")
    message(STATUS "找到 zeromq_factory !!! ")
    add_subdirectory(../zeromq_factory build)
    set(LIBZEROMQ_FACTORY_EXISTS TRUE)
endif()

# # 找第三方库
# 找行为树
find_package(behaviortree_cpp_v3)

include_directories(./include)
include_directories(../zeromq_factory/proto/proto_source)

add_executable(${PROJECT_NAME} pig_robot_node.cpp)

target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp_v3)

if(LIBZEROMQ_FACTORY_EXISTS)
    message(STATUS "${PROJECT_NAME} 链接 zeromq_factory")
    target_link_libraries(${PROJECT_NAME} zeromq::factory)
    include_directories(zeromq::factory)
endif()
