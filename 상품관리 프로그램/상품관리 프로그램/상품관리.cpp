#include <iostream>
#include <vector>
using namespace std;

// �⺻ ��ǰ Ŭ����
class Product {
protected:
    string id;
    int price;
    string producer;

public:
    Product(string id, int price, string producer)
        : id(id), price(price), producer(producer) {}

    virtual void showInfo() {
        cout << "ID: " << id << ", Price: " << price << ", Producer: " << producer;
    }

    virtual ~Product() {}
};

// å Ŭ����
class Book : public Product {
private:
    string title;
    string author;

public:
    Book(string id, int price, string producer, string title, string author)
        : Product(id, price, producer), title(title), author(author) {}

    void showInfo() override {
        Product::showInfo();
        cout << ", Title: " << title << ", Author: " << author << endl;
    }
};

// �ڵ��� Ŭ����
class HandPhone : public Product {
private:
    string model;
    int storage;

public:
    HandPhone(string id, int price, string producer, string model, int storage)
        : Product(id, price, producer), model(model), storage(storage) {}

    void showInfo() override {
        Product::showInfo();
        cout << ", Model: " << model << ", Storage: " << storage << "GB" << endl;
    }
};

// ��ǻ�� Ŭ����
class Computer : public Product {
private:
    string cpu;
    int ram;

public:
    Computer(string id, int price, string producer, string cpu, int ram)
        : Product(id, price, producer), cpu(cpu), ram(ram) {}

    void showInfo() override {
        Product::showInfo();
        cout << ", CPU: " << cpu << ", RAM: " << ram << "GB" << endl;
    }
};

// ���� �Լ�
int main() {
    vector<Product*> products;

    // ��ǰ ���
    products.push_back(new Book("B001", 15000, "BookPub", "C++ Programming", "Kim"));
    products.push_back(new HandPhone("H001", 800000, "Samsung", "Galaxy S21", 128));
    products.push_back(new Computer("C001", 1200000, "LG", "Intel i7", 16));

    // ��ǰ ���� ���
    for (Product* p : products) {
        p->showInfo();
    }

    // �޸� ����
    for (Product* p : products) {
        delete p;
    }

    return 0;
}
