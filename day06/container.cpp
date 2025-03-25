/*

container: ��ü�� �����ϰ� �����ϴ� �ڷᱸ��
	1. ������ �����̳� - ���������� ������ ����(����), vector, list, queue
	2. ���� �����̳� - ������ ��Ģ���� ���� set, multiset, map, meltimap
	3. �����̳� ����� - ���� 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v;
	vector<int> v1{ 10 };
	vector<int> v2(5);
	vector<int> v3{ 11, 22, 33, 44, 55, 66 };

	cout << "v size: " << v.size() << endl;
	cout << "v1 size: " << v1.size() << endl;
	cout << "v2 size: " << v2.size() << endl;
	cout << "v3 size: " << v3.size() << endl;

	for (int i = 0; i < v3.size(); i++) {
		printf("%d\n", v3[i]);
	}
	for (auto i : v3) {
		cout << i << endl;
	} // ������� for�� - index ��� �Ұ�

	// begin(), end()�� iterator(�ݺ���) Ÿ�� ��ȯ(������)
	cout << *v3.begin() << endl;
	cout << *(v3.end() - 1) << endl; // end�� ������ ��Ұ��� ������ ��ȯ�ϱ� ������ -1

	//-------------------------------------------------------------------
	vector<int> e;
	cout << "[v[i], v.size(), v.capacity()]" << endl;
	for (int i = 0; i <= 32; i++) {
		e.push_back(i + 1);
		cout << "[" << e[i] << ", " << e.size() << ", " << e.capacity() << "]" << endl;
	}

	vector<int> e2;
	e2.push_back(10); // ������ ���� �ڿ� 10�� �־��
	e2.push_back(11);
	e2.push_back(12);
	e2.push_back(13);
	e2.insert(e2.begin(), 1); // ù �ڸ��� 1 �־��
	e2.insert(find(e2.begin(), e2.end(), 13), 20); // ó������ ������ 13�� ã�Ƽ� �� �տ� 20�� �־��
	for (auto i : e2) {
		cout << i << endl;
	}

	e2.pop_back(); // �� �ڿ� �� ������
	for (auto i : e2) {
		cout << i << endl;
	}
	//--------------------------------------------------------------
	vector<int> c = { 10,20,30,40,50 };
	/* ��� 1 */
	for (auto i = 0; i < c.size(); i++) {
		cout << c[i] << endl;
		cout << c.at(i) << endl;
	}
	cout << endl << endl;
	/* ��� 2*/
	for (vector<int>::size_type i = 0; i < c.size(); i++) {
		cout << c[i] << endl;
	}
	cout << endl << endl;
	/* ��� 3 */
	vector<int>::iterator iter;
	for (iter = c.begin(); iter != c.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl << endl;
	/* ��� */
	for (auto i : v) {
		cout << i << endl;
	}
	//---------------------------------------------------------------------
	vector<string> t;
	t.push_back("tiger");
	t.push_back("lion");
	t.push_back("elephant");
	t.push_back("horse");

	cout << "t.front(): " << t.front() << endl; // �� ��
	cout << "t.back(): " << t.back() << endl; // �� ��
	cout << "t.capacity(): " << t.capacity() << endl;
	cout << endl << endl;

	vector<string>::iterator it;
	for (it = t.begin(); it != t.end(); it++) {
		cout << *it << endl;
	}
	cout << endl << endl;

	for (it = t.begin(); it != t.end(); it++) { // elephant ����
		if (*it == "elephant") {
			t.erase(it);
			break;
		}
	}
	for (it = t.begin(); it != t.end(); it++) {
		cout << *it << endl;
	}

	//------------------------------------------------------------------
	vector<int> r = { 10,20,30,40,50 };

	vector<int>::iterator ite;
	for (ite = r.begin(); ite != r.end(); ite++) {
		cout << *ite << endl;
	}

	for (auto ite = r.begin(); ite != r.end(); ite++) {
		cout << *ite << endl;
	}
	
	// ������
	vector<int>::reverse_iterator rit;
	for (rit = r.rbegin(); rit != r.rend(); rit++) { // rbegin()�� ������, rend()�� ó���� ����.
		cout << *rit << endl;
	}
	for (auto rit = r.rbegin(); rit != r.rend(); rit++) {
		cout << *rit << endl;
	}

	return 0;
}



