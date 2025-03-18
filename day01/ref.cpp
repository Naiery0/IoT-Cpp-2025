//#include <iostream>
//using namespace std;
//
//// 다른 함수에서 선언된 지역변수의 값을 바꾸는 법
//
//
//void chFunc(int* n) {
//	cout << "1" << endl;
//	*n = 20;
//}
//void chFunc(int& n) {		// 레퍼런스 (참조변수) 선언
//	cout << "2" << endl;
//	n = 20;
//}
//
//int func(int &anum) {
//	anum++;
//	return anum;
//}
//int& func2(int& anum) {
//	anum++;
//	return anum;
//	//return ref++; // rvalue
//}
//
//int main() {
//
//	int n = 10;
//	cout << "호출 전 n: " << n << endl;
//	// chFunc(&n);
//	chFunc(n);
//	cout << "호출 후 n: " << n << endl;
//
//	int num = 10;
//	int& ref = num; // 선언과 동시에 초기화해야 함
//	int* pn = &num;
//	printf("%d\n", ++num);
//	printf("%d\n", ++ref);
//	printf("%d\n", ++*pn);
//
//	if (&ref == &num) printf("동일\n");
//
//	// 상수 레퍼런스
//	const int& ref2 = 10; // 상수도 참조가 가능하다. 임시객체를 저장할 수 있는 공간 생성
//
//	const int& res = func(num);
//	num++;
//	cout << res << ", " << num << endl;
//
//	int& res2 = func2(num);
//	num++;
//	cout << res2 << ", " << num << endl;
//
//
//	return 0;
//}
//
