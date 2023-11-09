#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Bank{
        char name[100];
    char lastName[100];
        int savingNumber;
        char profession[100];
        char address[1000];
        int balance;
        int fix;
        int ac;
        struct Bank *next;
}node;

node *start=NULL;


node* createnode()
{
        node *n;
        n=(node*)malloc(sizeof(node));
        return(n);
}


void insert()
{
        node *temp,*prev;
        temp=createnode();
        int value1;
        printf("\n\t\tEnter the first name:- ");  
        scanf("%s",temp->name);

    printf("\n\t\tEnter the last name:- ");  
        scanf("%s",temp->lastName);


        printf("\n\t\tEnter the Savings number:- ");
        scanf("%d",&value1);
        
        int flag=0;
        node *search;
        search=start;
        if(start==NULL)
        {
                flag=0;
        }
        else
        {
                while(search!=NULL)
                {
                        if(value1==search->savingNumber)
                        {
                                flag=1;
                                printf("\n\t\tId already exists");
                                break;
                        }
                        else
                        {
                                search=search->next;
                        }
                }
        }

        if(flag==0)
        {       
                temp->savingNumber=value1;
                fflush(stdin);
                printf("\n\t\tEnter your profession:- ");
                scanf("%s",temp->profession);
                fflush(stdin);
                printf("\n\t\tEnter your address:- ");
                scanf("%s",temp->address);
                fflush(stdin);

                
                printf("\n\t\tDo you want credit or debit card ?   :- For Yes press 1 , otherwise press 2:- ");
                int option;
                scanf("%d", &option);

                if(option == 1) {
                        printf("\n\t\tInitially 100 Taka diposited in this account\n ");
                        // temp->balance=100;
                        // after mod
                        temp->fix=100;
                        temp->balance=0;

                } else {
                        temp->balance = 0;
                        temp->fix = 0;
                }
                

                
                int acc=rand()%989785;
                printf("\n\t\tUnique bank ac id. is %d\n",acc);
                temp->ac=acc;
                temp->next=NULL;
                if(start==NULL)
                {
                        start=temp;
                }
                else
                {
                        node *t;
                        t=start;
                        while(t->next!=NULL)
                                t=t->next;
                        t->next=temp;
        }
        }
}


void widraw()
{
        int value1;
        printf("\n\t\tEnter the Savings no.:- ");
        scanf("%d",&value1);
        
        int flag=0;
        node *search;
        search=start;
        if(start==NULL)
        {
                flag=0;
        }
        else
        {
                while(search!=NULL)
                {
                        if(value1==search->savingNumber)
                        {
                                flag=1;
                                break;
                        }
                        else
                        {
                                search=search->next;
                        }
                }
        }
        
        if(flag==1)
        {
                node *t=search;
                int limit;
                printf("\n\t\tEnter the amount:- ");
                scanf("%d",&limit);
                if(limit>0 && limit<=t->balance)
                {
                        t->balance-=limit;
                        printf("\n\t\t%d debited from account no. %d\n",limit,t->ac);
                        printf("\n\t\tYour current balance is %d\n",t->balance);
                }
                else
                        printf("\n\t\tEnter a valid limit\n");
                        
        }
        else
        {
                printf("\nNo id. exists\n");
        }
}



void deposit()
{
        int value1;
        printf("\n\t\tEnter the Savings number:- ");
        scanf("%d",&value1);
        
        int flag=0;
        node *search;
        search=start;
        if(start==NULL)
        {
                flag=0;
        }
        else
        {
                while(search!=NULL)
                {
                        if(value1==search->savingNumber)
                        {
                                flag=1;
                                break;
                        }
                        else
                        {
                                search=search->next;
                        }
                }
        }
        
        if(flag=1)
        {
                node *t=search;
                int limit;
                printf("\n\t\tEnter the amount:- ");
                scanf("%d",&limit);
                if(limit>0)
                {
                        t->balance+=limit;
                        printf("\n\t\t%d credited in account no %d\n",limit,t->ac);
                        printf("\n\t\tYour current balance is %d taka\n",t->balance);
                }
                else
                        printf("\n\t\tEnter a valid limit\n");
                        
        }
        else
        {
                printf("\nNo id. exists\n");
                
        }
}

void fix()
{
        int value1;
        printf("\n\t\tEnter the Savings number:- ");
        scanf("%d",&value1);
        
        int flag=0;
        node *search;
        search=start;
        if(start==NULL)
        {
                flag=0;
        }
        else
        {
                while(search!=NULL)
                {
                        if(value1==search->savingNumber)
                        {
                                flag=1;
                                break;
                        }
                        else
                        {
                                search=search->next;
                        }
                }
        }
        
        if(flag=1)
        {
                node *t=search;
                int limit;
                printf("\n\t\tEnter the amount:- ");
                scanf("%d",&limit);
                if(limit>0)
                {
                        t->fix+=limit;
                        printf("\n\t\t%d taka deposited in account no %d\n",limit,t->ac);
                }
                else
                        printf("\n\t\tEnter a valid limit\n");
        }
        else
        {
                printf("\nNo id. exists\n");
                
        }
        
}


