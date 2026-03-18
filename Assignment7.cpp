#include<iostream>
using namespace std;

class Employee{
protected:
    int id;
    double salary;

public:
    virtual ~Employee(){}

    virtual void accept(){
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter salary: ";
        cin>>salary;
    }

    virtual void display(){
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Manager : virtual public Employee{
protected:
    double bonus;

public:
    void accept(){
        Employee::accept();
        cout<<"Enter bonus: ";
        cin>>bonus;
    }

    void display(){
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
    }
};

class Salesman : virtual public Employee{
protected:
    double commission;

public:
    void accept(){
        Employee::accept();
        cout<<"Enter commission: ";
        cin>>commission;
    }

    void display(){
        Employee::display();
        cout<<"Commission: "<<commission<<endl;
    }
};

class SalesManager : public Manager, public Salesman{
public:
    void accept(){
        Employee::accept();
        cout<<"Enter bonus: ";
        cin>>bonus;
        cout<<"Enter commission: ";
        cin>>commission;
    }

    void display(){
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
        cout<<"Commission: "<<commission<<endl;
    }
};

int main(){

    Employee* arr[50];
    int type[50];   

    int count=0, choice;

    do{
        cout<<"\n----- MENU -----"<<endl;
        cout<<"1. Add Manager"<<endl;
        cout<<"2. Add Salesman"<<endl;
        cout<<"3. Add SalesManager"<<endl;
        cout<<"4. Display Count (Designation wise)"<<endl;
        cout<<"5. Display All Managers"<<endl;
        cout<<"6. Display All Salesman"<<endl;
        cout<<"7. Display All SalesManagers"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            arr[count] = new Manager();
            arr[count]->accept();
            type[count] = 1;
            count++;
            break;

        case 2:
            arr[count] = new Salesman();
            arr[count]->accept();
            type[count] = 2;
            count++;
            break;

        case 3:
            arr[count] = new SalesManager();
            arr[count]->accept();
            type[count] = 3;
            count++;
            break;

        case 4:{
            int m=0, s=0, sm=0;
            for(int i=0;i<count;i++){
                if(type[i]==1) m++;
                else if(type[i]==2) s++;
                else if(type[i]==3) sm++;
            }
            cout<<"Managers: "<<m<<endl;
            cout<<"Salesmen: "<<s<<endl;
            cout<<"SalesManagers: "<<sm<<endl;
            break;
        }

        case 5:
            cout<<"\n--- Managers ---"<<endl;
            for(int i=0;i<count;i++){
                if(type[i]==1){
                    arr[i]->display();
                    cout<<endl;
                }
            }
            break;

        case 6:
            cout<<"\n--- Salesmen ---"<<endl;
            for(int i=0;i<count;i++){
                if(type[i]==2){
                    arr[i]->display();
                    cout<<endl;
                }
            }
            break;

        case 7:
            cout<<"\n--- SalesManagers ---"<<endl;
            for(int i=0;i<count;i++){
                if(type[i]==3){
                    arr[i]->display();
                    cout<<endl;
                }
            }
            break;

        case 0:
            cout<<"Exiting..."<<endl;
            break;

        default:
            cout<<"Invalid choice"<<endl;
        }

    }while(choice!=0);

    for(int i=0;i<count;i++){
        delete arr[i];
    }

    return 0;
}