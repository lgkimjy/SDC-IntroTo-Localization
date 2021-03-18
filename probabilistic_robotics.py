"""
 *  probabilistic_robotics.py
 *   Created on : 2021. 3. 18.
 *       Author : Junyoung Kim
"""

import numpy as np

# uniform distribution of over places
# p = [0.2, 0.2, 0.2, 0.2, 0.2]
p = [0, 1, 0, 0,0, 0]
world = ['green', 'red', 'red', 'green', 'green']
senses = ["miss", "hit", "hit", "miss", "miss"]
Z = 'red'
measurements = ['red', 'green']
# robot sesne probability
pHit = 0.6
pMiss = 0.2
# robot motion probability
pExact = 0.8
pOvershoot = 0.1
pUndershoot = 0.1

###### sense
def sense(p, Z):
    q = []
    for i in range(len(p)):
        if world[i] == Z:
            # p[i] = p[i] * pHit
            q.append(p[i] * pHit)
        else:
            # p[i] = p[i] * pMiss
            q.append(p[i] * pMiss)
    return q

###### probality normalization
def normalization(p):
    sum = 0
    normalize = []
    # sum = np.sum(p)
    for i in range(len(p)):
        sum = sum + p[i]
    for i in range(len(p)):
        normalize.append(p[i] / sum)
        p[i] = p[i] / sum
    return p # or normalize

###### equael to normalization() + sense()
def normalized_sense(p, Z):
    q=[]
    for i in range(len(p)):
        hit = (Z == world[i])
        q.append(p[i] * (hit * pHit + (1-hit) * pMiss))
    s = sum(q)
    for i in range(len(q)):
        q[i] = q[i] / s
    return q

###### robot motion / motion_model
def move(p, U):
    q = []
    for i in range(len(p)):
        q.append(p[(i-U)%len(p)])
    return q
###### robot motion with slip or some kinds of errors
def inaccurate_move(p, U):
    q = []
    for i in range(len(p)):
        q.append(pExact*p[(i-U)%len(p)] + pUndershoot*p[(i-U-1)%len(p)] + pOvershoot*p[(i-U+1)%len(p)])
    return q

for i in range(1000):
    p = inaccurate_move(p,1)

print(p)