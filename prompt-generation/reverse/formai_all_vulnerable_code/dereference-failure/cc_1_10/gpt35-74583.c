//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h> //standard input-output library
#include <stdlib.h> //library for allocating memory
#include <string.h> //library for string operations

#define MAX_ACCOUNTS 100 //maximum number of accounts in the system

//structure for a bank account
typedef struct bankAccount {
    int accountNumber;
    char name[50];
    float balance;
} Account;

//function prototype declarations
void createAccount(Account *accounts);
void displayAccount(Account *accounts, int accountNumber);
void deposit(Account *accounts, int accountNumber, float amount);
void withdraw(Account *accounts, int accountNumber, float amount);

int main() {
    Account *accounts = (Account*) malloc(MAX_ACCOUNTS * sizeof(Account)); //allocate memory for maximum number of accounts
    
    int choice = 0; //menu choice variable

    while(choice != 5) {
        printf("------Main Menu------\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                printf("Enter account number: ");
                int accountNumber;
                scanf("%d", &accountNumber);
                displayAccount(accounts, accountNumber);
                break;
            case 3:
                printf("Enter account number: ");
                int accountNum;
                scanf("%d", &accountNum);
                printf("Enter amount to be deposited: ");
                float amt;
                scanf("%f", &amt);
                deposit(accounts, accountNum, amt);
                break;
            case 4:
                printf("Enter account number: ");
                int accountNo;
                scanf("%d", &accountNo);
                printf("Enter amount to be withdrawn: ");
                float amnt;
                scanf("%f", &amnt);
                withdraw(accounts, accountNo, amnt);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(accounts); //free the allocated memory
    return 0;
}

//function to create a new account
void createAccount(Account *accounts) {
    int flag = -1; //flag to indicate if account number already exists
    int i;
    for(i=0;i<MAX_ACCOUNTS;i++) {
        if(accounts[i].accountNumber != 0) {
            if(i == (MAX_ACCOUNTS - 1)) {
                printf("Maximum number of accounts reached.\n");
                return;
            }
            continue;
        } else {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("Enter account number: ");
        scanf("%d", &accounts[i].accountNumber);
        printf("Enter name: ");
        scanf("%s", accounts[i].name);
        printf("Enter initial balance: ");
        scanf("%f", &accounts[i].balance);
        printf("Account created successfully.\n");
    }
}

//function to display an account
void displayAccount(Account *accounts, int accountNumber) {
    int flag = -1; //flag to indicate if account number exists
    int i;
    for(i=0;i<MAX_ACCOUNTS;i++) {
        if(accounts[i].accountNumber == accountNumber) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
    } else {
        printf("Account not found.\n");
    }
}

//function to deposit money into an account
void deposit(Account *accounts, int accountNumber, float amount) {
    int flag = -1; //flag to indicate if account number exists
    int i;
    for(i=0;i<MAX_ACCOUNTS;i++) {
        if(accounts[i].accountNumber == accountNumber) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        accounts[i].balance += amount;
        printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
    } else {
        printf("Account not found.\n");
    }
}

//function to withdraw money from an account
void withdraw(Account *accounts, int accountNumber, float amount) {
    int flag = -1; //flag to indicate if account number exists
    int i;
    for(i=0;i<MAX_ACCOUNTS;i++) {
        if(accounts[i].accountNumber == accountNumber) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        if(amount > accounts[i].balance) {
            printf("Insufficient balance.\n");
            return;
        }
        accounts[i].balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
    } else {
        printf("Account not found.\n");
    }
}