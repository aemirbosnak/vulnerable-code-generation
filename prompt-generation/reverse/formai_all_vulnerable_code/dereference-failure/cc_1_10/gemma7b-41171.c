//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank records
struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
};

// Function to insert a new bank record at the end
void insert_bank_record(struct bank_record** head) {
    struct bank_record* new_record = (struct bank_record*)malloc(sizeof(struct bank_record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }

    new_record->next = NULL;
}

// Function to search for a bank record by account number
struct bank_record* search_bank_record(struct bank_record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the balance of a bank record
void update_bank_record(struct bank_record* head, int account_number, double new_balance) {
    struct bank_record* record = search_bank_record(head, account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a bank record by account number
void delete_bank_record(struct bank_record* head, int account_number) {
    struct bank_record* previous = NULL;
    struct bank_record* current = head;

    while (current) {
        if (current->account_number == account_number) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            current = NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    struct bank_record* head = NULL;

    // Insert some bank records
    insert_bank_record(&head);
    insert_bank_record(&head);
    insert_bank_record(&head);

    // Search for a bank record by account number
    struct bank_record* record = search_bank_record(head, 12345);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Update the balance of a bank record
    update_bank_record(head, 12345, 1000.0);
    record = search_bank_record(head, 12345);
    if (record) {
        printf("Updated balance: %.2lf\n", record->balance);
    }

    // Delete a bank record by account number
    delete_bank_record(head, 12345);
    record = search_bank_record(head, 12345);
    if (record) {
        printf("Deleted balance: %.2lf\n", record->balance);
    }

    return 0;
}