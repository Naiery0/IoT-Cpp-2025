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
//	void show() // �������̵�(������) 
//	{ printf("Derived Class!\n"); }
//};
//
//int main() {
//
//	Base* ptr = nullptr;
//	Derived* dptr = nullptr;
//
//	Derived obj; // �ڽ�Ŭ���� ��ü
//	dptr = &obj;
//	dptr->show(); 
//	
//	ptr = &obj; // UpCasting - �θ� Ÿ�� �����ͷ� �ڽ� Ÿ���� ��ü�� ����Ŵ
//	ptr->show(); // �θ�Ŭ������ show()�� �����
//	//ptr->Derived::show();
//	
//	return 0;
//}
//
