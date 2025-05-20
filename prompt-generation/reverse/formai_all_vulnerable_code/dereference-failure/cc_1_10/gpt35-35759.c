//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct bankRecord {
    int account_number;
    char customer_name[50];
    float balance;
    char last_transaction[20];
} customers[100];

int count = 0;

void createAccount() {
    int account_number;
    char customer_name[50];
    float deposit;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    printf("\nEnter Customer Name: ");
    scanf("%s", customer_name);
    printf("\nEnter Initial Deposit: ");
    scanf("%f", &deposit);
    customers[count].account_number = account_number;
    strcpy(customers[count].customer_name, customer_name);
    customers[count].balance = deposit;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(customers[count].last_transaction, "%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    count++;
    printf("\nAccount created successfully!\n");
}

void viewAllAccounts() {
    printf("\nAccount Number\tCustomer Name\tBalance\tLast Transaction\n");
    for(int i=0; i<count; i++) {
        printf("\n%d\t\t%s\t\t%.2f\t%s", customers[i].account_number, customers[i].customer_name, customers[i].balance, customers[i].last_transaction);
    }
    printf("\n");
}

void searchAccount() {
    int account_number, index = -1;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i=0; i<count; i++) {
        if(customers[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nAccount not found!\n");
        return;
    }
    printf("\nAccount Found!");
    printf("\nAccount Number: %d", customers[index].account_number);
    printf("\nCustomer Name: %s", customers[index].customer_name);
    printf("\nBalance: %.2f", customers[index].balance);
    printf("\nLast Transaction: %s\n", customers[index].last_transaction);
}

void updateAccount() {
    int account_number, index = -1;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i=0; i<count; i++) {
        if(customers[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nAccount not found!\n");
        return;
    }
    printf("\nEnter Amount to Deposit/Withdraw: ");
    scanf("%f", &amount);
    printf("\nEnter 1 for deposit and 2 for withdraw: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1) {
        customers[index].balance += amount;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(customers[index].last_transaction, "%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("\nDeposit Successful!\n");
    } else if(choice == 2) {
        if(customers[index].balance < amount) {
            printf("\nInsufficient Balance!\n");
            return;
        }
        customers[index].balance -= amount;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(customers[index].last_transaction, "%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("\nWithdrawal Successful!\n");
    } else {
        printf("\nInvalid Choice!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n*********Welcome to C Banking Record System*********\n");
        printf("\n1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Update Account\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAllAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                updateAccount();
                break;
            case 5:
                printf("\n*********Thank you for using C Banking Record System*********\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while(choice != 5);
    return 0;
}