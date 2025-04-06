#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 상품
class Product {
protected:
    string id;
    int price;
    string producer;

public:
    Product(string id, int price, string producer)
        : id(id), price(price), producer(producer) {}

    string getId() const { return id; }

    virtual void showInfo() const {
        cout << "ID: " << id << ", 가격: " << price << ", 제조사: " << producer;
    }

    virtual string getType() const = 0;

    virtual ~Product() {}
};

// 책
class Book : public Product {
private:
    string title;
    string author;

public:
    Book(string id, int price, string producer, string title, string author)
        : Product(id, price, producer), title(title), author(author) {}

    void showInfo() const override {
        Product::showInfo();
        cout << ", 책 제목: " << title << ", 저자: " << author << endl;
    }

    string getType() const override {
        return "Book";
    }
};

// 핸드폰
class HandPhone : public Product {
private:
    string model;

public:
    HandPhone(string id, int price, string producer, string model)
        : Product(id, price, producer), model(model) {}

    void showInfo() const override {
        Product::showInfo();
        cout << ", 모델명: " << model << endl;
    }

    string getType() const override {
        return "HandPhone";
    }
};


// 컴퓨터
class Computer : public Product {
private:
    string cpu;

public:
    Computer(string id, int price, string producer, string cpu)
        : Product(id, price, producer), cpu(cpu) {}

    void showInfo() const override {
        Product::showInfo();
        cout << ", CPU모델명: " << cpu << endl;
    }

    string getType() const override {
        return "Computer";
    }
};


// 상품 목록 저장
vector<Product*> products;

// 추가
void addProduct() {
    int type;
    cout << "\n상품 종류 선택 (1: 책, 2: 핸드폰, 3: 컴퓨터): ";
    cin >> type;

    string id, producer;
    int price;
    cout << "ID: ";
    cin >> id;
    cout << "가격: ";
    cin >> price;
    cout << "제조사: ";
    cin >> producer;

    if (type == 1) {
        string title, author;
        cout << "책 제목: ";
        cin.ignore(); getline(cin, title);
        cout << "저자: ";
        getline(cin, author);
        products.push_back(new Book(id, price, producer, title, author));
    }
    else if (type == 2) {
        string model;
        cout << "모델명: ";
        cin >> model;
        products.push_back(new HandPhone(id, price, producer, model));
    }
    else if (type == 3) {
        string cpu;
        cout << "CPU모델명: ";
        cin >> cpu;
        products.push_back(new Computer(id, price, producer, cpu));
    }
    else {
        cout << "잘못된 입력입니다." << endl;
    }

    cout << "상품이 추가되었습니다." << endl;
}

// 검색
void searchProduct() {
    string searchId;
    cout << "\n검색할 상품 ID 입력: ";
    cin >> searchId;

    bool found = false;
    for (Product* p : products) {
        if (p->getId() == searchId) {
            cout << "\n상품 정보:" << endl;
            p->showInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "해당 ID의 상품이 없습니다." << endl;
    }
}

// 삭제
void deleteProduct() {
    string deleteId;
    cout << "\n삭제할 상품 ID 입력: ";
    cin >> deleteId;

    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getId() == deleteId) {
            delete* it;
            products.erase(it);
            cout << "\n상품이 삭제되었습니다." << endl;
            return;
        }
    }

    cout << "해당 ID의 상품이 없습니다." << endl;
}

// 전체 상품 출력
void listProducts() {
    cout << "\n[전체 상품 목록]" << endl;
    for (Product* p : products) {
        p->showInfo();
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== 상품 관리 프로그램 =====\n" << endl;
        cout << "1. 상품 추가" << endl;
        cout << "2. 상품 검색" << endl;
        cout << "3. 상품 삭제" << endl;
        cout << "4. 전체 상품 출력" << endl;
        cout << "0. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        if (choice == 1) {
            addProduct();
        }
        else if (choice == 2) {
            searchProduct();
        }
        else if (choice == 3) {
            deleteProduct();
        }
        else if (choice == 4) {
            listProducts();
        }
        else if (choice == 0) {
            for (Product* p : products)
                delete p;
            cout << "프로그램 종료." << endl;
            break;
        }
        else {
            cout << "잘못된 선택입니다." << endl;
        }
    }

    return 0;
}
