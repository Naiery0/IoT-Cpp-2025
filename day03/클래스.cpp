#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* name, int age):age(age){ // 얕은 복사 생성자
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Person(const Person& other) : age(other.age) { // 객체를 받기에 참조를 받는다. const & 형태 // 깊은 복사 생성자
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

// 변환생성자
class Hello {
private:
	int val;
public:
	//Hello(int val) : val(val) { // 변환생성자(매개변수가 하나)
	//}

	explicit Hello(int val) : val(val) { // explicit 추가
	}

	void printfHello() {
		printf("%d\n", val);
	}
};

// 이동생성자 -> r-value 참조를 파라미터로 갖는 생성자
class Human {
private:
	char* name;
	int age;
public:
	Human(){}

	Human(const char* name, int age) : age(age) {
		printf("일반 생성자\n");
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Human(const Human& other) : age(other.age) {
		printf("복사 생성자\n");
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}

	Human(Human&& other) noexcept : age(other.age){ // 이동생성자
		printf("이동 생성자\n");
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
int StaticClass::static_n = 10; // static 멤버변수 초기화는 클래스 외부에서 이뤄져야 한다
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
	//this->a = 0; static 함수 내에는 static 변수만 들어올 수 있다. 일반 멤버변수 접근 x                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}

int main() {
	Person p("홍길동", 30);
	p.printPerson();

	Person p2(p); // 복사생성자 사용
	p2.printPerson();

	Person p3 = p;
	p3.printPerson();

	//----------------------------
	//Hello h = 10; // 변환생성자에 explicit 추가로 인해 사용 불가
	Hello hl{ 10 };
	hl .printfHello();

	//----------------------------
	int n = 10;
	int& rn = n;	// l-value 참조
	const int& ra = 10;  // l-value 참조 (r-value도 받을 수 있는)

	int&& rrn = 10; // r-value 참조

	//cout << n << ", " << rn << ", " << ra << ", " << rrn << endl;
	Human h("길동이", 14);
	h.printData();

	Human h2(h);
	h2.printData();

	//이동 생성자 호출
	Human h3(move(h)); // std::move
	h3.printData();

	//----------------------------
	StaticClass s1, s2;
	s1.printData();
	s2.printData();
	
	s1.static_n = 1099;
	s1.n = 123;
	s1.printData();
	s2.printData(); // s1.static_n으로 변경한 값이 그대로 반영
	//------------------------
	Static2 st1(10), st2(20);
	st1.printData();
	st2.printData();

	st1.setStatic_a(50);
	st1.printData();
	st2.printData();

	return 0;
}

