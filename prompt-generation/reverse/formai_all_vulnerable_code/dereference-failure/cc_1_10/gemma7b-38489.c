//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
};

void insert_record(struct BankRecord** head, char* name, int account_number, double balance) {
    struct BankRecord* new_record = malloc(sizeof(struct BankRecord));
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

void search_record(struct BankRecord* head, int account_number) {
    struct BankRecord* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            printf("Name: %s\n", current_record->name);
            printf("Account Number: %d\n", current_record->account_number);
            printf("Balance: %.2lf\n", current_record->balance);
            return;
        }
        current_record = current_record->next;
    }

    printf("Record not found.\n");
}

int main() {
    struct BankRecord* head = NULL;

    insert_record(&head, "John Doe", 123456, 1000.0);
    insert_record(&head, "Jane Doe", 654321, 2000.0);
    insert_record(&head, "Peter Pan", 984123, 3000.0);

    search_record(head, 123456);
    search_record(head, 654321);
    search_record(head, 984123);

    return 0;
}