#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* name, int age):age(age){ // ���� ���� ������
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Person(const Person& other) : age(other.age) { // ��ü�� �ޱ⿡ ������ �޴´�. const & ���� // ���� ���� ������
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}


	~Person() {
		delete[] name;
	}

	void printPerson() {
		cout << "name: " << name << " | " << "age: " << age << endl;
	}
};

// ��ȯ������
class Hello {
private:
	int val;
public:
	//Hello(int val) : val(val) { // ��ȯ������(�Ű������� �ϳ�)
	//}

	explicit Hello(int val) : val(val) { // explicit �߰�
	}

	void printfHello() {
		printf("%d\n", val);
	}
};

// �̵������� -> r-value ������ �Ķ���ͷ� ���� ������
class Human {
private:
	char* name;
	int age;
public:
	Human(){}

	Human(const char* name, int age) : age(age) {
		printf("�Ϲ� ������\n");
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Human(const Human& other) : age(other.age) {
		printf("���� ������\n");
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}

	Human(Human&& other) noexcept : age(other.age){ // �̵�������
		printf("�̵� ������\n");
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}

	~Human() { delete[] name; }

	void printData() {
		printf("name: %s, age: %d\n", name, age);
	}
};

class StaticClass {
public:
	int n;
	static int static_n;
	StaticClass();
	void printData();

};
int StaticClass::static_n = 10; // static ������� �ʱ�ȭ�� Ŭ���� �ܺο��� �̷����� �Ѵ�
StaticClass::StaticClass() {
	n = 20;
	//static_n = 10;
}
void StaticClass::printData() {
	cout << "Static_n: " << static_n << ", n: " << n << endl;
}

class Static2 {
private:
	static int static_a;
	int a;
public:
	Static2(int a);
	static void setStatic_a(int a);
	void printData();
};
int Static2::static_a = 100;
Static2::Static2(int a) {
	this->a = a;
}
void Static2::printData() {
	printf("static_a: %d, a: %d\n", static_a, a);
}
void Static2::setStatic_a(int a) {
	static_a = a;
	//this->a = 0; static �Լ� ������ static ������ ���� �� �ִ�. �Ϲ� ������� ���� x                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}

int main() {
	Person p("ȫ�浿", 30);
	p.printPerson();

	Person p2(p); // ��������� ���
	p2.printPerson();

	Person p3 = p;
	p3.printPerson();

	//----------------------------
	//Hello h = 10; // ��ȯ�����ڿ� explicit �߰��� ���� ��� �Ұ�
	Hello hl{ 10 };
	hl .printfHello();

	//----------------------------
	int n = 10;
	int& rn = n;	// l-value ����
	const int& ra = 10;  // l-value ���� (r-value�� ���� �� �ִ�)

	int&& rrn = 10; // r-value ����

	//cout << n << ", " << rn << ", " << ra << ", " << rrn << endl;
	Human h("�浿��", 14);
	h.printData();

	Human h2(h);
	h2.printData();

	//�̵� ������ ȣ��
	Human h3(move(h)); // std::move
	h3.printData();

	//----------------------------
	StaticClass s1, s2;
	s1.printData();
	s2.printData();
	
	s1.static_n = 1099;
	s1.n = 123;
	s1.printData();
	s2.printData(); // s1.static_n���� ������ ���� �״�� �ݿ�
	//------------------------
	Static2 st1(10), st2(20);
	st1.printData();
	st2.printData();

	st1.setStatic_a(50);
	st1.printData();
	st2.printData();

	return 0;
}

