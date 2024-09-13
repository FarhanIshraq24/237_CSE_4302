#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    char slash;
    cout << "Enter a fraction in the form of 'a/b': ";
    cin >> a >> slash >> b;
    cout << "Enter another fraction in the form of 'c/d': ";
    cin >> c >> slash >> d;
    int sum_numerator = a * d + b * c;
    int sum_denominator = b * d;
    cout << "The sum of the two fractions is: " << sum_numerator << "/" << sum_denominator << endl;
    return 0;

}