#include <iostream>

using namespace std;

void print(const char* p)
{
	while (*p) //no null pointer
		std::cout << p++ << std::endl;
}
void print2(int(&arr)[10])
{
	for (auto& ele : arr)
		cout << ele << endl;
}

void error_mesg(std::initializer_list<string> li)
{
	for (auto i = li.begin(); i != li.end(); i++)
	{
		cout << *i << endl;
	}
}

void test3()
{
	int* p = (int *)malloc(sizeof(int) * 10);
	*p = 10;
	cout << *p << endl;
	//000001 000001 000001 000001
	memset(p, 0, sizeof(int));
	cout << *p;
}

class Person {
public:
	int id;
	int age;
	int height;
	Person(int id, int age, int height) 
		:id(id),age(age),height(height){}
};



int main()
{
	int i = 42;
	const int* cp = &i;
	int a[10] = {1,1,1,1};

	//char p [10] = {'s','s'};
	//print(p);

	//print2(a);

	int *p = (int *)malloc(4);
	*p = 10;

	//cout << *p << "  "<<sizeof(p)<< endl ;

	free(p);

	//cout << *p << "  " << sizeof(p);

	/*char* p1 = (char*)malloc(2);
	p1[0] = 1;
	p1[1] = 10;
	cout << p1[0] << " " << p1[1] << endl;
	*p1 = 10;
	*(p1 + 1) = 1000;
	cout << p1[0] << " " << p1[1] << endl;
	*/

	//test3();

	Person person(10, 10, 10);
	std::cout << person.id << " " << person.age << "  " << person.height << endl;

	memset(&person, NULL, sizeof(Person));

	std::cout << person.id << " " << person.age << "  " << person.height << endl;

	return 0;
}