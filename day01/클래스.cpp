#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
public: // �ܺο��� Ŭ������ �����ϱ� ����
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
	Human h = { "��ö��", 20 };
	h.showHuman();

	return 0;
}