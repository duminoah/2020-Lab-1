// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6};
	myScreen.forward();
	myScreen.set('*');
	myScreen.down();
	myScreen.set('*');
	myScreen.move(3,3);
	myScreen.set("---");

	myScreen.display();
	cout << endl;

	myScreen.reSize(16,16);
	myScreen.display();
	myScreen.clear(' ');

	myScreen.move(7,7);
	myScreen.set("BIG");
	myScreen.move(8,5);
	myScreen.set("SCREEN");
	myScreen.display();

    //Exercise 4.1
	//Making the screen to display my initial 'F'
	//enum class Direction{HOME, FORWARD, BACK, UP, DOWN, END};
	//Direction dir = Direction::BACK;
	myScreen.clear(' ');
	myScreen.home();
	myScreen.set("******");
	myScreen.home();
	myScreen.move(Screen::Direction::DOWN);
	//myScreen.down();
	myScreen.set("*");
	myScreen.down();
	myScreen.set("*");
	myScreen.down();
	myScreen.set("*");
	myScreen.down();
	myScreen.set("****");
	myScreen.move(6,1);
	myScreen.set("*");
	myScreen.down();
	myScreen.set("*");
	myScreen.down();
	myScreen.set("*");
	myScreen.down();
	myScreen.display();

    /*Exercise 4.2
        1. The const keyword is being used at the end of member functions - string::size_type height() const { return height_; }
           This specifies that the member function height cannot modify any member variable of the class type screen.
        2. The const keyword is being used in member function definitions to specify formal parameters as constant reference
           parameters - void set( const string& s );
           This ensures that in a call to the function, the formal parameter receives the address of the actual parameter, but the
           formal parameter cannot modify the value of the actual parameter.
        3. The const keyword is being used to declare member variables as constant variables - const string::size_type TOP_LEFT = 0;
           This specifies that the value of the constant variable cannot be modified at any point in the execution of the program.

        The string class used at member function (string::size_type) allows for efficient use of memory by holding the size of
        a string nomatter how big it is. The size of the variable is not fixed, it is dictated by the string itself.
    */

	return 0;
}

