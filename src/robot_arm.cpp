#include "robot_arm.hpp"
#include <cmath>

std::vector<Transform2D> RobotArm::getArmPose(
    const std::vector<double>& joint_angles
) const {
    std::vector<Transform2D> poses;
    Transform2D current_pose; // Initialized to zeros via class definition

    for (size_t i = 0; i < joint_angles.size(); ++i) {
        // Update orientation
        current_pose.theta = (i == 0) ? joint_angles[i] 
                                     : poses.back().theta + joint_angles[i];
        
        // Update position (skip for first joint)
        if (i > 0) {
            double prev_len = link_lengths[i-1];
            current_pose.x = poses.back().x + prev_len * std::cos(poses.back().theta);
            current_pose.y = poses.back().y + prev_len * std::sin(poses.back().theta);
        }
        
        poses.push_back(current_pose);
    }
    return poses;
}