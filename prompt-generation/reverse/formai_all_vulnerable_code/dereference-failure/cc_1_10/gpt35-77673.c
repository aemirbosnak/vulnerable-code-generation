//FormAI DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char name[50];
    int accountNumber;
    double balance;
    struct Record *next;
} record;

record *head = NULL;
record *tail = NULL;

void addRecord(char *name, int accountNumber, double balance) {
    record *newRecord = (record*)malloc(sizeof(record));

    strcpy(newRecord->name, name);
    newRecord->accountNumber = accountNumber;
    newRecord->balance = balance;

    newRecord->next = NULL;

    if(head == NULL) {
        head = newRecord;
        tail = newRecord;
    } else {
        tail->next = newRecord;
        tail = newRecord;
    }
}

void displayRecords() {
    record *current = head;

    printf("\n\n=== BANKING RECORDS ===\n\n");

    while(current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->accountNumber);
        printf("Balance: %.2f\n\n", current->balance);

        current = current->next;
    }
}

void searchRecord(char *name) {
    record *current = head;
    int found = 0;

    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("\n\n=== RECORD FOUND ===\n\n");
            printf("Name: %s\n", current->name);
            printf("Account Number: %d\n", current->accountNumber);
            printf("Balance: %.2f\n\n", current->balance);
            found = 1;
            break;
        }

        current = current->next;
    }

    if(!found) printf("\n\n=== RECORD NOT FOUND ===\n\n");
}

void deleteRecord(char *name) {
    record *current = head;
    record *prev = NULL;
    int found = 0;

    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("\n\n=== RECORD DELETED ===\n\n");
            printf("Name: %s\n", current->name);
            printf("Account Number: %d\n", current->accountNumber);
            printf("Balance: %.2f\n\n", current->balance);

            if(current == head) {
                head = head->next;
            } else if(current == tail) {
                tail = prev;
                tail->next = NULL;
            } else {
                prev->next = current->next;
            }

            free(current);
            found = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    if(!found) printf("\n\n=== RECORD NOT FOUND ===\n\n");
}

int main() {
    int choice, accountNumber;
    char name[50];
    double balance;

    do {
        printf("=== BANKING RECORD SYSTEM ===\n\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Balance: ");
                scanf("%lf", &balance);

                addRecord(name, accountNumber, balance);
                break;

            case 2:
                displayRecords();
                break;

            case 3:
                printf("\nEnter Name: ");
                scanf("%s", name);
                searchRecord(name);
                break;

            case 4:
                printf("\nEnter Name: ");
                scanf("%s", name);
                deleteRecord(name);
                break;

            case 5:
                printf("\nGoodbye!\n\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }
    } while(choice != 5);

    return 0;
}