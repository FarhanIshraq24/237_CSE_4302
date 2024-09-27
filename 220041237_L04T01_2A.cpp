#include<iostream>
#include<string>

using namespace std;
class Product{
    private:
        string name;
        int id;
        double price;
        int quantity;
    public:    
        Product(string product_name,int product_id,double product_price,int product_quantity): name(product_name), id(product_id), price(product_price), quantity(product_quantity) {}

        void addToInventory(int addQuantity){
            quantity += addQuantity;
            cout << "Added " << addQuantity << " units of " << name << " to inventory." << endl;
        }
        bool isAvailable(){
            return quantity > 0;
        }
        void purchase(int purchased_Quantity){
            if(isAvailable()){
                if(purchased_Quantity <= quantity){
                    quantity -= purchased_Quantity;
                    cout << "Purchased " << purchased_Quantity << " units of " << name << ". Remaining quantity: " << quantity << endl;
                } else {
                    cout << "Insufficient quantity in inventory." << endl;
                }
            } else {
                cout << "Product is out of stock." << endl;
            }
        }
        void updatePrice(int discountPercent){
            double discountAmount = price * (discountPercent / 100.0);
            price -= discountAmount;
            cout << "Updated price of " << name << " to $" << price << " after a " << discountPercent << "% discount." << endl;
        }
        void displayInventoryValue(){
            double inventoryvalue= quantity*price;
            cout << "Current inventory value of " << name << ": $" << inventoryvalue << endl;
        }
        void displayDetails(){
            cout << "Product Name: " << name << endl;
            cout << "Product ID: " << id << endl;
            cout << "Price: $" << price << endl;
            cout << "Quantity: " << quantity << endl;
        }

        void displayTotalinventoryValue(Product p[], int quantity){
            double totalInventoryValue = 0.0;
            for(int i=0; i<quantity; i++){
                totalInventoryValue += p[i].price * p[i].quantity;
            }
            cout << "Total inventory value: $" << totalInventoryValue << endl; 
        }
        double getprice(){
            return price;
        }
        int getquantity(){
            return quantity;
        }
};

int main(){
    Product p1("Cows", 12345, 1200.0, 5);
    Product p2("Sheeps", 67890, 800.0, 10);
    Product p3("Camels", 98765, 50.0, 0);
    p1.displayDetails();
    p1.addToInventory(10);
    p1.displayInventoryValue();
    p1.purchase(3);
    p1.displayInventoryValue();
    p1.updatePrice(10);
    p1.displayDetails();
    p1.purchase(15);
    Product product[]={p1,p2,p3};
    double sum=0;
    for(int i=0;i<3;i++){
        sum+=product[i].getprice()*product[i].getquantity();
    }
    cout << "Total value of all products: $" << sum << endl;
    p1.displayTotalinventoryValue(product, 3);
    return 0;
}