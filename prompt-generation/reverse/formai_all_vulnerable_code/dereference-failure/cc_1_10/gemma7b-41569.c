//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    char account_number[20];
    int account_balance;
    struct Record* next;
} Record;

void add_record(Record* head) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%s", new_record->account_number);
    printf("Enter account balance: ");
    scanf("%d", &new_record->account_balance);
    new_record->next = head;
    head = new_record;
}

void display_records(Record* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account number: %s\n", head->account_number);
        printf("Account balance: %d\n", head->account_balance);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Record* head = NULL;
    char choice;

    while (1) {
        printf("Enter choice: (A)dd, (D)isplay, (E)xit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                add_record(head);
                break;
            case 'D':
                display_records(head);
                break;
            case 'E':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}