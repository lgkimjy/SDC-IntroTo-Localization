/*
 *  particle_filter.cpp
 *   Created on : 2021. 4. 13.
 *       Author : Junyoung Kim
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std;

void printSamples(double gps_x, double gps_y, double theta);

int main(){
    double gps_x = 4983;
    double gps_y = 5029;
    double theta = 1.201;

    printSamples(gps_x, gps_y, theta);

    return 0;
}

void printSamples(double gps_x, double gps_y, double theta) {
    std::default_random_engine gen;
    double std_x, std_y, std_theta;

    std_x = 2;
    std_y = 2;
    std_theta = 0.5;

    // Creates a normal (Gaussian) distribution for x,y,theta
    normal_distribution<double> dist_x(gps_x, std_x);
    normal_distribution<double> dist_y(gps_y, std_y);
    normal_distribution<double> dist_theta(theta, std_theta);

    for (int i = 0; i < 3; ++i) {
        double sample_x, sample_y, sample_theta;

        sample_x = dist_x(gen);
        sample_y = dist_y(gen);
        sample_theta = dist_theta(gen);   

        std::cout << "Sample " << i + 1 << " " << sample_x << " " << sample_y << " " << sample_theta << std::endl;
    }
}
