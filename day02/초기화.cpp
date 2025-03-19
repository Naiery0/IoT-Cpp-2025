//#include <iostream>
//using namespace std;
//
//class BoxClass {
//private:
//	int m_width{ 0 };
//	int m_height{ 0 };
//	int m_length{ 0 };
//public:
//	BoxClass() { // 디폴트 생성자
//	}
//	BoxClass(int wi, int he, int le) : m_width(wi), m_height(he), m_length(le)/*이니셜라이져 리스트(콜론 초기화)*/ {
//	}
//	void setMem(int wi, int he, int le) {
//		m_width = wi;
//		m_height = he;
//		m_length = le;
//	}
//
//	int volume() {
//		return m_width * m_height * m_length;
//	}
//
//};
//
//class ConstClass { 
//private:
//	int m_value;
//	const int m_const_value; // 객체 생성 전에 초기화가 이뤄져야 함
//public:
//	//ConstClass(int val, int conVal) { m_value = val; m_const_value = conVal; /*상수값 변경으로 인해 에러발생*/ }
//	ConstClass(int val, int conVal):m_value(val), m_const_value(conVal) {}
//	void showValue() {
//		cout << "m_value: " << m_value << "\t m_const_value: " << m_const_value << endl;
//	}
//};
//
//class RefClass {
//private:
//	int& ref; // const 처럼 객채 생성 전 초기화 필요
//public:
//	RefClass(int& n) : ref(n) { }
//	void showValue(){
//		cout << "ref: " << ref << endl;
//	}
//};
//
//class Position {// 객체를 멤버로 가지는 경우
//private:
//	int m_x;
//	int m_y;
//public:
//	Position(int x, int y) : m_x(x), m_y(y) {}
//	void getData() {
//		cout << "m_x * m_y : " << m_x * m_y << endl;
//	}
//};
//class ObjClass { 
//private:
//	Position pos; // 객체 멤버변수
//public:
//	ObjClass(int x, int y) : pos(x,y)/*Position 생성자 호출*/ {}
//	void showValue() {
//		pos.getData();
//	}
//};
//
//
//int main() {
//
//	int num = 10; // C style    복사 초기화
//	int num2(20); // Cpp style  직접 초기화
//	int num3{ 300 }; // 중괄호 직접 초기화
//	int num4 = { 3000 }; // 중괄호 복사 초기화
//
//	cout << num << endl;
//	cout << num2 << endl;
//	cout << num3 << endl;
//	cout << num4 << endl;
//
//	int x1 = 3.14; // 되긴 되는데 3이 저장
//	int x2(3.14); // 되긴 되는데 3이 저장
//	//int x3 = { 3.14 }; // 에러발생 
//	//int x4{ 3.14 }; // 에러발생 
//
//	//----------------------------------
//	//BoxClass b;
//	BoxClass b = BoxClass();
//	b.setMem(1, 2, 3);
//	cout << "b.volume: " << b.volume() << endl;
//
//	//BoxClass b2(4, 5, 6);
//	//BoxClass b2 = { 4, 5, 6 };
//	BoxClass b2{ 4, 5, 6 };
//	cout << "b2.volume: " << b2.volume() << endl;
//
//	ConstClass obj(10, 20);
//	obj.showValue();
//
//	//----------------------------------
//	int r = 50;
//	RefClass refObj(r);
//	refObj.showValue();
//
//	//----------------------------------
//	ObjClass o(3, 6);
//	o.showValue();
//
//	
//	return 0;
//}
//
