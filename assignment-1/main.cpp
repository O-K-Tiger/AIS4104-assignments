#include <iostream>

#include <Eigen/Dense>

double deg_to_rad(double degrees) {
    return degrees * M_PI / 180;
}

double rad_to_deg(double radians) {
    return radians * 180 / M_PI;
}


Eigen::Matrix3d rotate_x(double degrees) {
    double radians = deg_to_rad(degrees);
    Eigen::Matrix3d matrix;
    matrix <<
        1.0, 0.0, 0.0,
        0.0, std::cos(radians), -std::sin(radians),
        0.0, std::sin(radians), -std::cos(radians);
    return matrix;
}

void example(double constant)
{
    Eigen::Matrix3d identity;
    identity <<
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0;
    std::cout << "I: " << std::endl << identity << std::endl << std::endl;
    std::cout << constant <<"*I: " << std::endl << constant * identity << std::endl << std::endl;
}

int main()
{
    //example(2.0);
    Eigen::Matrix3d x_0 = rotate_x(0.0);
    std::cout << "x_0: " << std::endl << x_0 << std::endl << std::endl;
    Eigen::Matrix3d x_45 = rotate_x(45);
    std::cout << "x_45: " << std::endl << x_45 << std::endl << std::endl;
    return 0;
}
