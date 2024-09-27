#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string EmpName;      
    int ID;              
    float BaseSalary;   
    int JoiningYear;     

public:

    void FeedInfo(string empName, int id, float baseSalary, int joiningYear) {
        EmpName = empName;
        ID = id;
        BaseSalary = baseSalary;
        JoiningYear = joiningYear;
    }

    float calculateTotalSalary(){
        float transportAllowance = BaseSalary * 0.10;
        float housingAllowance = BaseSalary * 0.30;
        float miscAllowance = BaseSalary * 0.10;
        return BaseSalary + transportAllowance + housingAllowance + miscAllowance;
    }

    float calculateBonus(string status){
        float totalSalary = calculateTotalSalary();
        float bonusPercentage = 0;

        if (status == "Low") {
            bonusPercentage = 0.05;
        } else if (status == "Moderate") {
            bonusPercentage = 0.10;
        } else if (status == "High") {
            bonusPercentage = 0.15;
        }

        return totalSalary * bonusPercentage;
    }

    string getStatus(int age){
        float totalSalary = calculateTotalSalary();

        if (age <= 25) {
            if (totalSalary <= 20000) return "Low";
            else return "Moderate";
        } else {
            if (totalSalary <= 21000) return "Low";
            else if (totalSalary <= 60000) return "Moderate";
            else return "High";
        }
    }

    void ShowInfo(){
        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout << "Base Salary: BDT " << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Total Salary: BDT " << calculateTotalSalary() << endl;
    }
};


int main(){
    Employee e1;
    e1.FeedInfo("Shafi", 123, 30000, 2018);
    e1.ShowInfo();
    int age=99;
    string status = e1.getStatus(age);
    cout << "Status: " << status << endl;
    float bonus = e1.calculateBonus(status);
    cout << "Bonus: BDT " << bonus << endl;

    
    return 0;
}