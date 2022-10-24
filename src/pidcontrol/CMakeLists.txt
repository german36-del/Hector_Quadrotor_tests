cmake_minimum_required(VERSION 3.0.2)
project(pidcontrol)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  tf
)

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES pidcontrol
   CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy tf
#  DEPENDS system_lib
)



include_directories(include ${catkin_INCLUDE_DIRS} )






set(SOURCE controller_node.cpp)
add_executable(${PROJECT_NAME} src/${SOURCE} src/controler.cpp)
target_link_libraries(pidcontrol ${catkin_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INTERNAL_INCLUDES})