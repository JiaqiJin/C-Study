#include <iostream>
#include <vector>
using namespace std;

/*
decltype = type especifier, the compiler analyzes the expression to deternine it type
but does not evalueate the expression.

decltype return a reference type for a expression thata yield a object.
*/
int i = 42, * p = &i , &r = i; 
decltype(r + 0) b;

template<typename T>
auto multiply(T x, T y)->decltype(x * y)
{
	return x * y;
}

int main()
{
	std::cout << b;

	int nums[] = { 1,2,3,4 };
	vector<int> vec(nums, nums + 4);
	vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	using nullptr_t = decltype(nullptr);
	nullptr_t  nu = NULL;
	int* p = NULL;
	if (p == nu)
		cout << "NULL" << endl;

	typedef decltype(vec.begin()) vectype;

	for (vectype i = vec.begin(); i != vec.end(); i++) {
		cout << *i << " KAWAII";
	}
	cout << endl;

	struct
	{
		int d;
		double b;
	}anon_s;

	decltype(anon_s) as;

	as.b = 20.0;
	as.d = 10;

	cout <<"Multiply is  " <<multiply(as.b, as.b) << endl;

	return 0;

}
