#include<iostream>
using namespace std;

class Employee{
protected:
    int id;
    double salary;

public:
    Employee():id(0),salary(0.0){}
    Employee(int id, double salary):id(id),salary(salary){}

    void setId(int id){ this->id=id; }
    int getId(){ return id; }

    void setSalary(double salary){ this->salary=salary; }
    double getSalary(){ return salary; }

    void accept(){
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter salary: ";
        cin>>salary;
    }

    void display(){
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Manager : virtual public Employee{
protected:
    double bonus;

public:
    Manager():bonus(0.0){}
    Manager(int id,double salary,double bonus)
        :Employee(id,salary),bonus(bonus){}

    void setBonus(double bonus){ this->bonus=bonus; }
    double getBonus(){ return bonus; }

   
    void accept(){
        Employee::accept();
        cout<<"Enter bonus: ";
        cin>>bonus;
    }

    void display(){
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
    }

    void acceptManager(){
        cout<<"Enter bonus: ";
        cin>>bonus;
    }

    void displayManager(){
        cout<<"Bonus: "<<bonus<<endl;
    }
};

class Salesman : virtual public Employee{
protected:
    double commission;

public:
    Salesman():commission(0.0){}
    Salesman(int id,double salary,double commission)
        :Employee(id,salary),commission(commission){}

    void setCommission(double commission){ this->commission=commission; }
    double getCommission(){ return commission; }


    void accept(){
        Employee::accept();
        cout<<"Enter commission: ";
        cin>>commission;
    }

    void display(){
        Employee::display();
        cout<<"Commission: "<<commission<<endl;
    }

   
    void acceptSalesman(){
        cout<<"Enter commission: ";
        cin>>commission;
    }

    void displaySalesman(){
        cout<<"Commission: "<<commission<<endl;
    }
};

class SalesManager : public Manager, public Salesman{
public:
    SalesManager(){}

    SalesManager(int id,double salary,double bonus,double commission)
        :Employee(id,salary),
         Manager(id,salary,bonus),
         Salesman(id,salary,commission){}

    void accept(){
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display(){
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main(){

    cout<<"----- Employee -----"<<endl;
    Employee e;
    e.accept();
    e.display();

    cout<<"\n----- Manager -----"<<endl;
    Manager m;
    m.accept();
    m.display();

    cout<<"\n----- Salesman -----"<<endl;
    Salesman s;
    s.accept();
    s.display();

    cout<<"\n----- SalesManager -----"<<endl;
    SalesManager sm;
    sm.accept();
    sm.display();

    return 0;
}