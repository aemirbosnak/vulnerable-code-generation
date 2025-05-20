//FormAI DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

// Structures for customers, accounts and transactions
typedef struct{
    int id;
    char name[30];
    char address[100];
    int phone_no;
} customer;

typedef struct{
    int acc_no;
    int balance;
    int cust_id;
} account;

typedef struct{
    int acc_no;
    int amount;
    char type[15];
} transaction;

// Function to check balance of an account
void check_balance(account *acc, int n){
    int acc_no, bal;
    printf("\nEnter account number: ");
    scanf("%d", &acc_no);
    for(int i=0; i<n; i++){
        if((acc+i)->acc_no == acc_no){
            bal = (acc+i)->balance;
            printf("Account balance: %d\n", bal);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to make a deposit to an account
void make_deposit(account *acc, transaction *trans, int n, int m){
    int acc_no, amount, i;
    printf("\nEnter account number: ");
    scanf("%d", &acc_no);
    for(i=0; i<n; i++){
        if((acc+i)->acc_no == acc_no){
            printf("Enter amount to deposit: ");
            scanf("%d", &amount);
            (acc+i)->balance += amount;
            (trans+m)->acc_no = acc_no;
            (trans+m)->amount = amount;
            strcpy((trans+m)->type,"deposit");
            printf("Deposit of %d successful.\n", amount);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to make a withdrawal from an account
void make_withdrawal(account *acc, transaction *trans, int n, int m){
    int acc_no, amount, i;
    printf("\nEnter account number: ");
    scanf("%d", &acc_no);
    for(i=0; i<n; i++){
        if((acc+i)->acc_no == acc_no){
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if(amount > (acc+i)->balance){
                printf("Insufficient balance!\n");
                return;
            }
            (acc+i)->balance -= amount;
            (trans+m)->acc_no = acc_no;
            (trans+m)->amount = amount;
            strcpy((trans+m)->type,"withdrawal");
            printf("Withdrawal of %d successful.\n", amount);
            return;
        }
    }
    printf("Account not found!\n");
}

int main(){
    int n, m=0;
    printf("Enter number of customers: ");
    scanf("%d", &n);

    // Allocating memory for customers, accounts and transactions
    customer *cust = (customer*)malloc(n * sizeof(customer));
    account *acc = (account*)malloc(n * sizeof(account));
    transaction *trans = (transaction*)malloc(n * 10 * sizeof(transaction));

    // Accepting customer and account details
    for(int i=0; i<n; i++){
        printf("\nEnter details of customer %d\n", i+1);
        (cust+i)->id = i+1;
        printf("Name: ");
        scanf("%s", (cust+i)->name);
        printf("Address: ");
        scanf("%s", (cust+i)->address);
        printf("Phone number: ");
        scanf("%d", &(cust+i)->phone_no);
        printf("Enter account details:\n");
        (acc+i)->cust_id = i+1;
        printf("Account number: ");
        scanf("%d" , &(acc+i)->acc_no);
        printf("Account balance: ");
        scanf("%d", &(acc+i)->balance);
    }

    // Displaying customer and account details
    printf("\nCustomer details:\n");
    printf("ID\t| Name\t\t| Address\t\t\t\t| Phone number\n");
    for(int i=0; i<n; i++){
        printf("%d\t| %s\t| %s\t| %d\n", (cust+i)->id, (cust+i)->name, (cust+i)->address, (cust+i)->phone_no);
    }

    // Accepting transactions from user
    int choice;
    while(1){
        printf("\nEnter your choice:\n1. Check balance\n2. Make a deposit\n3. Make a withdrawal\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: check_balance(acc, n); break;
            case 2: make_deposit(acc, trans, n, m); m++; break;
            case 3: make_withdrawal(acc, trans, n, m); m++; break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}