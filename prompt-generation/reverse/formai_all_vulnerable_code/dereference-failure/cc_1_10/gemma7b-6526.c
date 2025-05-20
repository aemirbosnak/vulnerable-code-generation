//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: cheerful
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

// Function to insert a new banking record at the end
void insert_record(BankingRecord** head) {
    BankingRecord* new_record = (BankingRecord*)malloc(sizeof(BankingRecord));
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

// Function to print all banking records
void print_records(BankingRecord* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account number: %d\n", head->account_number);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main() {
    BankingRecord* head = NULL;

    // Insert some banking records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Print all banking records
    print_records(head);

    return 0;
}