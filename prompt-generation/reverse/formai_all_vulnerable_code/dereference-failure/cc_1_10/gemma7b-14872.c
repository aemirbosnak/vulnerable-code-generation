//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store banking records
typedef struct BankRecord {
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new record at the end
void insert_record(BankRecord* head, char* name, int account_no, double balance) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }
}

// Function to search for a record
BankRecord* search_record(BankRecord* head, int account_no) {
    BankRecord* current = head;
    while (current) {
        if (current->account_no == account_no) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update a record
void update_record(BankRecord* head, int account_no, double new_balance) {
    BankRecord* record = search_record(head, account_no);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a record
void delete_record(BankRecord* head, int account_no) {
    BankRecord* previous = NULL;
    BankRecord* current = head;
    while (current) {
        if (current->account_no == account_no) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    return;
}

int main() {
    BankRecord* head = NULL;

    // Insert some records
    insert_record(head, "John Doe", 12345, 1000);
    insert_record(head, "Jane Doe", 67890, 2000);
    insert_record(head, "Peter Pan", 32146, 3000);

    // Search for a record
    BankRecord* record = search_record(head, 12345);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %f\n", record->balance);
    }

    // Update a record
    update_record(head, 67890, 2500);
    record = search_record(head, 67890);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %f\n", record->balance);
    }

    // Delete a record
    delete_record(head, 32146);
    record = search_record(head, 32146);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %f\n", record->balance);
    }

    return 0;
}