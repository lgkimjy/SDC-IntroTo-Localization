## Introduction to Localization based on probabilistic robotics

## What is localization?
- Where the car is in a given map within an accuracy of 10cm or less.
- Onboard sensors are used to estimate transformation between measurements and a given map.
- In only Localization have to assume that we have a good map first, because without it, either won't work or won't work vey well.
- How can we know where we are with 10cm accuracy? → Have to use Localization technique.
- Technique of Locallizaton is just a infinite cycle between robot move(lose information) and sense(gain information) after the input of initial belief.

## What is Entropy?
- Measure of information(uncertainty) called "entropy"
- ENTROPY = Σ(−p×log(p))
- p is probability mass function
- entropy value will increase when robot is in difficult situation(hard initial information), and value will decrease in easier situation

## Law of Total probability
- .......

## Markov Assumption
- Quantity of data z(measurements) and u(control) are too big.
- based on chain rules, we can assume that x_{t-1} is optimized P
- This assumption is important because it will make the Bayes filter algorithm become a recursive structure

## Summarize
- Belief -> probability
- Sense -> product, followed by normalization
- Move -> convolution, addition

## Reference 
* udacity lecture
* probabilistic robotics lecture
* https://3months.tistory.com/436 -> about entropy