#include <iostream>
using namespace std;

class Cylinder
{
private:
    static double PI;
    double radius;
    double height;

public:
    Cylinder(void) : radius(0), height(0) {}
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    void setRadius(double radius)
    {
        this->radius = radius;
    }
    double getRadius()
    {
        return this->radius;
    }
    void setHeight(double height)
    {
        this->height = height;
    }
    double getHeight()
    {
        return this->height;
    }
    double calculateVolume()
    {
        return Cylinder::PI * this->radius * this->radius * this->height;
    }
};

double Cylinder::PI = 3.14;

int main()
{
    Cylinder c1;
    // Cylinder c1(2,16);
    c1.setRadius(25);
    c1.setHeight(50);
    cout << "radius: " << c1.getRadius() << endl;
    cout << "height: " << c1.getHeight() << endl;
    cout << "Volume of cylinder is: " << c1.calculateVolume();

    return 0;
}
