#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//int Add(int a, int b) {
//	return a + b;
//}
//float Add(double a, double b) {
//	return a + b;
//}

// 여러 자료형을 템플릿 인자로 받아 함수 내부에서 활용
// 다형성, 재활용


template <typename T, typename T2> // 템플릿 선언(일반화) 함수정의와 분리될 수 없음.
T Add(T a, T2 b) {
	cout << "T" << endl;
	return a + b;
}
template<> // 템플릿 특수화 -> 일반화 중 특별한 타입을 처리
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
template <>  // 클래스 템플릿의 특수화
class QTemplate<char> {
private:
	char data;
public:
	QTemplate(char d): data(d) {}
	char getData() { return data; }
};

// 템플릿 매개변수
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

	cout << Add(10.5, 20) << endl; // 템플릿 선언에 typename T2 추가
	//------------------------------------------
	QTemplate<int> obj(100); // 클래스 템플릿은 객체 생성 시 반드시 typename을 명시해야 함
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