void viewlist()
{
        node *view;
        int count=1;
        if(start==NULL)
        {
                printf("\n\t\tList is empty.\n");
        }
        else
        {
                view=start;
                while(view!=NULL)
                {
                printf("\n\t\t[-----Information of Client no. %d-----]",count);
                printf("\n\t\tName :- ");
                printf("%s ",view->name);
                printf("%s",view->lastName);


                printf("\n\t\tSavings No. :- ");
                printf("%d",view->savingNumber);
                printf("\n\t\tAccount number:- ");
                printf("%d",view->ac);
                printf("\n\t\tProfession:- ");
                printf("%s",view->profession);
                printf("\n\t\tAddress:- ");
                printf("%s",view->address),
                printf("\n\t\tBalance:- ");
                printf("%d",view->balance),
                printf("\n\t\tFixed Diposit:- ");
                printf("%d\n",view->fix);
                printf("\t\tTotal amount with Balance and Fix Diposit: %d taka\n\n", view->fix + view->balance);

                count++;
                view=view->next;
                }
                count--;
                printf("\n\n\t\tNumber of accounts = %d\n",count);
        }
}


void view()
{
        int value1;
        printf("\n\t\tEnter the Savings number:- ");
        scanf("%d",&value1);
        
        int flag=0;
        node *search;
        search=start;
        if(start==NULL)
        {
                flag=0;
        }
        else
        {
                while(search!=NULL)
                {
                        if(value1==search->savingNumber)
                        {
                                flag=1;
                                printf("\n\t\tId already exists");
                                break;
                        }
                        else
                        {
                                search=search->next;
                        }
                }
        }
        
        if(flag=1)
        {
                node *view=search;
                printf("\n\t\tName :- ");
                printf("%s",view->name);
        printf(" %s",view->lastName);


                printf("\n\t\tSavings Number :- ");
                printf("%d",view->savingNumber);
                printf("\n\t\tAccount number:- ");
                printf("%d",view->ac);
                //view->roll=value1;
                printf("\n\t\tProfession:- ");
                printf("%s",view->profession);
                printf("\n\t\tAddress:- ");
                printf("%s",view->address),
                printf("\n\t\tBalance:- ");
                printf("%d",view->balance),
                printf("\n\t\tFixed Diposit:- ");
                printf("%d\n",view->fix);
                printf("\t\tTotal amount with Balance and Fix Diposit: %d taka\n", view->fix + view->balance);

        }
        else
        {
                printf("\nNo account exists\n");
        }
}


void close()
{
        
        int value1;
        printf("\n\t\tEnter the Savings number:- ");
        scanf("%d",&value1);
        
        int flag=0;
        node *search;
        search=start;
        if(start==NULL)
        {
                printf("\nNo account exists.\n");
        }
        else if(start->savingNumber==value1)
        {
                node *t;
                t=start;
                if(start->next==NULL)
                        start=NULL;
                else
                        start=start->next;
                free(t);
                printf("\n\t\tAccount deleted\n");
        }
        else
        {
                node *prev,*t;
                t=start->next;
                while(t!=NULL && t->savingNumber!=value1)
                {
                        prev=t;
                        t=t->next;
                }
                if(t->next==NULL)
                {
                        printf("\n\t\tNo account exists\n");
                
                }
                else
                {
                        node *link;
                        link=t->next;
        
                        if(t->next==NULL)
                        {
                                prev->next=NULL;
                        }
                        else
                        {
                                prev->next=link;
                        }
                        free(t);
                        printf("\n\t\tAccount deleted\n");
                }
                
        }
        
}

int menu()
{
        int choice;
        printf("\n1: Register an account\n");
        printf("\n2: Withdraw money\n");
        printf("\n3: Deposit money\n");
        printf("\n4: Fixed Diposit\n");
        printf("\n5: Close account\n");
        printf("\n6: Get statements (account)\n");
        printf("\n7: View All account\n");
        printf("\n0: Close application\n");
        printf("\n\t\tENTER YOUR CHOICE:- ");
        scanf("%d",&choice);
        return(choice);
}
int main()
{
        printf("\n WELCOME TO DIU BANKING SYSTEM\n\n");
        printf("\n DEVELOPED BY AZAM,SADMAN,AZIM,RAJIN AND PRITU\n\n");
        while(1)
        {
                switch(menu())
                {
                        case 1:
                                insert();
                                break;
                        case 2:
                                widraw();
                                break;
                        case 3:
                                deposit();
                                break;
                        case 4:
                                fix();
                                break;
                        case 5:
                                close();
                                break;
                        case 6:
                                view();
                                break;
                        case 7:
                                viewlist();
                                break;
                        case 0:
                                printf("\n\t\tProject by Sadman , Azam , Rashed, Azim, Pritu");
                                exit(1);
                                
                                break;
                        default:
                                printf("\nENTER A VALID CHOICE");
                }
        }
        return(0);
}