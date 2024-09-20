#include <iostream>
#include <string>

using namespace std;

class RationalNumber{
    private: 
        int numerator;
        int denominator;
    public:
        void assignment(int numerator,int denominator){
            this->numerator = numerator;
            this->denominator = denominator;
        } 
        void convert(){
            float x =(float)this->numerator/(float)this->denominator;
            cout << x << endl;
        }  
        void invert(){
            int temp=this->numerator;
            this->numerator=this->denominator;
            this->denominator=temp;
        } 
        void print(){
            cout << "The Rational number is "<<this->numerator << "/" << this->denominator << endl;
        }

};

int main(){
    RationalNumber r1;
    r1.assignment(5, 10);
    r1.print();
    r1.convert();
    r1.invert();
    r1.print();

    return 0;

}