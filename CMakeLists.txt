cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

## ✅ Find required ROS packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  robotinfo_msgs
)

## ✅ Declare the catkin package
catkin_package(
  CATKIN_DEPENDS roscpp std_msgs robotinfo_msgs message_runtime
)

## ✅ Include directories
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## ✅ Executable for Normal Robot
add_executable(robot_info_node 
  src/robot_info_main.cpp 
  src/robot_info_class.cpp
)

add_dependencies(robot_info_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(robot_info_node ${catkin_LIBRARIES})

## ✅ Executable for AGV Robot
add_executable(agv_robot_info_node 
  src/agv_robot_info_main.cpp 
  src/agv_robot_info_class.cpp 
  src/robot_info_class.cpp
  src/hydraulic_system_monitor.cpp
)

add_dependencies(agv_robot_info_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(agv_robot_info_node ${catkin_LIBRARIES})