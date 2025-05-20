//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bank record data
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new bank record at the end
void insert_at_end(bank_record** head) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
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
bank_record* search_by_account_number(bank_record* head, int account_number) {
    bank_record* current = head;
    while (current) {
        if (current->account_number == account_number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update the balance of a bank record
void update_balance(bank_record* record, double new_balance) {
    record->balance = new_balance;
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
        }
        previous = current;
        current = current->next;
    }
    return;
}

int main() {
    bank_record* head = NULL;
    int choice;
    int account_number;
    double new_balance;

    // Loop until the user chooses to exit
    while (1) {
        printf("Enter 1 to insert a new bank record, 2 to search by account number, 3 to update balance, or 4 to delete a record: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_at_end(&head);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                bank_record* record = search_by_account_number(head, account_number);
                if (record) {
                    printf("Name: %s\n", record->name);
                    printf("Account number: %d\n", record->account_number);
                    printf("Balance: %.2lf\n", record->balance);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                record = search_by_account_number(head, account_number);
                if (record) {
                    printf("Enter new balance: ");
                    scanf("%lf", &new_balance);
                    update_balance(record, new_balance);
                    printf("Balance updated.\n");
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                record = search_by_account_number(head, account_number);
                if (record) {
                    delete_record(head, account_number);
                    printf("Record deleted.\n");
                } else {
                    printf("Record not found.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Enter 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
    }

    return 0;
}