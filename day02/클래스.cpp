//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//class Human { // 클래스 이름 첫글자는 무조건 대문자
//public: // 외부에서 클래스에 접근하기 위함
//	char name[20]; // 멤버변수 (속성)
//	int age;
//	Human(const char* _name, int _age) {
//		strcpy(name, _name);
//		age = _age;
//	}
//
//	void showHuman() const { // 멤버함수(기능), 메서드
//		printf("name: %s, age: %d", name, age);
//	}
//};
//
//int main() {
//	Human h = { "김철수", 20 }; // Human = 타입, h = 객체 이름 / h는 Human클래스의 인스턴스 
//	h.showHuman();
//
//	return 0;
//}