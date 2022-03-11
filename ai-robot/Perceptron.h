#pragma once

#include <cmath>

class Perceptron
{
private:
	float weights[2];
	float sigmoid(float x);


public:
	Perceptron();
	Perceptron(float w1, float w2);
	float Calculate(float i1, float i2);
};

float Perceptron::sigmoid(float x)
{
	return 1 / (1 + std::exp(-x));
}

Perceptron::Perceptron()
{

}

Perceptron::Perceptron(float w1, float w2)
{
	weights[0] = w1;
	weights[1] = w2;
}

float Perceptron::Calculate(float i1, float i2)
{
	return this->sigmoid((i1 * weights[0]) + (i2 * weights[1]));
}





