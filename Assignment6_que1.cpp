#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    double price;
public:
    virtual void accept()=0;
    virtual double calculatePrice()=0;
    virtual ~Product(){};

};

class Book : public Product
{
private:
    string author;
public:
     void accept()
    {
        cout<<"Enter Book ID: ";
        cin>>id;
          cin.ignore();

        cout<<"Enter Title: ";
          getline(cin,title);

        cout<<"Enter Author: ";
         getline(cin,author);

        cout<<"Enter Price: ";
        cin>>price;
    }
     double calculatePrice()
    {
        return price - (price * 0.10);
    }
};

class Tape : public Product
{
private:
    string artist;

public:
    void accept()
    {
        cout<<"Enter Tape ID: ";
        cin>>id;
        cin.ignore();

        cout<<"Enter Title: ";
        getline(cin,title);

        cout<<"Enter Artist: ";
         getline(cin,artist);

        cout<<"Enter Price: ";
        cin>>price;
    }

    double calculatePrice()
    {
        return price - (price * 0.05);
    }
};


int main()
{
    Product* arr[3];
    int choice;
    double totalBill = 0;

    for(int i=0;i<3;i++)
    {
        cout<<"\n1. Buy Book"<<endl;
        cout<<"2. Buy Tape"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            arr[i] = new Book();
        else
            arr[i] = new Tape();

        arr[i]->accept();
    }

    for(int i=0;i<3;i++)
    {
        totalBill += arr[i]->calculatePrice();
    }

    cout<<"\nFinal Bill = "<<totalBill<<endl;

    for(int i=0;i<3;i++)
        delete arr[i];

    return 0;
}