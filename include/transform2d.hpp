#pragma once
#include <Eigen/Dense>

class Transform2D {
public:
    double x = 0.0;       // Initialize to zero
    double y = 0.0;       // Initialize to zero
    double theta = 0.0;   // Initialize to zero

    // Generate the 3x3 transformation matrix
    Eigen::Matrix3d matrix() const;

    // Transform a 2D point (operator overloading)
    Eigen::Vector2d operator*(const Eigen::Vector2d& point) const;
};