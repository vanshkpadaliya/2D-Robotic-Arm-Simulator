#include "transform2d.hpp"
#include <Eigen/Dense>
#include <cmath>
#include <limits>

Eigen::Matrix3d Transform2D::matrix() const {
    Eigen::Matrix3d T;
    
    // Clean near-zero values
    auto clean = [](double val) {
        const double epsilon = 10 * std::numeric_limits<double>::epsilon();
        return std::abs(val) < epsilon ? 0.0 : val;
    };

    const double c = clean(std::cos(theta));
    const double s = clean(std::sin(theta));
    
    T << c,    -s,    clean(x),
         s,     c,    clean(y),
         0.0,   0.0,  1.0;
    
    return T;
}

Eigen::Vector2d Transform2D::operator*(const Eigen::Vector2d& point) const {
    Eigen::Vector3d homog_point(point.x(), point.y(), 1.0);
    Eigen::Vector3d transformed = matrix() * homog_point;
    
    // Final cleanup of results
    auto clean = [](double val) {
        return std::abs(val) < 1e-10 ? 0.0 : val;
    };
    
    return {clean(transformed.x()), clean(transformed.y())};
}