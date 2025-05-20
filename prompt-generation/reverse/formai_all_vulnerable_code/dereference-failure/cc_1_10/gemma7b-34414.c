//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define the structure of a bank record
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new bank record at the end
void insert_at_end(bank_record** head, char* name, int account_number, double balance) {
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
bank_record* search_by_account_number(bank_record* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(bank_record* head, int account_number, double new_balance) {
    bank_record* record = search_by_account_number(head, account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Main function
int main() {
    bank_record* head = NULL;

    // Insert some bank records
    insert_at_end(&head, "John Doe", 123456, 1000);
    insert_at_end(&head, "Jane Doe", 654923, 2000);
    insert_at_end(&head, "Peter Pan", 321468, 3000);

    // Search for a bank record by account number
    bank_record* record = search_by_account_number(head, 123456);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Update the balance of a bank record
    update_balance(head, 654923, 2500);
    record = search_by_account_number(head, 654923);
    if (record) {
        printf("Updated Balance: %.2lf\n", record->balance);
    }

    return 0;
}