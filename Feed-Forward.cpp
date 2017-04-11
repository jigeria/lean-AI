#include "Feed-forward.h"
#include <iostream>

Neuron ::Neuron (double weight, double bias)
{
	weight_ = weight;
	bias_ = bias;
}

double Neuron::feedForward(const double& _input)
{
	//output y = f(/igma)
	//sigma = weight * input + bias
	//if multipul inputs...
	//sigma = weight1 * input1 + weight2 * input2 +... + bias

	input_ = _input;
	const double sigma = weight_ * _input + bias_;

	output_ = getAct(sigma);

	return output_;
}

void Neuron::propBackward(const double& target)
{
	const double rate = 0.1; // leaning rate

	const double grad = (output_ - target) * getActGrad(output_);

	weight_ -= rate * grad * input_;
	bias_ -= rate * grad * 1.0;	

}

double Neuron::getActGrad(const double& x)
{
	return 1.0;
}
double Neuron::getAct(const double& x)
{
	return x;
}

double Neuron::showOutput()
{
	return output_;
}

void Neuron::printWeightBias()
{
	std::cout << "Weight = " << weight_ << " Bias = " << bias_ << std::endl;
}

void Neuron::printOutput(double input)
{
	std::cout << "Input = " << input << "  Output = " << feedForward(input)<< std::endl;
}


