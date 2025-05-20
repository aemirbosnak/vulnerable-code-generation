//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank records
struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
};

// Create a singly linked list to store bank records
struct bank_record* head = NULL;

// Function to insert a new bank record into the linked list
void insert_record(char* name, int account_number, double balance) {
    // Allocate memory for the new bank record
    struct bank_record* new_record = (struct bank_record*)malloc(sizeof(struct bank_record));

    // Copy the name, account number, and balance into the new bank record
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;

    // If the linked list is empty, make the new bank record the head
    if (head == NULL) {
        head = new_record;
    } else {
        // Traverse the linked list until the last bank record is reached
        struct bank_record* current_record = head;
        while (current_record->next != NULL) {
            current_record = current_record->next;
        }

        // Insert the new bank record after the last bank record
        current_record->next = new_record;
    }
}

// Function to search for a bank record
struct bank_record* search_record(int account_number) {
    // Traverse the linked list to find the bank record with the specified account number
    struct bank_record* current_record = head;
    while (current_record) {
        if (current_record->account_number == account_number) {
            return current_record;
        }
        current_record = current_record->next;
    }

    // Return NULL if the bank record is not found
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(int account_number, double new_balance) {
    // Search for the bank record with the specified account number
    struct bank_record* record = search_record(account_number);

    // If the bank record is found, update its balance
    if (record) {
        record->balance = new_balance;
    }
}

// Function to print the bank records
void print_records() {
    // Traverse the linked list and print each bank record
    struct bank_record* current_record = head;
    while (current_record) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current_record->name, current_record->account_number, current_record->balance);
        current_record = current_record->next;
    }
}

int main() {
    // Insert some bank records
    insert_record("John Doe", 123456, 1000.0);
    insert_record("Jane Doe", 654321, 2000.0);
    insert_record("Bill Smith", 984123, 3000.0);

    // Print the bank records
    print_records();

    // Update the balance of a bank record
    update_balance(123456, 2000.0);

    // Print the bank records after the balance update
    print_records();

    return 0;
}