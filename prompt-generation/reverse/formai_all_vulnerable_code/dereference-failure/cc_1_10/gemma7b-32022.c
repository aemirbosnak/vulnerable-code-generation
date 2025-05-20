//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Banking Record structure
typedef struct BankingRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Function to insert a new Banking Record into the head of the list
BankingRecord* insert_at_head(BankingRecord* head, char* name, int account_number, double balance) {
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }

    return head;
}

// Function to search for a Banking Record by account number
BankingRecord* search_by_account_number(BankingRecord* head, int account_number) {
    BankingRecord* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            return current_record;
        }
        current_record = current_record->next;
    }

    return NULL;
}

// Function to update the balance of a Banking Record
void update_balance(BankingRecord* record, double new_balance) {
    record->balance = new_balance;
}

// Main function
int main() {
    BankingRecord* head = NULL;

    // Insert some sample Banking Records
    insert_at_head(head, "John Doe", 123456, 1000.0);
    insert_at_head(head, "Jane Doe", 654912, 2000.0);
    insert_at_head(head, "Bill Smith", 321548, 3000.0);

    // Search for a Banking Record by account number
    BankingRecord* record = search_by_account_number(head, 123456);

    // If the record is found, update its balance
    if (record) {
        update_balance(record, 2500.0);
    }

    // Print the updated balance
    record = search_by_account_number(head, 123456);
    printf("The updated balance for account number %d is $%.2lf", record->account_number, record->balance);

    return 0;
}