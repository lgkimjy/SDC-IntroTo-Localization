/*
 *  markov_algorithm.cpp
 *   Created on : 2021. 3. 23.
 *       Author : Junyoung Kim
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev);

int main(){
    
    float position_stdev = 1.0f; // set standard deviation of position
    int map_size = 25;           // set map horizon distance in meters 
   
    vector<float> landmark_positions {5, 10, 20};    // initialize landmarks
    vector<float> priors = initialize_priors(map_size, landmark_positions, position_stdev);    // initialize priors

    // print prioty values
    for (int p = 0; p < priors.size(); ++p) {
        cout << priors[p] << endl;
    }

    return 0;
}

vector<float> initialize_priors(int map_size, vector<float> landmark_positions, float position_stdev) {

    vector<float> priors(map_size, 0.0);  // initailize all priors to 0.0

    // for(int i=0, j=0; i<map_size; i++){
    //     if(landmark_positions[j] == i){
    //         priors[i-1] = 1.0 / pow(landmark_positions.size(), 2);
    //         priors[i]= 1.0 / pow(landmark_positions.size(), 2);
    //         priors[i+1]= 1.0 / pow(landmark_positions.size(), 2);
    //         i++; j++;
    //     }
    // }
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