#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
public: // 외부에서 클래스에 접근하기 위함
	char name[20];
	int age;

	Human(const char* _name, int _age) {
		strcpy(name, _name);
		age = _age;
	}

	void showHuman() const {
		printf("name: %s, age: %d", name, age);
	}
};

int main() {
	Human h = { "김철수", 20 };
	h.showHuman();

	return 0;
}