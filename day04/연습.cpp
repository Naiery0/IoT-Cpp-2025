//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//// �����Ҵ�
//// char* name, int age, showHuman()�� ���� Human Ŭ����
////  "ȫ��"     30    man ��ü ����
//// man ��ü�� �����Ͽ� copyman ��ü ����
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
//		printf("�̸� : %s \n���� : %d \n------------------------\n", name, age);
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
//	Human man("ȫ��", 30);
//	man.showHuman();
//
//	Human copyman(man);
//	copyman.showHuman();
//
//	Human xman;
//	xman = copyman; // ������ �����ε����� �������� ��������
//	xman.showHuman();
//
//	return 0;
//}
//
