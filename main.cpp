#include <iostream>
#define PI 3.14159265358979323846

// sinx(x) = x - (x^3 / 3!) + (x^5 / 5!) - (x^7 / 7!) + ... 
// 				+ (-1)^n + 1 * (x^(2n + 1)) / (2n + 1)! [n >= 0]
// cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) - (x^6 / 6!) + ... 
//				+ (-1)^n + 1 * (x^(2n)) / (2n)! [n >= 0]

int factorial(unsigned int num) {
	int result = 1;
	for (int i = num; i > 0; i--) {
		result *= i;
	}
	return result;
}

// if both floats are negative, it doesnt work
double fmod(double x, double y) {
	while (x >= 1 || x <= -1) {
		(x > 1) ? x -= y : x += y;
	}
	return x;
}

double power(double base, int exponent) {
	float result = 1.0;
	for (int i = 0; i < exponent; i++) result *= base;
	return result;
}

double sin(double radsX) {
	if (radsX < -0.5 * PI || radsX > 0.5 * PI) radsX = fmod(radsX, (0.5 * PI));
	double result = 0.0;
	double currentTerm;
	for (int i = 0; i < 10; i++) {
		currentTerm = (power(radsX, 2*i + 1)) / factorial(2*i + 1);
		(i % 2 == 0) ? result += currentTerm : result -= currentTerm;
	}
	return result;
}

double cos(double radsX) {
	if (radsX < 0) radsX *= -1; // cos(x) = cos(-x)
	if (radsX > PI) radsX = fmod(radsX, PI);
	double result = 0.0;
	double currentTerm;
	for (int i = 0; i < 10; i++) {
		currentTerm = (power(radsX, 2*i)) / factorial(2*i);
		(i % 2 == 0) ? result += currentTerm : result -= currentTerm;
	}
	return result;
}

int main(int argv, char** argc) {
	bool running = true;

	while (running) {
		
		std::cout << "Enter a number to factorialize: ";
		int numInputFac;
		std::cin >> numInputFac;
		
		std::cout << "Enter a number to sin() (rads): ";
		double numInputSin;
		std::cin >> numInputSin;
		
		std::cout << "Enter a number to cos() (rads): ";
		double numInputCos;
		std::cin >> numInputCos;
		
		std::cout << "Factorial of " << numInputFac << " is " << factorial(numInputFac) << std::endl;
		std::cout << "sin(" << numInputSin << ") is " << sin(numInputSin) << std::endl; 
		std::cout << "cos(" << numInputCos << ") is " << cos(numInputCos) << std::endl;
		
	}
	
	return 0;
}
