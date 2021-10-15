#pragma once
#include <assert.h>
#include <iostream>

template<class T, int dim>
class Point
{
public:
	Point() = default;
	Point(T coord[dim])
	{
		for (int i = 0; i < dim; i++)
			_coords[i] = coord[i];
	}

	T& operator[](int index)
	{
		assert(index < dim&& index >= 0);
		return _coords[index];
	}

	T& operator[](int index) const
	{
		assert(index < dim&& index >= 0);
		return _coords[index];
	}

	
private:
	T _coords[dim];
};

template<class T, int dim>
std::ostream& operator << (std::ostream& os, const Point<T, dim>& pt)
{
	os << "(";
	for (int i = 0; i < dim - 1; i++)
		os << pt[i] << ", ";
	os << pt[dim - 1];
	os << ")";
}
