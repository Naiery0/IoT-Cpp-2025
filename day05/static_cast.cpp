#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Base {
public:
	void func1() {
		cout << "Base::func1()" << endl;
	}
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f()" << endl; }
	void func1() { cout << "Derived::func1()" << endl; }
}; 
class Derived2 : public Derived {
public:
	void f() { cout << "Derived2::f()" << endl; }
	void func1() { cout << "Derived2::func1()" << endl; }
};



// 기본 자료형의 형변환으로 컴파일 타임에 타입을 변환
int main() {
	char ch;
	int i = 100;
	float f = 3.14;
	double d = 2.345;

	ch = static_cast<char>(i); // int -> char 변환
	cout << ch << endl;
	ch = (char)i;
	cout << ch << endl;

	d = static_cast<double>(f);
	cout << d << endl;

	i = static_cast<int>(d);
	cout << i << endl;

	cout << typeid(ch).name() << endl;
	cout << typeid(d).name() << endl;
	//------------------------------

	Base* bptr;
	Derived dobj;
	bptr = static_cast<Base*>(&dobj); // upcasting
	bptr->func1();

	Base bobj;
	Derived* dptr;
	dptr = static_cast<Derived*>(&bobj); // downcasting
	dptr->f();
	dptr->func1();

	Derived2* dptr2 = static_cast<Derived2*>(dptr);
	dptr2->f();
	dptr2->func1();
	return 0;
}


