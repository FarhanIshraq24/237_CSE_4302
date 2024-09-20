#include<iostream>
#include<string>

using namespace std;

class Bankaccount{
    private:
        string name;
        int number;
        string type;
        double balance;
    public:
        void customerDetails(string name, int number, string type, double balance){
            this->name = name;
            this->number = number;
            this->type = type;
            this->balance = balance;
        }
        void accountType(string type){
            this->type = type;
        }
        void Balance(){
            int x= this->balance;
            cout << "balance: " << x << endl;
        }

        void deposit(double amount){
            if(amount > 0){
                this->balance += amount;
                cout << "Deposit successful. New balance: " << this->balance << endl;
            } else {
                cout << "Invalid deposit amount." << endl;
            }
        }
        void withdraw(double amount){
            if(amount > 0 && amount <= this->balance){
                this->balance -= amount;
                cout << "Withdrawal successful. New balance: " << this->balance << endl;
            } else {
                cout << "Invalid withdrawal amount or insufficient balance." << endl;
            }
        }

        void display(){
            cout << "Customer Name: " << this->name << endl;
            cout << "Account Number: " << this->number << endl;
            cout << "Account Type: " << this->type << endl;
            cout << "Balance: " << this->balance << endl;
        }
};

int main(){
    Bankaccount b1;
    b1.customerDetails("Farhan Ishraq", 220041237, "Savings", 20000);
    b1.accountType("fdr");
    b1.Balance();
    b1.deposit(50);
    b1.withdraw(50);
    b1.display();

    return 0;
}