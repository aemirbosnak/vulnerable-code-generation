//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <string.h>

// Define a structure to store banking records
typedef struct BankingRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord *next;
} BankingRecord;

// Function to insert a new banking record at the end
void insert_record(BankingRecord **head) {
    BankingRecord *new_record = (BankingRecord *)malloc(sizeof(BankingRecord));
    printf("Enter your name: ");
    scanf("%s", new_record->name);
    printf("Enter your account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter your initial balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
    (*head)->next = NULL;
}

// Function to search for a banking record by account number
BankingRecord *search_record(BankingRecord *head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the balance of a banking record
void update_balance(BankingRecord *record, double new_balance) {
    record->balance = new_balance;
}

// Function to delete a banking record
void delete_record(BankingRecord *head, int account_number) {
    BankingRecord *prev = NULL;
    BankingRecord *curr = head;

    while (curr) {
        if (curr->account_number == account_number) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Record not found.\n");
}

int main() {
    BankingRecord *head = NULL;

    // Insert a few banking records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a banking record by account number
    BankingRecord *record = search_record(head, 1234);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    // Update the balance of a banking record
    update_balance(record, 1000);

    // Delete a banking record
    delete_record(head, 1234);

    // Print the updated list of banking records
    BankingRecord *curr = head;
    while (curr) {
        printf("Name: %s\n", curr->name);
        printf("Account Number: %d\n", curr->account_number);
        printf("Balance: %.2lf\n", curr->balance);
        printf("\n");
        curr = curr->next;
    }

    return 0;
}