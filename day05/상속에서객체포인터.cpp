//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	void show() { printf("Base Class!!\n"); }
//};
//
//class Derived : public Base {	
//public:
//	void show() // 오버라이딩(재정의) 
//	{ printf("Derived Class!\n"); }
//};
//
//int main() {
//
//	Base* ptr = nullptr;
//	Derived* dptr = nullptr;
//
//	Derived obj; // 자식클래스 객체
//	dptr = &obj;
//	dptr->show(); 
//	
//	ptr = &obj; // UpCasting - 부모 타입 포인터로 자식 타입의 객체를 가리킴
//	ptr->show(); // 부모클래스의 show()가 실행됨
//	//ptr->Derived::show();
//	
//	return 0;
//}
//
