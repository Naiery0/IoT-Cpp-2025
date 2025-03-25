/*

container: 객체를 저장하고 관리하는 자료구조
	1. 시퀀스 컨테이너 - 선형적으로 데이터 저장(순서), vector, list, queue
	2. 연관 컨테이너 - 일정한 규칙으로 저장 set, multiset, map, meltimap
	3. 컨테이너 어댑터 - 변형 

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
	} // 범위기반 for문 - index 사용 불가

	// begin(), end()는 iterator(반복자) 타입 반환(포인터)
	cout << *v3.begin() << endl;
	cout << *(v3.end() - 1) << endl; // end는 마지막 요소값의 다음을 반환하기 때문에 -1

	//-------------------------------------------------------------------
	vector<int> e;
	cout << "[v[i], v.size(), v.capacity()]" << endl;
	for (int i = 0; i <= 32; i++) {
		e.push_back(i + 1);
		cout << "[" << e[i] << ", " << e.size() << ", " << e.capacity() << "]" << endl;
	}

	vector<int> e2;
	e2.push_back(10); // 마지막 원소 뒤에 10을 넣어라
	e2.push_back(11);
	e2.push_back(12);
	e2.push_back(13);
	e2.insert(e2.begin(), 1); // 첫 자리에 1 넣어라
	e2.insert(find(e2.begin(), e2.end(), 13), 20); // 처음부터 끝까지 13을 찾아서 그 앞에 20을 넣어라
	for (auto i : e2) {
		cout << i << endl;
	}

	e2.pop_back(); // 맨 뒤에 거 꺼내라
	for (auto i : e2) {
		cout << i << endl;
	}
	//--------------------------------------------------------------
	vector<int> c = { 10,20,30,40,50 };
	/* 출력 1 */
	for (auto i = 0; i < c.size(); i++) {
		cout << c[i] << endl;
		cout << c.at(i) << endl;
	}
	cout << endl << endl;
	/* 출력 2*/
	for (vector<int>::size_type i = 0; i < c.size(); i++) {
		cout << c[i] << endl;
	}
	cout << endl << endl;
	/* 출력 3 */
	vector<int>::iterator iter;
	for (iter = c.begin(); iter != c.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl << endl;
	/* 출력 */
	for (auto i : v) {
		cout << i << endl;
	}
	//---------------------------------------------------------------------
	vector<string> t;
	t.push_back("tiger");
	t.push_back("lion");
	t.push_back("elephant");
	t.push_back("horse");

	cout << "t.front(): " << t.front() << endl; // 맨 앞
	cout << "t.back(): " << t.back() << endl; // 맨 뒤
	cout << "t.capacity(): " << t.capacity() << endl;
	cout << endl << endl;

	vector<string>::iterator it;
	for (it = t.begin(); it != t.end(); it++) {
		cout << *it << endl;
	}
	cout << endl << endl;

	for (it = t.begin(); it != t.end(); it++) { // elephant 삭제
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
	
	// 역방향
	vector<int>::reverse_iterator rit;
	for (rit = r.rbegin(); rit != r.rend(); rit++) { // rbegin()은 마지막, rend()는 처음의 이전.
		cout << *rit << endl;
	}
	for (auto rit = r.rbegin(); rit != r.rend(); rit++) {
		cout << *rit << endl;
	}

	return 0;
}



