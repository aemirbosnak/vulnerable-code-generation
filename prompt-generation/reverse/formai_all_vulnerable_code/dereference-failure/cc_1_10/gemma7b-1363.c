//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank record data
typedef struct BankRecord {
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new bank record at the end
void insert_at_end(BankRecord** head, char* name, int account_no, double balance) {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

// Function to search for a bank record by account number
BankRecord* search_by_account_no(BankRecord* head, int account_no) {
    while (head) {
        if (head->account_no == account_no) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(BankRecord* head, int account_no, double new_balance) {
    BankRecord* record = search_by_account_no(head, account_no);
    if (record) {
        record->balance = new_balance;
    }
}

// Main function
int main() {
    BankRecord* head = NULL;

    // Insert some bank records
    insert_at_end(&head, "John Doe", 123456, 1000.0);
    insert_at_end(&head, "Jane Doe", 654321, 2000.0);
    insert_at_end(&head, "Peter Pan", 321468, 3000.0);

    // Search for a bank record by account number
    BankRecord* record = search_by_account_no(head, 123456);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Update the balance of a bank record
    update_balance(head, 654321, 2500.0);
    record = search_by_account_no(head, 654321);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %.2lf\n", record->balance);
    }

    return 0;
}