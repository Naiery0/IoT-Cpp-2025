#include <iostream>

class Human {
public: // �ܺο��� Ŭ������ �����ϱ� ����
	char name[20];
	int age;

	Human() { // ������

	}

	void showHuman() {
		printf("name: %s, age: %d", name, age);
	}
};

int main() {
	Human h = { "��ö��", 20 };
	h.showHuman();

	return 0;
}