//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    char address[MAX_RECORD_SIZE];
    char account_number[MAX_RECORD_SIZE];
    int account_balance;
    struct Record* next;
} Record;

Record* insert_record(Record* head, char* name, char* address, char* account_number, int account_balance) {
    Record* new_record = malloc(sizeof(Record));
    new_record->next = NULL;

    strcpy(new_record->name, name);
    strcpy(new_record->address, address);
    strcpy(new_record->account_number, account_number);
    new_record->account_balance = account_balance;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }

    return head;
}

int main() {
    Record* head = NULL;
    head = insert_record(head, "John Doe", "123 Main St.", "123456", 1000);
    head = insert_record(head, "Jane Doe", "456 Oak Ave.", "548213", 2000);
    head = insert_record(head, "Bob Smith", "789 Park Ave.", "362874", 3000);

    Record* current_record = head;
    while (current_record) {
        printf("Name: %s\n", current_record->name);
        printf("Address: %s\n", current_record->address);
        printf("Account Number: %s\n", current_record->account_number);
        printf("Account Balance: %d\n", current_record->account_balance);
        printf("\n");

        current_record = current_record->next;
    }

    return 0;
}