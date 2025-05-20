//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank record
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Create a linked list of bank records
bank_record* create_bank_record(char* name, int account_number, double balance) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;
    return new_record;
}

// Insert a bank record into the linked list
void insert_bank_record(bank_record* head, bank_record* new_record) {
    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }
}

// Print all bank records
void print_bank_records(bank_record* head) {
    bank_record* current_record = head;
    while (current_record) {
        printf("%s, %d, %lf\n", current_record->name, current_record->account_number, current_record->balance);
        current_record = current_record->next;
    }
}

// Main function
int main() {
    // Create a linked list of bank records
    bank_record* head = NULL;

    // Insert some bank records
    insert_bank_record(head, create_bank_record("John Doe", 123456, 1000.0));
    insert_bank_record(head, create_bank_record("Jane Doe", 654321, 2000.0));
    insert_bank_record(head, create_bank_record("Peter Pan", 984213, 3000.0));

    // Print all bank records
    print_bank_records(head);

    return 0;
}