//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank records
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Create a linked list of bank records
BankRecord* head = NULL;

// Function to insert a new bank record at the end
void insert_record(char* name, int account_number, double balance) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
        head = new_record;
    }
}

// Function to search for a bank record by account number
BankRecord* search_record(int account_number) {
    BankRecord* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            return current_record;
        }
        current_record = current_record->next;
    }

    return NULL;
}

// Function to update the balance of a bank record
void update_balance(int account_number, double new_balance) {
    BankRecord* record = search_record(account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to withdraw money from a bank record
void withdraw(int account_number, double amount) {
    BankRecord* record = search_record(account_number);

    if (record) {
        if (amount <= record->balance) {
            record->balance -= amount;
        } else {
            printf("Insufficient funds.");
        }
    } else {
        printf("Account not found.");
    }
}

// Main function
int main() {
    insert_record("John Doe", 123456, 1000.0);
    insert_record("Jane Doe", 654912, 500.0);
    insert_record("Peter Pan", 321549, 200.0);

    update_balance(123456, 1500.0);
    withdraw(654912, 200.0);

    BankRecord* record = search_record(321549);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    } else {
        printf("Account not found.");
    }

    return 0;
}