//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// structure to hold account information
struct account {
    int accountNumber;
    char name[50];
    float balance;
};

// function to add new account to the record
void addRecord(struct account *records, int *count) {
    printf("Enter account number: ");
    scanf("%d", &records[*count].accountNumber);
    getchar(); // to clear buffer
    printf("Enter name: ");
    fgets(records[*count].name, 50, stdin);
    // remove trailing new line character
    records[*count].name[strcspn(records[*count].name, "\n")] = 0;
    printf("Enter balance: ");
    scanf("%f", &records[*count].balance);
    (*count)++; // increment count
    printf("Account added successfully!\n");
}

// function to display all records
void displayAllRecords(struct account *records, int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    printf("--------------------------------\n");
    printf("Accounts Record\n");
    printf("--------------------------------\n");
    printf("Account Number\tName\tBalance\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", records[i].accountNumber, records[i].name, records[i].balance);
    }
    printf("--------------------------------\n");
}

// function to search account by account number
void searchByAccountNumber(struct account *records, int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    int accountNumber;
    printf("Enter account number to search: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++) {
        if (records[i].accountNumber == accountNumber) {
            printf("Account found!\n");
            printf("Account Number\tName\tBalance\n");
            printf("--------------------------------\n");
            printf("%d\t%s\t%.2f\n", records[i].accountNumber, records[i].name, records[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// function to search account by name
void searchByName(struct account *records, int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    char name[50];
    printf("Enter name to search: ");
    getchar(); // to clear buffer
    fgets(name, 50, stdin);
    // remove trailing new line character
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    printf("Accounts found with name %s:\n", name);
    printf("Account Number\tName\tBalance\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("%d\t%s\t%.2f\n", records[i].accountNumber, records[i].name, records[i].balance);
            found = 1;
        }
    }
    if (!found) {
        printf("No accounts found with name %s.\n", name);
    }
}

// function to deposit to account
void deposit(struct account *records, int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    int accountNumber;
    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++) {
        if (records[i].accountNumber == accountNumber) {
            float amount;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            records[i].balance += amount; // add amount to balance
            printf("Deposited %.2f to account %d successfully!\n", amount, accountNumber);
            return;
        }
    }
    printf("Account not found! Deposit failed.\n");
}

// function to withdraw from account
void withdraw(struct account *records, int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    int accountNumber;
    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++) {
        if (records[i].accountNumber == accountNumber) {
            float amount;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= records[i].balance) {
                records[i].balance -= amount; // subtract amount from balance
                printf("Withdrawn %.2f from account %d successfully!\n", amount, accountNumber);
            } else {
                printf("Insufficient balance! Withdraw failed.\n");
            }
            return;
        }
    }
    printf("Account not found! Withdraw failed.\n");
}

// main function
int main() {
    system("clear"); // clear screen on program start
    printf("Welcome to Paranoid Banking Records System!\n");
    printf("--------------------------------------------\n");

    // allocate memory for records
    struct account *records = (struct account*)malloc(100*sizeof(struct account));
    int count = 0; // count will keep track of number of records

    while (1) {
        printf("\n1. Add record\n");
        printf("2. Display all records\n");
        printf("3. Search account by account number\n");
        printf("4. Search account by name\n");
        printf("5. Deposit to account\n");
        printf("6. Withdraw from account\n");
        printf("7. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                displayAllRecords(records, count);
                break;
            case 3:
                searchByAccountNumber(records, count);
                break;
            case 4:
                searchByName(records, count);
                break;
            case 5:
                deposit(records, count);
                break;
            case 6:
                withdraw(records, count);
                break;
            case 7:
                free(records); // free allocated memory
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}