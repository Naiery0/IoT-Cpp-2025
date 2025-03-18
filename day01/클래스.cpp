#include <iostream>

class Human {
public: // 외부에서 클래스에 접근하기 위함
	char name[20];
	int age;

	Human() { // 생성자

	}

	void showHuman() {
		printf("name: %s, age: %d", name, age);
	}
};

int main() {
	Human h = { "김철수", 20 };
	h.showHuman();

	return 0;
}