# Neural Network C++ Tutorial
This is a C++ implementation of the excellent neural network tutorial by Arthur Arnx

[Original Link](https://towardsdatascience.com/first-neural-network-for-beginners-explained-with-code-4cfd37e06eaf)

This simple 2 input perceptron trains a neuron to identify whether your input is the logical OR operation:

| A | B | Result |
| - |:-:| ------:|
| 1 | 1 |   1    |
| 1 | 0 |   1    |
| 0 | 1 |   1    |

The Perceptron class can have its constructor set to the Sigmoid or the Relu for different behaviors.
You can change the number of "steps" data to any number (originally 50), the original article stated that if you set this number incorrectly the network may overtrain.
I have tested the Perceptron with 6000 iterations and the weights appears to converge correctly to 1 1 and 0.