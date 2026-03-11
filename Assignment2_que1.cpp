#include <iostream>
using namespace std;

class Box
{
private:
    float length;
    float width;
    float height;

public:
    Box()
    {
        this->length = 20;
        this->width = 20;
        this->height = 20;
    }
    Box(float value)
    {
        this->length = value;
        this->width = value;
        this->height = value;
    }
    Box(float l, float w, float h)
    {
        this->length = l;
        this->width = w;
        this->height = h;
    }

    float calculateVolume()
    {
        return this->length * this->width * this->height;
    }
};

int menuChoice(void)
{
    int choice;
    cout << "0.EXIT" << endl;
    cout << "1. Calculate Volume with default values " << endl;
    cout << "2.Calculate Volume with length,breadth and height with same value " << endl;
    cout << "3.Calculate Volume with different length,breadth and height values." << endl;
    cout << "Enter choice";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    while ((choice = menuChoice()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            Box b1;
            cout << "Volume with default values: ---------" << b1.calculateVolume() << endl;
            break;
        }
        case 2:
        {
            float val;
            cout << "Enter one value: ";
            cin >> val;
            Box b2(val);
            cout << "Volume with length,breadth and height with same value: --------" << b2.calculateVolume() << endl;
            break;
        }
        case 3:
        {
            float l, w, h;
            cout << "Enter diff l,w,h values: " << endl;
            cin >> l >> w >> h;
            Box b3(l, w, h);
            cout << "Volume with different length,breadth and height values. ----------" << b3.calculateVolume() << endl;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
