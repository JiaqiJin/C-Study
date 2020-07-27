/*
Inline functions reduce the function call overhead.
Small function, commonly-use functions, the time needed to make the function call
is often a lot more than the time to excute the function code.
*/

#include <iostream>
#include "inline.h"
using namespace std;

class Base
{
public:
	inline virtual void whoIam()
	{
		cout << "I am kawaii \n";
	}

};

class Derived : public Base
{
public:
	inline void whoIam()
	{
		cout << "I am kawaii desune \n";
	}
};

int main()
{
	Base b;
	b.whoIam();

	Base* ptr = new Derived();
	ptr->whoIam();

	delete ptr;

	A a;
	std::cout << a.MyFunction(1);

	return 0;
}