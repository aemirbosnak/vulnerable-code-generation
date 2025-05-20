//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: interoperable
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

// Function to insert a bank record at the end
void insert_at_end(bank_record** head, char* name, int account_number, double balance) {
    bank_record* new_record = malloc(sizeof(bank_record));
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

// Function to search for a bank record
bank_record* search(bank_record* head, int account_number) {
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
    bank_record* record = search(head, account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a bank record
void delete_record(bank_record* head, int account_number) {
    bank_record* previous = NULL;
    bank_record* current = head;

    while (current) {
        if (current->account_number == account_number) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    return;
}

int main() {
    bank_record* head = NULL;

    // Insert some bank records
    insert_at_end(&head, "John Doe", 123456, 1000.0);
    insert_at_end(&head, "Jane Doe", 654912, 2000.0);
    insert_at_end(&head, "Peter Pan", 321698, 3000.0);

    // Search for a bank record
    bank_record* record = search(head, 123456);

    // Update the balance of a bank record
    update_balance(head, 654912, 2500.0);

    // Delete a bank record
    delete_record(head, 321698);

    // Print the bank records
    for (record = head; record; record = record->next) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", record->name, record->account_number, record->balance);
    }

    return 0;
}