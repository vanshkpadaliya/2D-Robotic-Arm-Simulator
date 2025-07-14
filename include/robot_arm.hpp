#pragma once
#include "transform2d.hpp"
#include <vector>

class RobotArm {
public:
    std::vector<double> link_lengths;

    explicit RobotArm(const std::vector<double>& lengths) 
        : link_lengths(lengths) {}

    std::vector<Transform2D> getArmPose(const std::vector<double>& joint_angles) const;
};