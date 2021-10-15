#include <iostream>
#include "Point.h"
#include "Vector.h"

float data[1024];

template<typename T> 
T getValue(int i )
{
	return static_cast<T>(data[i]);
}

template<typename T, int Size>
struct TestArray
{
	T data[Size];
};

int main()
{
	//Point<int, 3> point;
	//std::cout << point[0];
	float a = getValue<int>(0);
	std::cout << a;
	TestArray<int, 10> b;
	return 0;
}