#pragma once

template<typename T>
class Vector
{
public:
	void push_back(T const&e)
	{
		data = e;
	}
	void clear()
	{
		data = nullptr;
	}
private:
	T data;
};