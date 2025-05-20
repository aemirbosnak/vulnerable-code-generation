//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

struct Account{
    int balance;
    char name[20];
    struct Account* next;
};

struct Account* head=NULL;

void add_account(){
    struct Account* new_account=malloc(sizeof(struct Account));
    scanf("%s",new_account->name);
    new_account->balance=0;
    new_account->next=NULL;
    if(head==NULL){
        head=new_account;
    }
    else{
        struct Account* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_account;
    }
}

void display_accounts(){
    struct Account* temp=head;
    while(temp!=NULL){
        printf("Account name: %s\n",temp->name);
        printf("Balance: %d\n",temp->balance);
        temp=temp->next;
    }
}

int main(){
    int choice;
    struct Account* temp;
    do{
        printf("1. Add Account\n2. Display Accounts\n3. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                exit(0);
        }
    }while(choice!=3);
    return 0;
}