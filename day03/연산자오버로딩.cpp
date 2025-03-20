//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//	int x, y;
//	Point(int x = 0, int y = 0) : x(x), y(y){
//		printf("일반생성자\n");
//	}
//
//	Point(const Point& other) : x(other.x), y(other.y) {
//		printf("복사생성자\n");
//
//	}
//
//	void showPoint() {
//		printf("x: %d, y: %d\n", x, y);
//	}
//
//	Point add(const Point& np) {
//		printf("add호출\n");
//		return Point(x + np.x, y + np.y);
//	}
//};
//
//int main() {
//
//	Point p(10, 20);
//	p.showPoint();
//	Point p2(30, 40);
//	p2.showPoint();
//	//Point p3;
//	//p3 = p.add(p2); //add: 두 개의 객체를 더하는 메서드
//	Point p3 = p.add(p2); // 위 두 줄 방법보다 객체 생성 횟수가 1회 줄음
//	p3.showPoint();
//
//	return 0;
//}
//
