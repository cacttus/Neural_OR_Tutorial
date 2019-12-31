/**
* 
*   Simple Perceptron Test
*   Tutorial: https://towardsdatascience.com/first-neural-network-for-beginners-explained-with-code-4cfd37e06eaf
*   12/29/2019
*   
*   A simple C++ example of a neural network that trains a logical OR function
*   Input: 10, 01, 11, 00 
*   Output: 1,  1,  1,  0
*
*/
#include <iostream>
#include <functional>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <conio.h>
#define WEIGHT_COUNT 3
double weights[WEIGHT_COUNT];
double learn_rate = 1;
double bias = 1;

//Simple Perceptron
class Perceptron {
    std::function<double(double)> activator;
public:
    Perceptron(std::function<double(double)> activator) {
        this->activator = activator;
    }
    virtual ~Perceptron() {
    }
    double test(double input1, double input2) {
        //Linear combination of weights and values.
        double outputP = input1 * weights[0] + input2 * weights[1] + bias * weights[2];
        outputP = activator(outputP);
        return outputP;
    }
    void exec(double input1, double input2, double output) {
        double outputP = test(input1, input2);
        double error = output - outputP;
        weights[0] += error * input1 * learn_rate;
        weights[1] += error * input2 * learn_rate;
        weights[2] += error * bias * learn_rate;
    }
};

int main(int argc, char* argv[]) {
    //Wights
    double initialvalue = (double)rand() / (double)RAND_MAX;
    memset(weights, initialvalue, WEIGHT_COUNT * sizeof(float));

    //Activators
    //https://en.wikipedia.org/wiki/Rectifier_(neural_networks)
    std::function<double(double)> relu = [](double x) {
        /*x=max(0,x)*/
        if (x > 0) {
            x = 1;
        }
        else {
            x = 0;
        }
        return x;
    };
    std::function<double(double)> sigmoid /*softplus?*/ = [](double x) {
        x = 1 / (1 + exp(-x));
        return x;
    };

    //Training
    Perceptron p(sigmoid);
    int steps = 600000;
    for (int i = 0; i < steps; ++i) {
        p.exec(1, 1, 1);
        p.exec(1, 0, 1);
        p.exec(0, 1, 1);
        p.exec(0, 0, 0);
    }

    //Output
    std::cout << "Trained " << steps << " times.  Weights:";
    std::string app = "";
    for (int i = 0; i < WEIGHT_COUNT; ++i) {
        std::cout << app << weights[i];
        app = ",";
    }
    std::cout<<std::endl;

    //Test!
    while (true) {
        double x, y;
        std::cout << "enter value for x:";
        std::cin >> x;
        std::cout << "enter value for y:";
        std::cin >> y;
        std::cout << "result:" << p.test(x, y) << std::endl;
        std::cout << "Press escape to exit, or enter to try again." << std::endl;
        int c = _getch();
        if (c == 27) {
            break;
        }
    }

    return 0;
}