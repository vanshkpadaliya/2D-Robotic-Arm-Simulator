# 2D Robotic Arm Simulator with Collision Avoidance

[![CMake](https://github.com/yourusername/2D-Robotic-Arm-Simulator/actions/workflows/cmake.yml/badge.svg)](https://github.com/yourusername/2D-Robotic-Arm-Simulator/actions/workflows/cmake.yml)

## Introduction

This project simulates the movement of a robotic arm in 2D space using kinematic transformations with collision avoidance capabilities. It demonstrates how robots can be programmed to move efficiently while avoiding obstacles.

## Key Concepts

### Configuration Space (C-Space)
The set of all possible configurations a robot can achieve through:
1. **Rotation** (represented by angle θ)
2. **Translation** (represented by displacement vector x)

### Chasles' Theorem
Any rigid body motion can be described as a rotation followed by a translation.

## Mathematical Foundation

### Rotation Matrices
For 2D rotation (about z-axis):

$$
R_z(\psi) = 
\begin{bmatrix}
\cos \psi & -\sin \psi \\
\sin \psi & \cos \psi
\end{bmatrix}
$$

### Combined Transformation
For a point $p = [x, y]^T$:
$$
p' = R \cdot p + t
$$
where $t = [t_x, t_y]^T$ is the translation vector.

## Implementation

### Dependencies
- Eigen3 (via vcpkg)
- CMake (minimum 3.15)

```sh
vcpkg install eigen3
