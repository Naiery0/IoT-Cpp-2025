//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//	int x, y;
//	Point(int x = 0, int y = 0) : x(x), y(y){
//		printf("�Ϲݻ�����\n");
//	}
//
//	Point(const Point& other) : x(other.x), y(other.y) {
//		printf("���������\n");
//
//	}
//
//	void showPoint() {
//		printf("x: %d, y: %d\n", x, y);
//	}
//
//	Point add(const Point& np) {
//		printf("addȣ��\n");
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
//	//p3 = p.add(p2); //add: �� ���� ��ü�� ���ϴ� �޼���
//	Point p3 = p.add(p2); // �� �� �� ������� ��ü ���� Ƚ���� 1ȸ ����
//	p3.showPoint();
//
//	return 0;
//}
//
