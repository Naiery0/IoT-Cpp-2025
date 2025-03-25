#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Super {
public:
	Super() { cout << "생성자" << endl; }

	int n1, n2;
	int num;
	Super(int num) : num(num){cout << this->num << "생성자" << endl;}
	Super(const Super& other) : num(other.num) { cout << this << "복사생성자" << endl; }
	~Super() { cout << num << "소멸자" << endl; }
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
	Sub* sp3 = dynamic_cast<Sub*>(sp2); // dynamic_cast로 다운캐스팅 시 가상함수 없으면 에러뜸
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
	//reinterpret_cast 복습할것 

	//---------------------------------------------------
	//Super& obj = Super{ 20 }; 임시 객체는 참조를 사용할 수 없다
	Super obj2 = Super{ 10 };
	obj2.setData(20);
	
	Super&& obj3 = Super{ 30 };
	obj3.setData(33);

	const Super& obj4 = Super{ 40 };
	// obj4.setData(44) ; // 상수참조를 하므로 값 변경 불허
	Super obj5{ fun(obj2) };
	//------------------------------------------------------
	// 스마트 포인터: unique_ptr - 객체의 생명주기를 객체에 맡김으로써 메모리 관리 부담 감소
	unique_ptr<Super> uptr(new Super{});
	unique_ptr<Super> uptr2 = move(uptr);
	//---------------------------------------------
	//shared_ptr : 참조 카운트를 통해 객체의 소유권을 공유. 레퍼런스 카운터가 0이 되면 메모리가 자동 해제됨
	//make_shared : 객체와 참조 카운트를 하나의 메모리 블록에 같이 할당시킴. shared_ptr을 생성하는 함수
	shared_ptr<Super> sptr = make_shared<Super>();
	shared_ptr<Super> sptr2 = sptr; // sptr2, sptr은 동일한 객체를 가리킴
	sptr2->func();
	//---------------------------------------------
	//weak_ptr: 레퍼런스 카운터에 영향을 주지 않는 스마트 포인터
	weak_ptr<Super> wptr = sptr;
	
	shared_ptr<Super> wptr2 = wptr.lock(); // weak_ptr로 전환한 shared_ptr 사용 가능
	
	return 0;
}

/* 기본 클래스를 참조하는 lvalue를 파생된 클래스에 대한 참조로 변환
	상속관계에서 안전하게 형변환을 지원한다. 업캐스팅
	다운 캐스팅 경우는 다형성을 위해서 virtual 메서드가 꼭 있어야 한다
	*/

