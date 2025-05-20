//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct bank_record {
    char name[20];
    int account_no;
    double balance;
    struct bank_record *next;
};

void deposit(struct bank_record *ptr) {
    double amount;
    printf("Enter the amount you want to deposit: ");
    scanf("%lf", &amount);
    ptr->balance += amount;
    printf("Your new balance is: $%.2lf", ptr->balance);
}

void withdraw(struct bank_record *ptr) {
    double amount;
    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= ptr->balance) {
        ptr->balance -= amount;
        printf("Your new balance is: $%.2lf", ptr->balance);
    } else {
        printf("Insufficient funds!");
    }
}

int main() {
    struct bank_record *head = NULL;
    struct bank_record *ptr = NULL;

    // Create a new bank record
    ptr = (struct bank_record *)malloc(sizeof(struct bank_record));
    ptr->name[0] = '\0';
    ptr->account_no = 1234;
    ptr->balance = 1000.0;
    ptr->next = NULL;

    // Add the new bank record to the head of the list
    if (head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head = ptr;
    }

    // Menu options
    int choice;
    printf("Please select an option:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    // Switch case for menu options
    switch (choice) {
        case 1:
            deposit(head);
            break;
        case 2:
            withdraw(head);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid option!");
    }

    return 0;
}