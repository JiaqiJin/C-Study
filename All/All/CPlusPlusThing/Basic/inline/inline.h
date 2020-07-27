#pragma once

class A
{
public:
	int MyFunction(int x, int y);

	int MyFunction(int x);
};

inline int A::MyFunction(int x, int y)
{
	return x + y;
}

inline int A::MyFunction(int x)
{
	return x;
}