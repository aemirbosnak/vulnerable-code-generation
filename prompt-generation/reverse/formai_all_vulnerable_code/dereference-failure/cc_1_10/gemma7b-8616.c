//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <string.h>

// Define the Banking Record System structure
typedef struct BankingRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Function to insert a new banking record into the system
void insert_record(BankingRecord** head, char* name, int account_number, double balance) {
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));
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

// Function to search for a banking record by account number
BankingRecord* search_record(BankingRecord* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the balance of a banking record
void update_balance(BankingRecord* head, int account_number, double new_balance) {
    BankingRecord* record = search_record(head, account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a banking record
void delete_record(BankingRecord* head, int account_number) {
    BankingRecord* previous = NULL;
    BankingRecord* current = head;

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
    BankingRecord* head = NULL;

    // Insert some banking records
    insert_record(&head, "John Doe", 123456, 1000);
    insert_record(&head, "Jane Doe", 654321, 2000);
    insert_record(&head, "Peter Pan", 321468, 3000);

    // Search for a banking record by account number
    BankingRecord* record = search_record(head, 123456);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Update the balance of a banking record
    update_balance(head, 654321, 2500);
    record = search_record(head, 654321);
    if (record) {
        printf("Updated Balance: %.2lf\n", record->balance);
    }

    // Delete a banking record
    delete_record(head, 321468);
    record = search_record(head, 321468);
    if (record) {
        printf("Deleted Balance: %.2lf\n", record->balance);
    }

    return 0;
}