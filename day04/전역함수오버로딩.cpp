//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//	int x, y;
//	Point(int ax, int ay) : x(ax), y(ay) {}
//	Point operator+(const Point& other) {
//		return Point(x + other.x, y + other.y);
//	}
//	Point operator+(int n) {
//		return Point(x + n, y + n);
//	}
//	void showPoint() {
//		printf("x : %d, y : %d\n", x, y);
//	}
//};
//
//inline Point operator+(int n, const Point& other) {
//	return Point(other.x + n, other.y + n);
//}
//
//class Complex {
//private:
//	double real, image;
//public:
//	Complex(double r = 0, double i = 0) :real(r), image(i) {
//	}
//	Complex add(const Complex& other) {
//		return Complex(real + other.real, image + other.image);
//	}
//	Complex operator+(const Complex& other) {
//		return Complex(real + other.real, image + other.image);
//	}
//	Complex operator*(int n) {
//		return Complex(real * n, image * n);
//	}
//	void showComplex() {
//		printf("%.1lf , %.1lf\n", real, image);
//	}
//	friend Complex operator*(int n, const Complex& other);
//	friend std::ostream& operator<<(std::ostream& out, const Complex& other);
//};
//Complex operator*(int n, const Complex& other) {
//	return Complex(other.real * n, other.image * n); // private 접근제어로 인한 액세스 불가 -> 클래스 내에 friend 함수 원형 선언 
//}
//// 출력 연산자 오버로딩
//std::ostream& operator<<(std::ostream& out, const Complex& other) {
//	 out << other.real << ", " << other.image;
//	 return out;
//}
//
//int main() {
//
//	Point a(2, 3);
//	Point b(20, 30);
//	Point c = a + b;
//	c.showPoint();
//
//	Point d = a + 100;
//	d.showPoint();
//
//	Point e = 200 + a; // 전역함수 호출
//	e.showPoint();
//	//--------------------------------------------------
//	Complex com1(1.1, 2.2);
//	com1.showComplex();
//	Complex com2(3.3, 4.4);
//	com2.showComplex();
//	Complex com3 = com1 + com2;
//	com3.showComplex();
//	Complex com4 = com1 * 100;
//	com4.showComplex();
//	Complex com5 = 100 * com1;
//	com5.showComplex();
//
//	cout << com5 << endl; // 출력 연산자<<는 기본적으로 객체를 출력할 수 없다 -> 출력 연산자 오버로딩
//	return 0;
//}
//
