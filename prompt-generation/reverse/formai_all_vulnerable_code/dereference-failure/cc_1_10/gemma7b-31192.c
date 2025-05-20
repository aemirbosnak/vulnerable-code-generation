//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct BankRecord {
    char name[20];
    int account_no;
    double balance;
} BankRecord;

void create_record(BankRecord **records, int *num_records) {
    *records = (BankRecord *)malloc((*num_records) * sizeof(BankRecord));
    (*num_records)++;
}

void deposit(BankRecord *records, int num_records) {
    char name[20];
    int account_no;
    double amount;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter account number: ");
    scanf("%d", &account_no);

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0 && records[i].account_no == account_no) {
            records[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(BankRecord *records, int num_records) {
    char name[20];
    int account_no;
    double amount;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter account number: ");
    scanf("%d", &account_no);

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0 && records[i].account_no == account_no) {
            if (records[i].balance - amount >= 0) {
                records[i].balance -= amount;
                printf("Withdrawal successful.\n");
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }

    printf("Account not found.\n");
}

void view_records(BankRecord *records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_no);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("\n");
    }
}

int main() {
    BankRecord *records = NULL;
    int num_records = 0;

    char choice;

    while (1) {
        printf("Enter choice: (D/W/V/C) ");
        scanf("%c", &choice);

        switch (choice) {
            case 'D':
                deposit(records, &num_records);
                break;
            case 'W':
                withdraw(records, num_records);
                break;
            case 'V':
                view_records(records, num_records);
                break;
            case 'C':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}