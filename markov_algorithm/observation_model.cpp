/*
 *  observation_model.cpp
 *   Created on : 2021. 4. 6.
 *       Author : Junyoung Kim
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<float> vf;

float normal_pdf(float x, float mu, float std);
float observation_model(vf landmark_positions, vf observations, vf pseudo_ranges, float distance_max, float observation_stdev);
vf pseudo_range_estimator(vf landmark_positions, float pseudo_position);

int main(){

    float observation_stdev = 1.0f;
    int map_size = 25;
    float distance_max = map_size;
    vf observations {5.5, 13, 15};
    vf landmark_positions {5, 10, 12, 20};

    // step through each pseudo position x(i)
    for(int i = 0; i < map_size; ++i){
        float pseudo_position = float(i);
        // get pseudo ranges
        vf pseudo_ranges = pseudo_range_estimator(landmark_positions, pseudo_position);

        // cout each pos pseudo ranges
        if(pseudo_ranges.size() > 0){
            for (int s = 0; s < pseudo_ranges.size(); ++s)
                cout << "x: " << i << "\t" << pseudo_ranges[s] << endl;
            cout << "-----------------------" << endl;
        }
        //get observation probability
        float observation_prob = observation_model(landmark_positions, observations, pseudo_ranges, distance_max, observation_stdev);
        cout << observation_prob << endl;
    } 

    return 0;
}

vf pseudo_range_estimator(vf landmark_positions, float pseudo_position){
    // define pseudo observation vector
    vf pseudo_ranges;
            
    for(int i=0; i<landmark_positions.size(); i++){
        float error;
        error = landmark_positions[i] - pseudo_position;
        if(error > 0)
            pseudo_ranges.push_back(error);
    }
    sort(pseudo_ranges.begin(), pseudo_ranges.end());
    return pseudo_ranges;
}

float observation_model(vf landmark_positions, vf observations, vf pseudo_ranges, float distance_max, float observation_stdev){

    float distance_prob;

    return distance_prob;
}

float normal_pdf(float x, float mu, float std){

    return (1 / sqrt(2*M_PI*std)) * exp(-1/2 * pow((x-mu)/std,2));
}