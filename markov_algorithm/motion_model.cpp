/*
 *  motion_model.cpp
 *   Created on : 2021. 3. 26.
 *       Author : Junyoung Kim
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function declaration
float normal_pdf(float x, float mu, float std);
float motion_model(float pseudo_position, float movement, vector<float> priors, int map_size, int control_stdev);
vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev);


// Main function
int main(){

    float position_stdev = 1.0f;             // set standard deviation of position
    float control_stdev = 1.0f;              // set control input
    float movement_per_timestep = 1.0f;
    int map_size = 25;                       // set map horizon distance in meters 
    vector<float> landmark_positions {5, 10, 20};    // initialize landmarks
    vector<float> priors = initialize_priors(map_size, landmark_positions, position_stdev);

    // step through each pseudo position x (i)    
    for (float i = 0; i < map_size; ++i) {
        float pseudo_position = i;

        // get the motion model probability for each x position
        float motion_prob = motion_model(pseudo_position, movement_per_timestep, priors, map_size, control_stdev);
        
    cout << pseudo_position << "\t" << motion_prob << endl;
  }    

    return 0;
}

float motion_model(float pseudo_position, float movement, vector<float> priors, int map_size, int control_stdev){

    float prob = 0.0;

    return prob;
}

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev) {

    vector<float> priors(map_size, 0.0);  // initailize all priors to 0.0

    float normarlizer = landmark_positions.size() * (position_stdev * 2 + 1);
    for (int i=0; i<landmark_positions.size(); ++i){
        for (float j=1; j <= position_stdev; ++j){
            priors.at(int(j+landmark_positions[i]+map_size)%map_size) += 1.0/normarlizer;
            priors.at(int(-j+landmark_positions[i]+map_size)%map_size) += 1.0/normarlizer;
        }
        priors.at(landmark_positions[i]) += 1.0/normarlizer;
    }

    return priors;
}

float normal_pdf(float x, float mu, float std){

    return (1 / sqrt(2*M_PI*std)) * exp(-1/2 * pow((x-mu)/std,2));
}