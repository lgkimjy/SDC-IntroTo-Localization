from math import *
import matplotlib.pyplot as plt
import numpy as np

sample_size = 1000
alpha1 = 0.1
alpha2 = 0.1
alpha3 = 0.1
alpha4 = 0.1
motion_param = [alpha1, alpha2, alpha3, alpha4]

def Gaussian(mu, sigma, x):
    return exp(- ((mu - x) ** 2) / (sigma ** 2) / 2.0) / sqrt(2.0 * pi * (sigma ** 2))

def normal_dist(a, b):
    return exp((a ** 2 / b **2 ) / -2.0) / sqrt(2.0 * pi * (a ** 2))

def motion_model(xt, ut, xt_1):

    delta_x = xt[0] - xt_1[0]
    delta_y = xt[1] - xt_1[1]
    delta_th = xt[2] - xt_1[2]

    delta_x_prime = 
    delta_y_prime = 
    delta_th_prime = 

    rot1 = atan2(delta_y, delta_x) - xt_1[2]     # ground truth
    trans = sqrt(delta_x ** 2 + delta_y ** 2)    # ground truth
    rot2 = xt[2] - xt_1[2] - rot1                # ground truth

    rot1_bar = atan2(y, x)
    trans_bar = sqrt(x)
    rot2_bar =  -  - rot1_bar

    p_1 = normal_dist(rot1 - rot1_bar, motion_param[0]*rot1_bar**2 + motion_param[1]*trans_bar**2)
    p_2 = normal_dist(trans - trans_bar, motion_param[2]*trans_bar**2+motion_param[3]*rot1_bar**2+motion_param[3]*rot2_bar**2)
    p_3 = normal_dist(rot2 - rot2_bar, motion_param[0]*rot2_bar**2+motion_param[1]*trans_bar**2)

    return x, y, p_1*p_2*p_3

if __name__=="__main__":

    xt = [1, 1 , pi/4]
    xt_1 = [2, 2, pi/5]
    ut = []

    for i in range(sample_size):
        x, y, p = motion_model(xt, xt, xt)