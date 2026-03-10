#include<stdio.h>

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
         printf("Day/Month/Year: %d/%d/%d \n",ptrDate->day,ptrDate->month,ptrDate->year);
}
void acceptDateFromConsole(struct Date *ptrDate){
    printf("enter Day/Month/Year: \n");
    scanf("%d %d %d",&ptrDate->day,&ptrDate->month,&ptrDate->year);

}
int menuChoice(void){
    int choice;
    printf("\n");
    printf("0.EXIT\n");
    printf("1.initDate\n");
    printf("2.printDateOnConsole\n");
    printf("3.acceptDateFromConsole\n");
    printf("Enter choice");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    struct Date dt;
    int choice;
    while ((choice=menuChoice())!=0)
    {
        // printf("%d",choice);
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
        default:
            break;
        }
    }
    
    return 0;
}
