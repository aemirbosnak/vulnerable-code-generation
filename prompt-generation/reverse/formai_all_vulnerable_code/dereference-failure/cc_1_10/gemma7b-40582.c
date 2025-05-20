//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a bank record
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a bank record into the head of a linked list
void insert_record(bank_record** head, char* name, int account_number, double balance) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
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

// Function to search for a bank record by account number
bank_record* search_record(bank_record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the balance of a bank record
void update_balance(bank_record* head, int account_number, double new_balance) {
    bank_record* record = search_record(head, account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to print all bank records
void print_records(bank_record* head) {
    while (head) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main() {
    bank_record* head = NULL;

    // Insert some bank records
    insert_record(&head, "Sherlock Holmes", 123456, 1000.0);
    insert_record(&head, "John Watson", 654321, 2000.0);
    insert_record(&head, "Dr. Watson", 481239, 3000.0);

    // Search for a bank record by account number
    bank_record* record = search_record(head, 123456);

    // Update the balance of a bank record
    update_balance(head, 654321, 2500.0);

    // Print all bank records
    print_records(head);

    return 0;
}