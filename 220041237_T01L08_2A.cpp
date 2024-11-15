#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual void display() { cout << "Name: " << name << endl; }
};

class Employee : public Person {
private:
    int employeeID;
protected:
    float salary;
public:
    Employee(string n, int id, float sal) : Person(n), employeeID(id), salary(sal) {}
    void display() {
        Person::display();
        cout << "Employee ID: " << employeeID << ", Salary: " << salary << endl;
    }
};

class Intern : public Employee {
    string schoolName;
public:
    Intern(string n, int id, float sal, string school) : Employee(n, id, sal), schoolName(school) {}
    void display() override {
        Employee::display();
        cout << "School Name: " << schoolName << endl;
    }
};

class Manager : protected Employee {
    string department;
public:
    Manager(string n, int id, float sal, string dept) : Employee(n, id, sal), department(dept) {}
    void display() override {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

class Director : public Manager {
    float bonus;
public:
    Director(string n, int id, float sal, string dept, float b) : Manager(n, id, sal, dept), bonus(b) {}
    void display() override {
        Manager::display();
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {
    Manager manager("farhan",237,10.05,"kamla");
    manager.display();
    Director director("rafi",222,100000000.0005,"boss",10000.00003);
    director.display();
    return 0;
}
