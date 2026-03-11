#include <iostream>
using namespace std;

class Tollbooth
{
private:
    unsigned int totalNumOfCar;
    double totalAmount;

public:
    Tollbooth()
    {
        this->totalNumOfCar = 0;
        this->totalAmount = 0;
    }
    void payingCar()
    {
        this->totalNumOfCar++;
        this->totalAmount += 0.50;
    }
    void nopayCar()
    {
        this->totalNumOfCar++;
    }
    void printOnConsole()
    {
        unsigned int payingCars = totalAmount / 0.50;
        unsigned int nonPayingCars = totalNumOfCar - payingCars;
        cout << "Total number of paying cars:----" << payingCars << endl;
        cout << "Total number of nonPaying cars:----" << nonPayingCars << endl;
        cout << "Total number of cars passed:----" << this->totalNumOfCar << endl;
        cout << "Total number of Amount collected:----" << this->totalAmount << endl;
    }
};

int menuChoice(void)
{
    int choice;
    cout << "0.EXIT" << endl;
    cout << "1.payingCar" << endl;
    cout << "2.nopayCar" << endl;
    cout << "3.printOnConsole" << endl;
    cout << "Enter choice";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Tollbooth t1;
    while ((choice = menuChoice()) != 0)
    {
        switch (choice)
        {

        case 1:
        {
            t1.payingCar();
            break;
        }
        case 2:
        {
            t1.nopayCar();
            break;
        }
        case 3:
        {
            t1.printOnConsole();
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
