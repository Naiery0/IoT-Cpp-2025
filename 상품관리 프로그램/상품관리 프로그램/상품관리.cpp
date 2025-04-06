#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ��ǰ
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
        cout << "ID: " << id << ", ����: " << price << ", ������: " << producer;
    }

    virtual string getType() const = 0;

    virtual ~Product() {}
};

// å
class Book : public Product {
private:
    string title;
    string author;

public:
    Book(string id, int price, string producer, string title, string author)
        : Product(id, price, producer), title(title), author(author) {}

    void showInfo() const override {
        Product::showInfo();
        cout << ", å ����: " << title << ", ����: " << author << endl;
    }

    string getType() const override {
        return "Book";
    }
};

// �ڵ���
class HandPhone : public Product {
private:
    string model;

public:
    HandPhone(string id, int price, string producer, string model)
        : Product(id, price, producer), model(model) {}

    void showInfo() const override {
        Product::showInfo();
        cout << ", �𵨸�: " << model << endl;
    }

    string getType() const override {
        return "HandPhone";
    }
};


// ��ǻ��
class Computer : public Product {
private:
    string cpu;

public:
    Computer(string id, int price, string producer, string cpu)
        : Product(id, price, producer), cpu(cpu) {}

    void showInfo() const override {
        Product::showInfo();
        cout << ", CPU�𵨸�: " << cpu << endl;
    }

    string getType() const override {
        return "Computer";
    }
};


// ��ǰ ��� ����
vector<Product*> products;

// �߰�
void addProduct() {
    int type;
    cout << "\n��ǰ ���� ���� (1: å, 2: �ڵ���, 3: ��ǻ��): ";
    cin >> type;

    string id, producer;
    int price;
    cout << "ID: ";
    cin >> id;
    cout << "����: ";
    cin >> price;
    cout << "������: ";
    cin >> producer;

    if (type == 1) {
        string title, author;
        cout << "å ����: ";
        cin.ignore(); getline(cin, title);
        cout << "����: ";
        getline(cin, author);
        products.push_back(new Book(id, price, producer, title, author));
    }
    else if (type == 2) {
        string model;
        cout << "�𵨸�: ";
        cin >> model;
        products.push_back(new HandPhone(id, price, producer, model));
    }
    else if (type == 3) {
        string cpu;
        cout << "CPU�𵨸�: ";
        cin >> cpu;
        products.push_back(new Computer(id, price, producer, cpu));
    }
    else {
        cout << "�߸��� �Է��Դϴ�." << endl;
    }

    cout << "��ǰ�� �߰��Ǿ����ϴ�." << endl;
}

// �˻�
void searchProduct() {
    string searchId;
    cout << "\n�˻��� ��ǰ ID �Է�: ";
    cin >> searchId;

    bool found = false;
    for (Product* p : products) {
        if (p->getId() == searchId) {
            cout << "\n��ǰ ����:" << endl;
            p->showInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "�ش� ID�� ��ǰ�� �����ϴ�." << endl;
    }
}

// ����
void deleteProduct() {
    string deleteId;
    cout << "\n������ ��ǰ ID �Է�: ";
    cin >> deleteId;

    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getId() == deleteId) {
            delete* it;
            products.erase(it);
            cout << "\n��ǰ�� �����Ǿ����ϴ�." << endl;
            return;
        }
    }

    cout << "�ش� ID�� ��ǰ�� �����ϴ�." << endl;
}

// ��ü ��ǰ ���
void listProducts() {
    cout << "\n[��ü ��ǰ ���]" << endl;
    for (Product* p : products) {
        p->showInfo();
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== ��ǰ ���� ���α׷� =====\n" << endl;
        cout << "1. ��ǰ �߰�" << endl;
        cout << "2. ��ǰ �˻�" << endl;
        cout << "3. ��ǰ ����" << endl;
        cout << "4. ��ü ��ǰ ���" << endl;
        cout << "0. ����" << endl;
        cout << "����: ";
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
            cout << "���α׷� ����." << endl;
            break;
        }
        else {
            cout << "�߸��� �����Դϴ�." << endl;
        }
    }

    return 0;
}
