#include <iostream>
#include <string>
#include <vector>
#include<sstream>
#include "DebugLiteralClass.h"
using namespace std;

class Person;
class Window_mgr;

class Sales_data
{
	//is a function given the same access as methods to private and protected data
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os,const Sales_data& item);
public:
	Sales_data() = default;
	Sales_data(const string &a,unsigned int b,double c)
		:bookNo(a),units_sold(b),revenue(c)
	{

	}
	explicit Sales_data(const std::string &s) : bookNo(s){}
	explicit Sales_data(std::istream&);
	//typedef std::string s;
	//explicit constructor can use only for direct initialization
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data& data);

	void printer();

	Sales_data operator +(const Sales_data& data)
	{
		return Sales_data(bookNo + data.bookNo, units_sold + data.units_sold, revenue + data.revenue);
	}

	inline Sales_data& set(int a)
	{
		this->units_sold = a;
		return *this;
	}

	void changeConsterMutable() const
	{
		//units_sold++; dont work
		mutabletester++;
		cout << mutabletester;
	}

private:

	void printerMyAtt();
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	mutable int mutabletester = 1;

	friend Person;
};

std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data::Sales_data(std::istream& is)
{
	read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data& data)
{
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
	return *this;
}

void Sales_data::printerMyAtt()
{
	cout << "my attribute is " << bookNo << endl;
}

void Sales_data::printer()
{
	cout << "my attribute is " << "bookNo "<< bookNo <<" units_sold " << units_sold <<" revenue "<< revenue <<endl;
}


class Person
{
public:
	Person() = default;

	void printSalesAtt();

};

void Person::printSalesAtt()
{
	Sales_data sd;
	sd.bookNo = "sada";
	sd.printerMyAtt();
}
/*
class Window_mgr
{

public:
	using ScreenIndex = std::vector<Screen>::size_type;

	inline void clear(ScreenIndex i)
	{
		Screen& s = screens[i];
		s.contents = string(s.height * s.width, ' ');
	}
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
*/
class Screen {
	//friend void Window_mgr::clear(ScreenIndex);

public:
	using pos = std::string::size_type;
	//typedef std::string::size_type ps;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') { } // 2
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) { } // 3

	inline Screen& move(pos r, pos c);
	inline Screen& set(char c);
	inline Screen& set(pos r, pos c, char ch);

	const Screen& dispaly(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}

	Screen& display(std::ostream& os) 
	{ 
		do_display(os); 
		return *this; 
	}

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r * width + c]; }

private:
	void do_display(std::ostream& os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	friend Window_mgr;
};

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}
//need initialice first
double Account::interestRate = 0.0;

int main()
{

	/*Person p;
	p.printSalesAtt();

	Sales_data data1("ddd", 10, 2.2);
	Sales_data data2("aaa", 10, 5.2);
	Sales_data data3;
	data3 = data1 + data2;
	data3.set(100);
	data3.printer();
	data3.changeConsterMutable();*/

	/*Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').dispaly(std::cout);
	std::cout << "\n";
	myScreen.display(std::cout);
	std::cout << "\n";
	*/
	Account as;
	as.rate(10.0);
	double r = Account::rate();
	cout << r << endl;

	Sales_data *a = new Sales_data("ads", 1, 1.0);
	a->printer();
	
	Sales_data item1(cin);//-> input element
	a->combine(item1);
	a->printer();
	
	//cannot use an explicit constructor with this form initialization
	//Sales_data data = { "asda" };

	return 0;
}