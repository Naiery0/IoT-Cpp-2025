/* 
* 가상함수: 자식 클래스에서 재정의할 것을 약속 받은 멤버 함수를 말하며
* 부모클래스의 멤버함수에 virtual 키워드를 사용
* virtual table이 만들어지고, dynamic binding으로 동작
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Base {
public:
	virtual void func1() { cout << "B::func1()" << endl; }
	virtual void func2() { cout << "B::func2()" << endl; }
	void func3() { cout << "B::func3()" << endl; }
};

class Derived : public Base {
	void func1() override { cout << "D::func1()" << endl; } // override 키워드로 재정의 명시
	void func3() { cout << "D::func3()" << endl; }
	void func4() { cout << "D::func4()" << endl; }
};

// 순수지정자를 가지는 메서드를 순수 가상 함수라고 함.
// 이 순수 가상 함수를 가지는 클래스
class Cinterface {
public:
	Cinterface() {
		cout << "CInterface constructor" << endl;
	}
	virtual void getData() const = 0; // 순수 가상 함수
};
class CinSub : public Cinterface {
public:
	CinSub() { cout << "CinSub constructor" << endl;}
	void getData() const override {
		cout << "Pure Virtual Function()" << endl;
	}
};


class CTest {
private:
	int num;
public:
	  CTest(int num) : num(num)	{ cout << num << "CTest constructor" << endl; }
	       virtual void vfunc()	{ cout << "CTest virtual funtion()" << endl; }
					void func()	{ cout << "CTest function()" << endl; }
					   ~CTest() { cout << "CTest destructor" << endl; }

};
class CTestSub : public CTest {
private:
	int subN;
public:
	CTestSub(int an1, int an2) : CTest(an1), subN(an2) { 
		cout << subN << "CTestSub constructor" << endl; }
	void vfunc() override { cout << "CTestSub funtion() override" << endl; }
	~CTestSub() { cout << "CTestSub destructor" << endl; }
};

int main_2() {

	Base b;
	Derived d;
	Base* bptr = new Derived();

	bptr->func1();	// base클래스의 func1()은 가상함수로 선언되어 Derived 클래스의 func1로 호출
	bptr->func2();	// base클래스의 func2()은 가상함수로 선언되었지만 오버라이딩이 되지 않음
	bptr->func3();	// 포인터 타입의 호출 함수가 결정
	

	delete bptr;

	bptr = &b;
	bptr->func1();
	bptr->func2();
	bptr->func3();

	/*
		객체 포인터의 다형성으로 기초 클래스 타입의 포인터로 파생 클래스의 객체를 가리키면,
		접근은 기초 클래스 멤버로 제한됨.
		이때, 오버라이딩 된 파생 클래스의 멤버를 사용하기 위해서 기초 클래스의 멤버 함수를
		가상 함수로 만들면 된다.
		이것은 컴파일 시, 포인터형으로 바인딩 되지 못하고, 런타임에서 포인터가 어떤 객체를
		가리키고 있는지에 따라 바인딩 할 함수를 결정한다.
	*/

	//-----------------------------------------
	CinSub obj;
	obj.getData();

	//----------------------------------------
	CTest Cobj(1);
	CTestSub Cobj2(2, 22);
	Cobj.func();
	Cobj.vfunc();
	Cobj2.func();
	Cobj2.vfunc();

	CTest* cptr = new CTestSub(3, 33);

	delete cptr;
	/*
	* 추상자료형을 이용해 동적 할당된 객체를 참조할 때는 메모리 해제 시 
	* 참조 타입의 소멸자만 호출되어 메모리 누수 발생.
	* 따라서 상위 클래스의 소멸자를 가상으로 만들어 실타입의 소멸자 호출을 유도
	*/
	return 0;
	}