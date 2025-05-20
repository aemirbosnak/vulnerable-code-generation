//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank records
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Create a linked list to store bank records
bank_record* head = NULL;

// Function to insert a new bank record into the linked list
void insert_record(char* name, int account_number, double balance) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }
}

// Function to search for a bank record by account number
bank_record* search_record(int account_number) {
    bank_record* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            return current_record;
        }
        current_record = current_record->next;
    }

    return NULL;
}

// Function to update the balance of a bank record
void update_balance(int account_number, double new_balance) {
    bank_record* record = search_record(account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a bank record
void delete_record(int account_number) {
    bank_record* previous_record = NULL;
    bank_record* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                head = current_record->next;
            }
            free(current_record);
            return;
        }
        previous_record = current_record;
        current_record = current_record->next;
    }

    return;
}

int main() {
    insert_record("John Doe", 123456, 1000.0);
    insert_record("Jane Doe", 654321, 2000.0);
    insert_record("Peter Pan", 321468, 3000.0);

    bank_record* record = search_record(123456);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    update_balance(123456, 2000.0);

    record = search_record(123456);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    delete_record(654321);

    record = search_record(654321);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    return 0;
}