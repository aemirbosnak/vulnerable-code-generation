//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: intelligent
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

// Function to insert a new bank record at the end
void insert_at_end(bank_record** head) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    new_record->next = NULL;

    // If the head of the list is NULL, make the new record the first node
    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
        *head = new_record;
    }
}

// Function to search for a bank record by account number
bank_record* search_by_account_number(bank_record* head, int account_number) {
    bank_record* current = head;

    // Iterate over the list until the record is found or the end of the list is reached
    while (current) {
        if (current->account_number == account_number) {
            return current;
        }
        current = current->next;
    }

    // Return NULL if the record is not found
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(bank_record* record, double new_balance) {
    record->balance = new_balance;
}

// Function to print the bank records
void print_records(bank_record* head) {
    bank_record* current = head;

    // Iterate over the list and print each record
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main() {
    // Create a linked list of bank records
    bank_record* head = NULL;

    // Insert some sample records
    insert_at_end(&head);
    insert_at_end(&head);
    insert_at_end(&head);

    // Search for a record by account number
    bank_record* record = search_by_account_number(head, 123);

    // Update the balance of the record
    if (record) {
        update_balance(record, 1000);
    }

    // Print the bank records
    print_records(head);

    return 0;
}