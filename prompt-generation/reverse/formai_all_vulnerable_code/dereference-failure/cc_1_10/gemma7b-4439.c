//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store banking records
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record at the end
void insert_bank_record(BankRecord** head) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
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
    *head = new_record;
}

// Function to search for a bank record by account number
BankRecord* search_bank_record(BankRecord* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(BankRecord* head, int account_number, double new_balance) {
    BankRecord* record = search_bank_record(head, account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a bank record
void delete_bank_record(BankRecord* head, int account_number) {
    BankRecord* previous = NULL;
    BankRecord* current = head;

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
    BankRecord* head = NULL;

    // Insert some bank records
    insert_bank_record(&head);
    insert_bank_record(&head);
    insert_bank_record(&head);

    // Search for a bank record
    BankRecord* record = search_bank_record(head, 1234);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %lf\n", record->balance);
    }

    // Update the balance of a bank record
    update_balance(head, 1234, 1000);
    record = search_bank_record(head, 1234);
    if (record) {
        printf("New Balance: %lf\n", record->balance);
    }

    // Delete a bank record
    delete_bank_record(head, 1234);
    record = search_bank_record(head, 1234);
    if (record) {
        printf("Record not found.\n");
    }

    return 0;
}