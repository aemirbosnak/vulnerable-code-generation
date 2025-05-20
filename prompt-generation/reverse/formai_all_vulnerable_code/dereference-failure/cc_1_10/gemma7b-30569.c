//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <string.h>

struct BankRecord {
    char name[50];
    int accountNo;
    double balance;
    struct BankRecord *next;
};

void insertRecord(struct BankRecord **head) {
    struct BankRecord *newRecord = (struct BankRecord *)malloc(sizeof(struct BankRecord));
    printf("Enter name: ");
    scanf("%s", newRecord->name);
    printf("Enter account number: ");
    scanf("%d", &newRecord->accountNo);
    printf("Enter balance: ");
    scanf("%lf", &newRecord->balance);
    newRecord->next = *head;
    *head = newRecord;
}

void displayRecords(struct BankRecord *head) {
    while (head) {
        printf("%s, %d, %.2lf\n", head->name, head->accountNo, head->balance);
        head = head->next;
    }
}

int main() {
    struct BankRecord *head = NULL;
    int choice;

    printf("Welcome to the Banking Record System!\n");
    printf("1. Insert Record\n");
    printf("2. Display Records\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertRecord(&head);
            break;
        case 2:
            displayRecords(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}