cmake_minimum_required(VERSION 3.15)
project(RoboticArmSimulator)

# Find Eigen
find_package(Eigen3 REQUIRED)

# Add executable
add_executable(arm_simulator 
    src/main.cpp 
    src/transform2d.cpp 
    src/robot_arm.cpp
)

# Link Eigen
target_link_libraries(arm_simulator PRIVATE Eigen3::Eigen)

# Include directories
target_include_directories(arm_simulator PRIVATE 
    ${EIGEN3_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)