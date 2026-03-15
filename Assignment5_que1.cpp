#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(void) : day(0), month(0), year(0) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void acceptRecord(){
        cout<<"Enter day:"<<endl;
        cin>>day;
        cout<<"Enter month:"<<endl;
        cin>>month;
        cout<<"Enter year:"<<endl;
        cin>>year;
    } 
    void printRecord(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person
{
private:
    string name;
    string address;
    Date birthdate;

public:
    Person(void) : name(""), address("") {}
    Person(string name, string address) : name(name), address(address) {}
    Person(string name, string address, int day, int month, int year) : name(name), address(address), birthdate(day, month, year) {}

     void acceptRecord(){
        cout<<"Enter name:"<<endl;
        cin>>name;
        cout<<"Enter address:"<<endl;
         cin.ignore();
        getline(cin, address);
        cout<<"Enter birthdate:"<<endl;
        this->birthdate.acceptRecord();
    } 
    void printRecord(){
        cout<<"name:"<<name<<endl;
        cout<<"address:"<<address<<endl;
        this->birthdate.printRecord();
    }
};

class Students
{
private:
    int id;
    int marks;
    string course;
    Date joining_date;
    Date end_date;

public:
    Students(void) : id(0), marks(0), course("") {}
    Students(int id, int marks, string course) : id(id), marks(marks), course(course) {}
    Students(int id, int marks, string course, Date joining_date, Date end_date) : id(id), marks(marks), course(course), joining_date(joining_date), end_date(end_date) {}

    void acceptRecord(){
        cout<<"Enter id:"<<endl;
        cin>>id;
        cout<<"Enter marks:"<<endl;
        cin>>marks;
        cout<<"Enter course:"<<endl;
        cin>>course;
        cout<<"Enter joining_date:"<<endl;
        this->joining_date.acceptRecord();
        cout<<"Enter end_date:"<<endl;
        this->end_date.acceptRecord();
    } 
    void printRecord(){
        cout<<"id:"<<id<<endl;
        cout<<"marks:"<<marks<<endl;
        cout<<"course:"<<course<<endl;
        cout<<"joining_date:"<<endl;
        this->joining_date.printRecord();
        cout<<"end_date:"<<endl;
        this->end_date.printRecord();
    }
};

int menuList(){
    int choice;
    cout<<"\n0:EXIT"<<endl;
    cout<<"1:Person's record"<<endl;
    cout<<"2:Student's record"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
    
}
int main()
{
    int choice;
    Person *personPtr=new Person();
    Students *studentPtr=new Students();
    while ((choice=menuList())!=0)
    {
        switch (choice)
        {
        case 1:
            personPtr->acceptRecord();
            personPtr->printRecord();
            break;
        case 2:
            studentPtr->acceptRecord();
            studentPtr->printRecord();
            break;
        default:
            break;
        }
    }
    delete personPtr;
    personPtr=NULL;

    delete studentPtr;
    studentPtr=NULL;
    return 0;
}
