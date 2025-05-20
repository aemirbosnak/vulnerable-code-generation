//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
};

typedef struct Record Record;

void insert(Record** head, char* name, int account_number, double balance) {
    Record* new_record = malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void search(Record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_number);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }
    printf("Record not found\n");
}

int main() {
    Record* head = NULL;

    insert(&head, "John Doe", 12345, 1000.0);
    insert(&head, "Jane Doe", 67890, 2000.0);
    insert(&head, "Peter Pan", 32146, 3000.0);

    search(head, 12345);
    search(head, 67890);

    return 0;
}