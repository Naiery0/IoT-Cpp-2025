//#include <iostream>
//using namespace std;
//
//class BoxClass {
//private:
//	int m_width{ 0 };
//	int m_height{ 0 };
//	int m_length{ 0 };
//public:
//	BoxClass() { // ����Ʈ ������
//	}
//	BoxClass(int wi, int he, int le) : m_width(wi), m_height(he), m_length(le)/*�̴ϼȶ����� ����Ʈ(�ݷ� �ʱ�ȭ)*/ {
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
//	const int m_const_value; // ��ü ���� ���� �ʱ�ȭ�� �̷����� ��
//public:
//	//ConstClass(int val, int conVal) { m_value = val; m_const_value = conVal; /*����� �������� ���� �����߻�*/ }
//	ConstClass(int val, int conVal):m_value(val), m_const_value(conVal) {}
//	void showValue() {
//		cout << "m_value: " << m_value << "\t m_const_value: " << m_const_value << endl;
//	}
//};
//
//class RefClass {
//private:
//	int& ref; // const ó�� ��ä ���� �� �ʱ�ȭ �ʿ�
//public:
//	RefClass(int& n) : ref(n) { }
//	void showValue(){
//		cout << "ref: " << ref << endl;
//	}
//};
//
//class Position {// ��ü�� ����� ������ ���
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
//	Position pos; // ��ü �������
//public:
//	ObjClass(int x, int y) : pos(x,y)/*Position ������ ȣ��*/ {}
//	void showValue() {
//		pos.getData();
//	}
//};
//
//
//int main() {
//
//	int num = 10; // C style    ���� �ʱ�ȭ
//	int num2(20); // Cpp style  ���� �ʱ�ȭ
//	int num3{ 300 }; // �߰�ȣ ���� �ʱ�ȭ
//	int num4 = { 3000 }; // �߰�ȣ ���� �ʱ�ȭ
//
//	cout << num << endl;
//	cout << num2 << endl;
//	cout << num3 << endl;
//	cout << num4 << endl;
//
//	int x1 = 3.14; // �Ǳ� �Ǵµ� 3�� ����
//	int x2(3.14); // �Ǳ� �Ǵµ� 3�� ����
//	//int x3 = { 3.14 }; // �����߻� 
//	//int x4{ 3.14 }; // �����߻� 
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
