#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Super {
public:
	Super() { cout << "������" << endl; }

	int n1, n2;
	int num;
	Super(int num) : num(num){cout << this->num << "������" << endl;}
	Super(const Super& other) : num(other.num) { cout << this << "���������" << endl; }
	~Super() { cout << num << "�Ҹ���" << endl; }
	void setData(int num) { this->num = num; }

	virtual void func() { cout << "Super::func()" << endl; }
	void func1() { cout << "Super::func1()" << endl; }
	void fx() { cout << "Super::fx()" << endl; }
};
Super fun(Super obj){
	cout << "fun()" << endl;
	return obj;
}
class Sub :public Super {
public:
	int n3, n4;

	void func() { cout << "Sub::func()" << endl; }
	void func2() { cout << "Sub::func2()" << endl; }
	void fx() { cout << "Sub::fx()" << endl; }
};
class Sub2 :public Sub {
public:
	int n5, n6;
};
int main() {
	// dynamic_cast
	Sub* sup;
	Sub2* sup2;
	Sub2 obj{};

	sup2 = dynamic_cast<Sub2*>(&obj);
	sup = dynamic_cast<Sub*>(sup2); // upcasting
	dynamic_cast<Super*>(sup2);// upcasting
	//-------------------------------------------------------
	Super* sp = new Super{};
	sp->func();
	sp->func1();
	sp->fx();
	delete sp;
	cout << "++++++++++++++++++++ Upcasting ++++++++++++++++++++" << endl;
	Super* sp2 = new Sub{};
	sp2->func();
	sp2->func1();
	sp2->fx();
	cout << "++++++++++++++++++++ Downcasting ++++++++++++++++++++" << endl;
	Sub* sp3 = dynamic_cast<Sub*>(sp2); // dynamic_cast�� �ٿ�ĳ���� �� �����Լ� ������ ������
	sp3->func();
	sp3->func1();
	sp3->func2();
	sp3->fx();
	delete sp2;
	//-------------------------------------------------------
	//const_cast
	const int num2 = 10;
	int* np = const_cast<int*>(&num2);
	*np += 1;
	cout << "num2: " << num2 << endl;
	//reinterpret_cast �����Ұ� 

	//---------------------------------------------------
	//Super& obj = Super{ 20 }; �ӽ� ��ü�� ������ ����� �� ����
	Super obj2 = Super{ 10 };
	obj2.setData(20);
	
	Super&& obj3 = Super{ 30 };
	obj3.setData(33);

	const Super& obj4 = Super{ 40 };
	// obj4.setData(44) ; // ��������� �ϹǷ� �� ���� ����
	Super obj5{ fun(obj2) };
	//------------------------------------------------------
	// ����Ʈ ������: unique_ptr - ��ü�� �����ֱ⸦ ��ü�� �ñ����ν� �޸� ���� �δ� ����
	unique_ptr<Super> uptr(new Super{});
	unique_ptr<Super> uptr2 = move(uptr);
	//---------------------------------------------
	//shared_ptr : ���� ī��Ʈ�� ���� ��ü�� �������� ����. ���۷��� ī���Ͱ� 0�� �Ǹ� �޸𸮰� �ڵ� ������
	//make_shared : ��ü�� ���� ī��Ʈ�� �ϳ��� �޸� ��Ͽ� ���� �Ҵ��Ŵ. shared_ptr�� �����ϴ� �Լ�
	shared_ptr<Super> sptr = make_shared<Super>();
	shared_ptr<Super> sptr2 = sptr; // sptr2, sptr�� ������ ��ü�� ����Ŵ
	sptr2->func();
	//---------------------------------------------
	//weak_ptr: ���۷��� ī���Ϳ� ������ ���� �ʴ� ����Ʈ ������
	weak_ptr<Super> wptr = sptr;
	
	shared_ptr<Super> wptr2 = wptr.lock(); // weak_ptr�� ��ȯ�� shared_ptr ��� ����
	
	return 0;
}

/* �⺻ Ŭ������ �����ϴ� lvalue�� �Ļ��� Ŭ������ ���� ������ ��ȯ
	��Ӱ��迡�� �����ϰ� ����ȯ�� �����Ѵ�. ��ĳ����
	�ٿ� ĳ���� ���� �������� ���ؼ� virtual �޼��尡 �� �־�� �Ѵ�
	*/

