#include<iostream>
#include<cmath>
using namespace std;

class Shape {
public:
    virtual void whoAmI() = 0; 
};

class TwoDimensionalShape : public Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class ThreeDimensionalShape : public Shape {
public:
    virtual double surfaceArea() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDimensionalShape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() override { return side * side; }
    double perimeter() override { return 4 * side; }
    void whoAmI() override { cout << "Square,two-dimensional shape." << endl; }
};

class Circle : public TwoDimensionalShape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return M_PI * radius * radius; }
    double perimeter() override { return 2 * M_PI * radius; }
    void whoAmI() override { cout << "Circle,two-dimensional shape." << endl; }
};

class Cube : public ThreeDimensionalShape {
    double side;
public:
    Cube(double s) : side(s) {}
    double surfaceArea() override { return 6 * side * side; }
    double volume() override { return side * side * side; }
    void whoAmI() override { cout << "Cube,three-dimensional shape." << endl; }
};

class Sphere : public ThreeDimensionalShape {
    double radius;
public:
    Sphere(double r) : radius(r) {}
    double surfaceArea() override { return 4 * M_PI * radius * radius; }
    double volume() override { return (4.0 / 3) * M_PI * radius * radius * radius; }
    void whoAmI() override { cout << "Sphere,three-dimensional shape." << endl; }
};

int main() {
    Square square(5);
    square.whoAmI();
    cout << "Area: " << square.area() << ", Perimeter: " << square.perimeter() << endl;

    Circle circle(3);
    circle.whoAmI();
    cout << "Area: " << circle.area() << ", Perimeter: " << circle.perimeter() << endl;

    Cube cube(4);
    cube.whoAmI();
    cout << "Surface Area: " << cube.surfaceArea() << ", Volume: " << cube.volume() << endl;

    Sphere sphere(2);
    sphere.whoAmI();
    cout << "Surface Area: " << sphere.surfaceArea() << ", Volume: " << sphere.volume() << endl;

    return 0;
}
