//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define a structure to store bank record data
typedef struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Create a function to insert a bank record into the linked list
void insert_record(BankRecord** head, char* name, int account_number, double balance) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
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

// Create a function to search for a bank record by account number
BankRecord* search_record(BankRecord* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Create a function to update the balance of a bank record
void update_balance(BankRecord* head, int account_number, double new_balance) {
    BankRecord* record = search_record(head, account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Main function
int main() {
    BankRecord* head = NULL;

    // Insert some bank records
    insert_record(&head, "John Doe", 123456, 1000.0);
    insert_record(&head, "Jane Doe", 654321, 2000.0);
    insert_record(&head, "Bill Smith", 984123, 3000.0);

    // Search for a bank record by account number
    BankRecord* record = search_record(head, 123456);

    // Print the balance of the bank record
    if (record) {
        printf("Balance: %f", record->balance);
    } else {
        printf("Record not found");
    }

    // Update the balance of a bank record
    update_balance(head, 654321, 2500.0);

    // Search for the updated bank record
    record = search_record(head, 654321);

    // Print the updated balance of the bank record
    if (record) {
        printf("Updated balance: %f", record->balance);
    } else {
        printf("Record not found");
    }

    return 0;
}