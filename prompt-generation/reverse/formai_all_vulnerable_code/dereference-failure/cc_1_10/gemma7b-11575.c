//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store banking records
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    char transaction_type;
    double amount;
    struct bank_record* next;
} bank_record;

// Function to insert a new banking record at the end
void insert_record(bank_record** head) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
    printf("Enter transaction type: ");
    scanf(" %c", &new_record->transaction_type);
    printf("Enter amount: ");
    scanf("%lf", &new_record->amount);

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }

    new_record->next = NULL;
}

// Function to display all banking records
void display_records(bank_record* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account number: %d\n", head->account_number);
        printf("Balance: %.2lf\n", head->balance);
        printf("Transaction type: %c\n", head->transaction_type);
        printf("Amount: %.2lf\n", head->amount);
        printf("\n");
        head = head->next;
    }
}

int main() {
    bank_record* head = NULL;

    // Insert some banking records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Display all banking records
    display_records(head);

    return 0;
}