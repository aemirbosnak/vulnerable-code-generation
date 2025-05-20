//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank record data
typedef struct bank_record {
    char name[50];
    int account_no;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new bank record into the linked list
void insert_record(bank_record** head, bank_record* new_record) {
    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
        *head = new_record;
    }
}

// Function to search for a bank record by account number
bank_record* search_record(bank_record* head, int account_no) {
    while (head) {
        if (head->account_no == account_no) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the balance of a bank record
void update_balance(bank_record* record, double new_balance) {
    record->balance = new_balance;
}

// Function to print the bank records
void print_records(bank_record* head) {
    while (head) {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}

int main() {
    // Create a linked list of bank records
    bank_record* head = NULL;

    // Insert some sample bank records
    insert_record(&head, malloc(sizeof(bank_record)));
    insert_record(&head, malloc(sizeof(bank_record)));
    insert_record(&head, malloc(sizeof(bank_record)));

    // Search for a bank record by account number
    bank_record* record = search_record(head, 12345);

    // Update the balance of the bank record
    if (record) {
        update_balance(record, 1000);
    }

    // Print the bank records
    print_records(head);

    return 0;
}