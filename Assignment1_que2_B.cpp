#include<iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    void initDate(struct Date *ptrDate);
    void printDateOnConsole(struct Date *ptrDate);
    void acceptDateFromConsole(struct Date *ptrDate);
    bool isLeapYear(struct Date *ptrDate);
    
};

void Date::initDate(struct Date *ptrDate){
    ptrDate->day=01;
    ptrDate->month=01;
    ptrDate->year=2000;
}  

void Date::printDateOnConsole(struct Date *ptrDate){
    cout<<"Day/Month/Year:"<< ptrDate->day<<"/"<<ptrDate->month<<"/"<<ptrDate->year<<endl;  
}
void Date::acceptDateFromConsole(struct Date *ptrDate){
    cout<<"Enter Day/Month/Year: ";
    cin>>ptrDate->day>>ptrDate->month>>ptrDate->year;
}

bool Date::isLeapYear(struct Date *ptrDate){
    int year = ptrDate->year;
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        cout<<"IsLeapYear:--> YES"<<endl;
        return true;
    }else{
        cout<<"IsLeapYear:--> NO"<<endl;
        return false;
    }
    
}
int menuChoice(void){
    int choice;
    cout<<"0.EXIT"<<endl;
    cout<<"1.initDate"<<endl;
    cout<<"2.printDateOnConsole"<<endl;
    cout<<"3.acceptDateFromConsole"<<endl;
    cout<<"4.isLeapYear"<<endl;
    cout<<"Enter choice";
    cin>>choice;
    return choice;
}

int main()
{
    struct Date dt;
    int choice;
    while ((choice=menuChoice())!=0)
    {
        switch (choice)
        {
        case 1:
            dt.initDate(&dt);
            break;
        case 2:
            dt.printDateOnConsole(&dt);
            break;
        case 3:
            dt.acceptDateFromConsole(&dt);
            break; 
        case 4:
            dt.isLeapYear(&dt);
            break;       
        default:
            break;
        }
    }
    
    return 0;
}
