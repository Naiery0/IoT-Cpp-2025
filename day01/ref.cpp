//#include <iostream>
//using namespace std;
//
//// �ٸ� �Լ����� ����� ���������� ���� �ٲٴ� ��
//
//
//void chFunc(int* n) {
//	cout << "1" << endl;
//	*n = 20;
//}
//void chFunc(int& n) {		// ���۷��� (��������) ����
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
//	cout << "ȣ�� �� n: " << n << endl;
//	// chFunc(&n);
//	chFunc(n);
//	cout << "ȣ�� �� n: " << n << endl;
//
//	int num = 10;
//	int& ref = num; // ����� ���ÿ� �ʱ�ȭ�ؾ� ��
//	int* pn = &num;
//	printf("%d\n", ++num);
//	printf("%d\n", ++ref);
//	printf("%d\n", ++*pn);
//
//	if (&ref == &num) printf("����\n");
//
//	// ��� ���۷���
//	const int& ref2 = 10; // ����� ������ �����ϴ�. �ӽð�ü�� ������ �� �ִ� ���� ����
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
