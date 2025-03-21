#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//int Add(int a, int b) {
//	return a + b;
//}
//float Add(double a, double b) {
//	return a + b;
//}

// ���� �ڷ����� ���ø� ���ڷ� �޾� �Լ� ���ο��� Ȱ��
// ������, ��Ȱ��


template <typename T, typename T2> // ���ø� ����(�Ϲ�ȭ) �Լ����ǿ� �и��� �� ����.
T Add(T a, T2 b) {
	cout << "T" << endl;
	return a + b;
}
template<> // ���ø� Ư��ȭ -> �Ϲ�ȭ �� Ư���� Ÿ���� ó��
int Add<int>(int a, int b) {
	cout << "<int>" << endl;
	return a + b;
}

template <typename Q>
class QTemplate {
private: 
	Q data;
public:
	QTemplate(Q d) { data = d; }
	Q getData() { return data; }
};
template <>  // Ŭ���� ���ø��� Ư��ȭ
class QTemplate<char> {
private:
	char data;
public:
	QTemplate(char d): data(d) {}
	char getData() { return data; }
};

// ���ø� �Ű�����
template <typename T, int sz>
class CTest {
private: 
	T ary[sz];
public:
	T& operator[](int idx) {
		if (idx < 0 || idx >= sz) {
			cout << "Error" << endl;
			exit(1);
		}
		return ary[idx];
	}
	void getData() {
		for (int i = 0; i < sz; i++) {
			cout << "T ary: " << ary[i] << endl;
		}
	}
};

int main() {

	cout << Add(1.1, 2.2) << endl;
	cout << Add(10, 20) << endl;
		
	cout << Add<double>(19.9, 20.2) << endl;
	cout << Add<int>(100, 10) << endl;

	cout << Add(10.5, 20) << endl; // ���ø� ���� typename T2 �߰�
	//------------------------------------------
	QTemplate<int> obj(100); // Ŭ���� ���ø��� ��ü ���� �� �ݵ�� typename�� ����ؾ� ��
	cout << obj.getData() << endl;

	QTemplate<char> obj2('a');
	cout << obj2.getData() << endl;
	//------------------------------------------
	CTest<int, 5> ct;
	ct.operator[](0) = 10;
	ct[1] = 20;
	ct[2] = 30;
	ct[3] = 40;
	ct[4] = 50;

	ct.getData();



	return 0;
}

