//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//using namespace std;
//
//class A {
//private:
//	int n1;
//	int n2;
//	char* name;
//public:
//	A(int nb1, int nb2, const char* iname) : n1(nb1), n2(nb2), name(nullptr) {
//		//n1 = nb1;
//		//n2 = nb2;
//		//name = nullptr;
//		name = new char[strlen(iname) + 1]; // 동적할당
//		strcpy(name, iname);
//	}
//
//	~A() {
//		delete[]name;
//	}
//
//	void printData() {
//		cout << "n1: " << n1 << "\tn2: " << n2 << endl;
//		cout << "name: " << name << "\n" << endl;
//	}
//	void getData() const;
//	void setData(int nb1, int nb2, const char* iname) {
//		n1 = nb1;
//		n2 = nb2;
//
//		delete[]name;
//		//name = nullptr;
//		
//		name = new char[strlen(iname) + 1]; // 동적할당
//		strcpy(name, iname);
//	}
//}; 
//void A::getData() const {
//
//}
//
//int main() {
//	A obj(2, 3, "asdasd");
//	obj.printData();
//
//	obj.setData(3, 4, "afasdsadter");
//	obj.printData();
//
//	return 0;
//}// A의 소멸자 호출