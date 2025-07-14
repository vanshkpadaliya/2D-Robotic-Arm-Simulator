#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include "transform2d.hpp"
#include "robot_arm.hpp"

// Helper function for clean output
void print_point(const char* label, const Eigen::Vector2d& p) {
    std::cout << label << "(" 
              << (std::abs(p.x()) < 1e-10 ? 0.0 : p.x()) << ", " 
              << (std::abs(p.y()) < 1e-10 ? 0.0 : p.y()) << ")\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(6);

    // Test Transform2D
    Transform2D tf{0, 0, M_PI/2};  // 90° rotation
    Eigen::Vector2d point{1, 0};
    print_point("Rotated point: ", tf * point);

    // Test RobotArm - 2-link arm (1.0m and 0.5m)
    RobotArm arm{{1.0, 0.5}};
    auto poses = arm.getArmPose({M_PI/2, M_PI/4});  // 90° + 45°
    
    std::cout << "\nArm Configuration:\n";
    for (size_t i = 0; i < poses.size(); ++i) {
        std::cout << "Link " << i+1 << " end: ("
                  << (std::abs(poses[i].x) < 1e-10 ? 0.0 : poses[i].x) << ", "
                  << (std::abs(poses[i].y) < 1e-10 ? 0.0 : poses[i].y) << ")\n";
    }

    // Test case 1: 90° rotation
Transform2D tf1{0, 0, M_PI/2};
Eigen::Vector2d p1{1, 0};
auto result1 = tf1 * p1;
std::cout << "Test 1 - 90° rotation: (" 
          << result1.x() << ", " << result1.y() << ")\n";

// Test case 2: 45° rotation + translation
Transform2D tf2{1, 1, M_PI/4};
Eigen::Vector2d p2{1, 0};
auto result2 = tf2 * p2;
std::cout << "Test 2 - 45° + translation: (" 
          << result2.x() << ", " << result2.y() << ")\n";
    
    return 0;
}