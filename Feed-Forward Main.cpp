#include "Feed-forward.h"
#include <iostream>

#define INPUT_LIMIT 5.0

int main()
{
	Neuron myNeuron = Neuron(2.0, 1.0);

	int		count = 0;
	bool	boolsRunning = true;
	double	customTarget = 0.0;
	double	input = 0.0;
	double	minDelta = 0.000000000001;

	std::cout << "Input : ";
	std::cin >> input;

	std::cout << "Input = " << input << "  Output = " << myNeuron.feedForward(input) << std::endl;

	std::cout << "Target : ";
	std::cin >> customTarget;


	while(boolsRunning)
	{

		std::cout.precision(12);

		std::cout << "Traning count " << count << std::endl;
		myNeuron.printOutput(input);
		//std::cout.fixed;
		//std::cout << "Input = " << input << "  Output = " << myNeuron.feedForward(input) << std::endl;
		myNeuron.propBackward(customTarget);
		myNeuron.printWeightBias();

		std::cout << std::endl;
		count++;

		if (fabs(customTarget - myNeuron.showOutput() ) < minDelta)
			boolsRunning = false;
	}

	getchar();
	getchar();

	return 0;
}