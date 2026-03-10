#include<iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate){
    ptrDate->day=01;
    ptrDate->month=01;
    ptrDate->year=2000;
}  

void printDateOnConsole(struct Date *ptrDate){
         cout<<"Day/Month/Year:"<< ptrDate->day<<"/"<<ptrDate->month<<"/"<<ptrDate->year<<endl;  
}
void acceptDateFromConsole(struct Date *ptrDate){
    cout<<"Enter Day/Month/Year: ";
    cin>>ptrDate->day>>ptrDate->month>>ptrDate->year;

}

bool isLeapYear(struct Date *ptrDate){
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
            initDate(&dt);
            break;
        case 2:
            printDateOnConsole(&dt);
            break;
        case 3:
            acceptDateFromConsole(&dt);
            break; 
        case 4:
            isLeapYear(&dt);
            break;       
        default:
            break;
        }
    }
    
    return 0;
}
