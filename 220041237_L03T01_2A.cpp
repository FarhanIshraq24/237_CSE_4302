#include<iostream>
#include<string>

using namespace std;

class Temaparature{
    private:
     double temparature;
     double increament;
    public:
      Temaparature(){
        temparature = 0;
        increament = 0;
      }
      void setIncreament(double increament){
        this->increament = increament;
      }
      void getTemparature(){
        cout<<this->temparature<<endl;
      }
      void increment(){
        float final_temp=this->temparature+=this->increament;
        cout<<"The final temperature after increment is "<<final_temp<<endl;
      }
      void resetTemparature(){
        this->temparature = 0;
        cout<<"Temperature reset to 0 degrees Celsius."<<endl;
      }

};

int main(){
  Temaparature t1;
  t1.setIncreament(5);
  t1.getTemparature();
  t1.increment();
  t1.increment();
  t1.resetTemparature();

  return 0;
}