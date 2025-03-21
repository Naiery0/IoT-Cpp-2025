//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//// 동적할당
//// char* name, int age, showHuman()을 갖는 Human 클래스
////  "홍명보"     30    man 객체 생성
//// man 객체를 복사하여 copyman 객체 생성
//
//class Human {
//private:
//	char* name;
//	int age;
//public:
//	Human() {
//
//	};
//	Human(const char* name, int age):age(age) {
//		this->name = new char[strlen(name) + 1];
//		strcpy(this->name, name);
//	}
//	Human(const Human& other) :age(other.age) {
//		this->name = new char[strlen(other.name) + 1];
//		strcpy(this->name, other.name);
//	}
//
//	~Human() {
//		delete[] name;
//	}
//	Human& operator=(const Human& other);
//	void showHuman() {
//		printf("이름 : %s \n나이 : %d \n------------------------\n", name, age);
//	}
//};
//Human& Human::operator=(const Human& other) {
//	if (this != &other) {
//		delete[] name;
//		this->name = new char[strlen(other.name) + 1];
//		strcpy(this->name, other.name);
//		this->age = other.age;
//	}
//	return *this;
//}
//int main() {
//	Human man("홍명보", 30);
//	man.showHuman();
//
//	Human copyman(man);
//	copyman.showHuman();
//
//	Human xman;
//	xman = copyman; // 연산자 오버로딩으로 에러없이 가능케함
//	xman.showHuman();
//
//	return 0;
//}
//
