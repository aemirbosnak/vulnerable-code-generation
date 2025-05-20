//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank records
typedef struct bank_record {
    char name[50];
    int account_no;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new bank record at the end
void insert_bank_record(bank_record* head) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    scanf("Enter name: ", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }

    new_record->next = NULL;
}

// Function to search for a bank record by account number
bank_record* search_bank_record(bank_record* head, int account_no) {
    bank_record* current_record = head;

    while (current_record) {
        if (current_record->account_no == account_no) {
            return current_record;
        }
        current_record = current_record->next;
    }

    return NULL;
}

// Function to update a bank record
void update_bank_record(bank_record* head, int account_no) {
    bank_record* current_record = search_bank_record(head, account_no);

    if (current_record) {
        printf("Enter new balance: ");
        scanf("%lf", &current_record->balance);
    } else {
        printf("Record not found.\n");
    }
}

// Function to delete a bank record
void delete_bank_record(bank_record* head, int account_no) {
    bank_record* current_record = search_bank_record(head, account_no);

    if (current_record) {
        bank_record* previous_record = NULL;

        if (current_record == head) {
            head = current_record->next;
        } else {
            previous_record = current_record->next;
            previous_record->next = current_record->next;
        }

        free(current_record);
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    bank_record* head = NULL;

    // Insert some bank records
    insert_bank_record(head);
    insert_bank_record(head);
    insert_bank_record(head);

    // Search for a bank record
    bank_record* record = search_bank_record(head, 123);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_no);
        printf("Balance: %lf\n", record->balance);
    }

    // Update a bank record
    update_bank_record(head, 123);

    // Delete a bank record
    delete_bank_record(head, 123);

    return 0;
}