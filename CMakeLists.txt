cmake_minimum_required(VERSION 3.16)
project(robot_behavior_tree)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find BehaviorTree.CPP package
find_package(behaviortree_cpp REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} robot_behavior_tree.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    BT::behaviortree_cpp
)