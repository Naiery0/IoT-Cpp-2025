/* 
* �����Լ�: �ڽ� Ŭ�������� �������� ���� ��� ���� ��� �Լ��� ���ϸ�
* �θ�Ŭ������ ����Լ��� virtual Ű���带 ���
* virtual table�� ���������, dynamic binding���� ����
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
	void func1() override { cout << "D::func1()" << endl; } // override Ű����� ������ ���
	void func3() { cout << "D::func3()" << endl; }
	void func4() { cout << "D::func4()" << endl; }
};

// ���������ڸ� ������ �޼��带 ���� ���� �Լ���� ��.
// �� ���� ���� �Լ��� ������ Ŭ����
class Cinterface {
public:
	Cinterface() {
		cout << "CInterface constructor" << endl;
	}
	virtual void getData() const = 0; // ���� ���� �Լ�
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

	bptr->func1();	// baseŬ������ func1()�� �����Լ��� ����Ǿ� Derived Ŭ������ func1�� ȣ��
	bptr->func2();	// baseŬ������ func2()�� �����Լ��� ����Ǿ����� �������̵��� ���� ����
	bptr->func3();	// ������ Ÿ���� ȣ�� �Լ��� ����
	

	delete bptr;

	bptr = &b;
	bptr->func1();
	bptr->func2();
	bptr->func3();

	/*
		��ü �������� ���������� ���� Ŭ���� Ÿ���� �����ͷ� �Ļ� Ŭ������ ��ü�� ����Ű��,
		������ ���� Ŭ���� ����� ���ѵ�.
		�̶�, �������̵� �� �Ļ� Ŭ������ ����� ����ϱ� ���ؼ� ���� Ŭ������ ��� �Լ���
		���� �Լ��� ����� �ȴ�.
		�̰��� ������ ��, ������������ ���ε� ���� ���ϰ�, ��Ÿ�ӿ��� �����Ͱ� � ��ü��
		����Ű�� �ִ����� ���� ���ε� �� �Լ��� �����Ѵ�.
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
	* �߻��ڷ����� �̿��� ���� �Ҵ�� ��ü�� ������ ���� �޸� ���� �� 
	* ���� Ÿ���� �Ҹ��ڸ� ȣ��Ǿ� �޸� ���� �߻�.
	* ���� ���� Ŭ������ �Ҹ��ڸ� �������� ����� ��Ÿ���� �Ҹ��� ȣ���� ����
	*/
	return 0;
	}