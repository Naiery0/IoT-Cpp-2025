//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring> 
////~�� ~�̴� - ����� �����̴�(x) ������ ����̴�(o)
////~�� ~�� ���� �ִ� - ������ �л��� ���� �ִ�(x) �л��� ������ ���� �ִ�(o)
//using namespace std;
//
//
//class Human // �θ�, ����, ����, ���̽� Ŭ���� 
//{
//protected:
//	char name[20];
//	int age;
//public:
//	Human();
//	Human(const char*, int);
//	void getData();
//};
//class Student : public Human // �ڽ�, �Ļ�, ����, ����̹��� Ŭ����
//{
//private:
//	int studentID;
//public:
//	Student();
//	Student(const char*, int, int);// �ڽ�Ŭ���� ��ü ���� �� �θ��� ��ұ��� �� �Է¹޾ƾ� ��
//	void showStudent();
//};
//Human::Human(const char* name, int age) {
//	strcpy(this->name, name);
//	this->age = age;
//}
//void Human::getData() {
//	cout << "name: " << name << endl;
//	cout << "age: " << age << endl;
//}
//Student::Student(const char* name, int age, int studentID) : Human(name, age) {
//	//strcpy(this->name, name);
//	//Human::age = age;
//	this->studentID = studentID;
//
//}
//void Student::showStudent() {
//	getData();
//	cout << "�й�: " << studentID << endl;
//}
//
//int main() {
//	Human h("ȫ�浿", 25);
//	h.getData();
//
//	Student h2("�Ӳ���", 30, 202503);
//	h2.showStudent();
//}