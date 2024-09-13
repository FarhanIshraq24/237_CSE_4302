#include<bits/stdc++.h>
using namespace std;
struct fraction
{
    int a,b;
    char slash;
};

int main(){
    struct fraction f1, f2, f3;
    cout << "Enter the first fraction: ";
    cin >> f1.a >> f1.slash >> f1.b;
    cout << "Enter the second fraction: ";
    cin >> f2.a >> f2.slash >> f2.b;

    f3.a = (f1.a * f2.b) + (f1.b * f2.a);
    f3.b = f1.b * f2.b;
    f3.slash = f1.slash;
    cout << "Sum of the two fractions: " << f3.a << f3.slash << f3.b << endl;

    return 0;
}
