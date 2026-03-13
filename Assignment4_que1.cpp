#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int min;
    int sec;

public:
    Time(void) : hour(0), min(0), sec(0) {}
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}

    void setHours(int h)
    {
        hour = h;
    }

    void setMin(int m)
    {
        min = m;
    }

    void setSec(int s)
    {
        sec = s;
    }

    // getters
    int getHours()
    {
        return this->hour;
    }

    int getMin()
    {
        return this->min;
    }

    int getSec()
    {
        return this->sec;
    }

    void printTime()
    {
        cout << "Time is : " << hour << ":" << min << ":" << sec << endl;
    }
};

int menuChoice()
{
    int choice;
    printf("\n");
    printf("0.EXIT\n");
    printf("1.Add Time \n");
    printf("2.Display All Time\n");
    printf("3.Display only hrs of all time objects \n");
    printf("Enter choice");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int n;
    cout << "Enter number of Time objects: ";
    cin >> n;
    Time *arr = new Time[n];
    int count = 0;
    int choice;
    while ((choice = (menuChoice())) != 0)
    {
        switch (choice)
        {
        case 1:
            if (count < n)
            {
                int h, m, s;

                cout << "Enter hour minute second: ";
                cin >> h >> m >> s;
                arr[count].setHours(h);
                arr[count].setMin(m);
                arr[count].setSec(s);
                count++;
            }
            else
            {
                cout << "Array is full" << endl;
            }
            break;
        case 2:
            cout << "All Time Objects:";
            for (int i = 0; i < count; i++)
            {
                arr[i].printTime();
            }
            break;
        case 3:
            cout << "Hours of all Time objects:"<<endl;
            for (int i = 0; i < count; i++)
            {
                cout << arr[i].getHours() << endl;
            }
        default:
            break;
        }
    }
    delete[] arr;
    arr = NULL;

    return 0;
}
