//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring> 
////~은 ~이다 - 사람은 경찰이다(x) 경찰은 사람이다(o)
////~은 ~을 갖고 있다 - 연필이 학생을 갖고 있다(x) 학생이 연필을 갖고 있다(o)
//using namespace std;
//
//
//class Human // 부모, 기초, 슈퍼, 베이스 클래스 
//{
//protected:
//	char name[20];
//	int age;
//public:
//	Human();
//	Human(const char*, int);
//	void getData();
//};
//class Student : public Human // 자식, 파생, 서브, 드라이버드 클래스
//{
//private:
//	int studentID;
//public:
//	Student();
//	Student(const char*, int, int);// 자식클래스 객체 생성 시 부모의 요소까지 다 입력받아야 함
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
//	cout << "학번: " << studentID << endl;
//}
//
//int main() {
//	Human h("홍길동", 25);
//	h.getData();
//
//	Student h2("임꺽정", 30, 202503);
//	h2.showStudent();
//}