//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank records
struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
};

// Function to insert a new bank record at the end
void insert_at_end(struct bank_record** head, char* name, int account_number, double balance) {
    struct bank_record* new_record = (struct bank_record*)malloc(sizeof(struct bank_record));
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
struct bank_record* search_by_account_number(struct bank_record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(struct bank_record* head, int account_number, double new_balance) {
    struct bank_record* record = search_by_account_number(head, account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to print all bank records
void print_records(struct bank_record* head) {
    while (head) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main() {
    struct bank_record* head = NULL;

    // Insert some bank records
    insert_at_end(&head, "John Doe", 123456, 1000.0);
    insert_at_end(&head, "Jane Doe", 654321, 2000.0);
    insert_at_end(&head, "Peter Pan", 321468, 3000.0);

    // Search for a bank record by account number
    struct bank_record* record = search_by_account_number(head, 123456);
    if (record) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", record->name, record->account_number, record->balance);
    }

    // Update the balance of a bank record
    update_balance(head, 654321, 2500.0);

    // Print all bank records
    print_records(head);

    return 0;
}