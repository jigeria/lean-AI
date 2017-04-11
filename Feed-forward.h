#pragma once

class Neuron
{
private:
	double weight_;
	double bias_;

	double output_;
	double input_;

public:
	Neuron(double weight , double bias);
	
	double feedForward(const double& input);
	double getAct(const double& x);
	double getActGrad(const double& x);
	double showOutput();
	
	void printWeightBias();
	void propBackward(const double& target);
	void printOutput(double);
};