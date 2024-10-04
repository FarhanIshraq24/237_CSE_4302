#include<bits/stdc++.h>

using namespace std;


std::string generateRandomString(int length) {
    std::string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

// Function to generate a random double within a given range [min, max]
double randomInRange(double min, double max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    // Generate a random double between 0 and 1
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    // Scale and shift the random value to the desired range
    return min + randomFraction * (max - min);
}


class Products{
    private:
        string productName;
        string productCategory;
        string productDescription;
        int amountInStore;
        float regularPrice;
        float discountRate;

    public:
    Products(string name, string category, string description, int amount, float price, float discount) 
    : productName(name), productCategory(category), productDescription(description), amountInStore(amount), regularPrice(price), discountRate(discount) {}

    string getProductName() { return productName; }
    void setProductName(string name) { productName = name; }

    string getProductCategory() { return productCategory; }
    void setProductCategory(string category) { productCategory = category; }

    string getProductDescription() { return productDescription; }
    void setProductDescription(string description) { productDescription = description; }

    int getAmountInStore() { return amountInStore; }
    void setAmountInStore(int amount) { amountInStore = amount; }

    float getRegularPrice() { return regularPrice; }
    void setRegularPrice(float price) { regularPrice = price; }

    float getDiscountRate() { return discountRate; }
    void setDiscountRate(float discount) { discountRate = discount; }

    double calculateDiscount(int amountOfProducts) const {
        double discount = discountRate;
        double regular = regularPrice;
        if (amountOfProducts >= 5) {
            if(amountOfProducts >= 10){
                return ((discount+=3)/100)*regular;
            }
            return ((discount/100)*regular);

        }
    }
    double netTotal(int amountOfProducts) const {
        double totalCost = regularPrice * amountOfProducts;
        double discount = calculateDiscount(amountOfProducts);
        return totalCost - discount;
    }

};

void EditInformationByKeyboard(Products &product){
    string name, category, description;
    int amount;
    float price, discount;

    cout << "Enter product name: ";
    getline(cin, name);
    cout << "Enter product category: ";
    getline(cin, category);
    cout << "Enter product description: ";
    getline(cin, description);
    cout << "Enter amount in store: ";
    cin >> amount;
    cout << "Enter regular price: ";
    cin >> price;
    cout << "Enter discount rate: ";
    cin >> discount;

    product.setProductName(name);
    product.setProductCategory(category);
    product.setProductDescription(description);
    product.setAmountInStore(amount);
    product.setRegularPrice(price);
    product.setDiscountRate(discount);

}

void generateInformationInRandom(Products &product){
    product.setProductName(generateRandomString(6));
    product.setProductCategory(generateRandomString(7));
    product.setProductDescription(generateRandomString(70));
    product.setAmountInStore(rand() % 100 + 1);
    product.setRegularPrice(rand() % 100 + 1);
    product.setDiscountRate(rand() % 15 + 1);
}

void ShowAllDiscounts(vector<Products> &product){
    for(int i=0;i<product.size();i++){
        cout << "Product Name: " << product[i].getProductName() << ", Discount Amount: $" << product[i].calculateDiscount(1) << endl;
    }

}

void grossTotal(vector<Products> &product){
    for(int i=0;i<product.size();i++){
        int amountToPurchase = rand() % 10 + 1;
        cout << "Product Name: " << product[i].getProductName() << ", Net Total: $" << product[i].netTotal(amountToPurchase) << endl;
    }
}

bool compare(Products &a,Products &b){
    return a.getProductName() < b.getProductName();
}

void ShowAllAlphabetically(vector<Products> &product){
    sort(product.begin(),product.end(),compare);
    for(int i=0;i<product.size();i++){
        cout << "Product Name: " << product[i].getProductName() << "Product category: "<<product[i].getProductCategory()<<"Product discount: "<<product[i].getDiscountRate()<< endl;
    }
}


int main(){

    srand(static_cast<unsigned int>(time(0))); 



    vector<Products> products;

    for(int i=0;i<100;i++){
        Products p("Random string generate kore kemne?", "Random Category", "This is a random product description.", rand() % 100 + 1, rand() % 100 + 1, rand() % 15 + 1);
        products.push_back(p);
    }
    

    EditInformationByKeyboard(products[0]);
    EditInformationByKeyboard(products[5]);

    for (int i = 2; i < 100; ++i) {
        generateInformationInRandom(products[i]);
    }

    ShowAllDiscounts(products);

    grossTotal(products);

    ShowAllAlphabetically(products);


    return 0;
}