//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Myclass {
//private:
//	int m_a, m_b;
//	const char* m_name;
//
//public:
//	Myclass(int a = 0, int b = 0, const char* name = nullptr) :m_a(a), m_b(b), m_name(name){
//		//m_name = new char[strlen(name) + 1];
//		//strcpy(m_name, name);
//	}
//	//Myclass(const Myclass& other): m_a(other.m_a), m_b(other.m_b){
//	//	m_name = new char[strlen(other.m_name) + 1];
//	//	strcpy(m_name, other.m_name);
//	//}
//
//
//	void showMyClass() {
//		cout << m_a << ", " << m_b << ", " << m_name << endl;
//	}
//};
//
//class Point {
//public:
//	int x, y;
//	Point(int x = 0, int y = 0) : x(x), y(y){
//		printf("생성자호출\n");
//	}
//
//	Point(const Point& other) : x(other.x), y(other.y) {
//		printf("복사 생성자호출\n");
//	}
//
//	void showPoint() {
//		printf("x: %d, y: %d\n", x, y);
//	}
//
//	//Point add(const Point& np) {
//	//	printf("add\n");
//	//	return Point(x + np.x, y + np.y); // 객체 리턴
//	//}
//
//	Point& add(const Point& np) {
//		printf("add\n");
//		x = np.x;
//		y = np.y;
//		return *this; // 참조 리턴
//	}
//};
//
//class Oper {
//private:
//	int val;
//public:
//	Oper(int n) : val(n) {}
//	Oper operator+(const Oper& other) { // 연산자 오버로딩
//		printf("+ overoading\n");
//		return Oper(val + other.val);
//	}
//	void showOper() {
//		printf("val : %d\n", val);
//	}
//};
//
//class Oper2 {
//private:
//	int x, y;
//public:
//	Oper2(int x, int y):x(x), y(y){}
//	Oper2 operator+(const Oper2& other) {
//		printf("+ overoading\n");
//		return Oper2(x + other.x, y + other.y);
//	}
//	Oper2 operator+(int x) {
//		printf("+ overoading\n");
//		return Oper2(this->x + x, this->y + x);
//	}
//	void showMyClass() {
//		printf("x : %d, y : %d\n", x, y);
//	}
//	Oper2 add(const Oper2& other) {
//		int vx = x + other.x;
//		int vy = y + other.y;
//		return Oper2(vx, vy);
//	}
//	
//};
//
//class Money {
//private:
//	int money;
//public:
//	Money(int m = 0) : money(m){}
//	// 단항연산자 오버로딩
//	int operator()() {
//		return money;
//	}
//	void operator()(int m) {
//		money += m;
//	}
//};
//
//
//int main() {
//
//	Myclass m{ 1, 2, "길동" };
//	m.showMyClass();
//
//	Myclass m2;
//
//	m2 = m;
//	m2.showMyClass();
////-----------------------------------------
//	Point p(10, 20);
//	p.showPoint();
//	Point p2(30, 40);
//	p2.showPoint();
//	//Point p3;
//	//p3 = p.add(p2); //add: 
//	Point p3 = p.add(p2); 
//	p3.showPoint();
//
////-----------------------------------------
//	Oper o(10); // 초기값을 갖는 객체 생성
//	o.showOper();
//
//	Oper o2(o); // o를 복사하여 객체 생성
//	o2.showOper();
//
//	Oper o3 = o2; // o를 복사하여 객체 생성
//	o3.showOper();
//
//	Oper o4 = o + o2; // 객체를 더한 결과를 가지고 객체 생성
//	//Oper o4 = o.operator+(o2);
//	o4.showOper();
////--------------------------------------
//	Oper2 oo(10, 20);
//	Oper2 oo2(20, 30);
//	Oper2 oo3 = oo.add(oo2);
//	oo3.showMyClass();
//
//	Oper2 oo4 = oo.operator+(oo3);
//	oo4.showMyClass();
//
//	Oper2 oo5 = oo4 + 100;
//	oo5.showMyClass();
//
////--------------------------------------
//	Money mo;
//	cout << "money:" << mo.operator()() << endl;
//	mo(1000);
//	cout << "money:" << mo.operator()() << endl;
//	mo.operator()(1000);
//	cout << "money:" << mo.operator()() << endl;
//
//	// 오버로딩 할 수 없는 연산자:
//	// ::, ., sizeof
//	return 0;
//}
//
