//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//using namespace std;
//
//class A {
//private:
//	int n1;
//	int n2;
//public:
//	A(int nb1, int nb2) { // 생성자 객체 생성 시 입력을 두 개 받음. - 클래스 이름과 같아야 함.
//		n1 = nb1;
//		n2 = nb2;
//	}
//	A() { // 생성자도 함수라서 오버로딩 가능
//		printf("생성자도 오버로딩 가능함\n");
//	}
//
//	~A(){} // 소멸자 ( ~클래스이름)
//
//	void printData() {
//		cout << "난 a의 인스턴스이다.\n";
//		cout << "n1: " << n1 << "\tn2: " << n2 << endl;
//	}
//};
//
//int main() {
//	A obj;
//	A obj2(100, 200);
//	obj2.printData();
//	
//
//	return 0;
//}// A의 소멸자 호출