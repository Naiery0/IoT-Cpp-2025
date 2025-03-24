//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class MyClass {
//public:
//	void showMyClass() {
//		cout << "hello world" << endl;
//	}
//};
//
//class NumClass {
//public:
//	int value;
//	NumClass(int v=0):value(v){}
//	void showMyClass() {
//		cout << "val: " << value << endl;
//	}
//};
//
//int main() {
//	
//	MyClass obj;
//	MyClass* pt;
//	pt = &obj;
//
//	pt->showMyClass();
//
//	//-----------------------
//	// 객체 동적할당
//	MyClass* ptr = new MyClass();
//	ptr->showMyClass();
//
//	delete ptr;
//	//----------------------
//	NumClass* ptr2 = new NumClass{ 10 };
//	ptr2->showMyClass();
//	printf("val: %d\n", ptr2->value);
//	delete ptr2;
//	
//	NumClass obj2{};
//	NumClass* ptr3;
//	ptr3 = &obj2;
//	ptr3->showMyClass();
//	(*ptr3).showMyClass();
//
//	//-----------------------
//
//
//	return 0;
//}
//
