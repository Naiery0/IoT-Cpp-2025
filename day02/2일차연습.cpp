#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Human {
private:
	char* pname;
	int age;
	char* ptel;
public:
	Human(const char* name, int age, const char* tel) : pname(nullptr), age(age), ptel(nullptr) {
		pname = new char[strlen(name) + 1];
		strcpy(pname, name);
		ptel = new char[strlen(tel) + 1];
		strcpy(ptel, tel);
	}
	~Human() {
		delete[] pname;
		delete[] ptel;
	}
	void getData() {
		cout << "name: " << pname << endl;
		cout << "age: " << age << endl;
		cout << "tel: " << ptel << endl;
	}
};

int main() {

	Human h("ȫ�浿", 30, "010-1234-1234");
	h.getData();

	return 0;
}

