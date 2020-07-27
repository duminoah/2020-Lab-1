// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6};
	myScreen.display();
	cout << endl;

	myScreen.reSize(16,16);
	myScreen.clear(' ');
	myScreen.drawSquare(5,5,4,4);
	myScreen.display();

    //Exercise 4.1
	//Making the screen to display my initial 'F'
	//enum class Direction{HOME, FORWARD, BACK, UP, DOWN, END};
	//Direction dir = Direction::BACK;
	/*myScreen.clear(' ');
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
	myScreen.display();*/

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

    /*Exercise 4.5
        Yes, I would need access to the internal representation of the screen object in-order to implement the function to draw
        a square because it involves new member functions which initially do not form part of the class object.
        Yes, a function like this forms part of the responsibilities of a screen object for a client to be able to highlight
        a part of the screen which they may intend to use for typing information or clearly show a piece of writing on the screen
    */

    /*Exercise 4.6
        A more intuitive way of representing the screen class would perhaps be to use an array of characters (charater arrays).
        Arrays are much easier for accesibility and navigation
        It is important to maintain the class interface because in doing so, time and resources are saved by avoiding to re-think
        and re-implement it using a different interface.
        We can change the implementation in-order to come up with a more efficient way that has less running time and may use less
        memory
    */
	return 0;
}

