#include <iostream> 
#include <string> 
using namespace std;

/*
When the variable is declared as static, the space will be allocated 
during the life cycle of the programs. Event the function if called multiple time
the static variable space is only allocated once, and the variable value in the previus
 call is passed through the next function call.
 This is useful for ohter application taht need to store the state of the previus functions
*/

void demo()
{
	static int count = 0;
	cout << count << "  " ;

	count++;
}

class Account
{
public:
	Account()
	{
		Initialize(12.0);
	};

	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void myRate(double);

private:
	string name;
	double amount;
	static double interestRate;
	static void Initialize(double value)
	{
		interestRate = value;
	}
};
Account acc;
//Need initialize the value first
double Account::interestRate = 0.0;

//double r = Account::rate();

class Apple
{
public:
	static int i;

	Apple() {
		cout << "In constructor" << endl;
	};

	~Apple()
	{
		cout << "Inside Destructor" << endl;
	}

	static void printHello()
	{
		cout << "Hello" << endl;
	}

};
// The static variable in the class should be explicitly initialized 
int Apple::i = 1;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		demo();
	}

	Apple a1;

	cout << a1.i;

	//invoke static member function
	Apple::printHello();

	/*
	Cycle of the program 
	1 - constructor
	2 - life time of the program =  cout << "end of main" << endl;
	3- destructor
	*/
	int x = 0;
	if (x == 0) {
		static Apple a;
	}

	cout << "end of main" << endl;

	/*
	To access the private member need initialize the member first out of the body
	*/
	Account a2;
	cout << acc.rate() << " this rate" << endl;
	cout << a2.rate() << "rate of acc_2" << endl;
	return 0;
}