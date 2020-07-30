// complex.cpp
// Multiplying complex numbers

#include <iostream>	// contains the definition of cout, endl
#include <complex>	// contains the complex class definition

using namespace std; // cout, endl, complex are all part of this namespace

int main()
{
	using cmplxNum=complex<float>; //using aliasing for a more readable code
	auto num1 = cmplxNum{2.0, 2.0};  // use auto for type deduction
	auto num2 = cmplxNum{4.0, -2.0}; // use uniform initialisation syntax (curly braces)

	auto answer = num1 * num2; // type deduced for 'answer' is: complex<float>

	cout << "The answer is: " << answer << endl;
	cout << "Or in a more familiar form: " << answer.real() 
			<< " + " << answer.imag() << "j" 
			<< endl	<< endl;

	// answer++;  This line wont run, or the compiler  will result in an error, beacuse 
	//	      the operator '++' was not overloaded in complex class, that is, it is not 
	//	      declared as a memeber function 'operator'  in the complex class, hence still
	//	      belongs in the std namespace.
	return 0;
}

