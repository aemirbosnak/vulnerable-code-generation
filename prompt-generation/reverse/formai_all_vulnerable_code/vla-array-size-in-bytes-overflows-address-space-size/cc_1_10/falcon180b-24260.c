//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    char name[50];
    char type[20];
    char number[15];
    double balance;
};

struct transaction{
    char date[20];
    char description[100];
    double amount;
    char category[20];
};

void add_account(struct account *a, int n){
    printf("Enter account name: ");
    scanf("%s", a[n].name);
    printf("Enter account type: ");
    scanf("%s", a[n].type);
    printf("Enter account number: ");
    scanf("%s", a[n].number);
    printf("Enter initial balance: ");
    scanf("%lf", &a[n].balance);
}

void display_accounts(struct account a[], int n){
    printf("\nAccount Details\n");
    printf("--------------------\n");
    for(int i=0; i<n; i++){
        printf("%-20s %-20s %-15s %10.2lf\n", a[i].name, a[i].type, a[i].number, a[i].balance);
    }
}

void add_transaction(struct transaction *t, int n){
    printf("\nEnter transaction details:\n");
    printf("---------------------------------\n");
    printf("Date: ");
    scanf("%s", t[n].date);
    printf("Description: ");
    scanf("%s", t[n].description);
    printf("Amount: ");
    scanf("%lf", &t[n].amount);
    printf("Category: ");
    scanf("%s", t[n].category);
}

void display_transactions(struct transaction t[], int n){
    printf("\nTransaction Details\n");
    printf("--------------------\n");
    for(int i=0; i<n; i++){
        printf("%-20s %-20s %10.2lf %s\n", t[i].date, t[i].description, t[i].amount, t[i].category);
    }
}

int main(){
    int n;
    printf("Enter the number of accounts: ");
    scanf("%d", &n);
    struct account a[n];
    for(int i=0; i<n; i++){
        add_account(a, i);
    }
    printf("\nAccounts added successfully!\n");

    int m;
    printf("Enter the number of transactions: ");
    scanf("%d", &m);
    struct transaction t[m];
    for(int i=0; i<m; i++){
        add_transaction(t, i);
    }
    printf("\nTransactions added successfully!\n");

    return 0;
}