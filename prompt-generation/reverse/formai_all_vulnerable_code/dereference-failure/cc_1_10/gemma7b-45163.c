//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of records
#define MAX_RECORDS 10

// Define the record structure
typedef struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

// Function to insert a new record
void insert_record(Record** head) {
    // Allocate memory for the new record
    Record* new_record = (Record*)malloc(sizeof(Record));

    // Get the record details from the user
    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    // Insert the new record into the linked list
    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }

    // Print a confirmation message
    printf("Record inserted successfully.\n");
}

// Function to search for a record
void search_record(Record* head) {
    // Get the account number of the record to search for
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Search for the record
    Record* current_record = head;
    while (current_record) {
        if (current_record->account_number == account_number) {
            // Print the record details
            printf("Name: %s\n", current_record->name);
            printf("Account number: %d\n", current_record->account_number);
            printf("Balance: %lf\n", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    // If the record is not found, print an error message
    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

// Function to update a record
void update_record(Record* head) {
    // Get the account number of the record to update
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Search for the record
    Record* current_record = head;
    while (current_record) {
        if (current_record->account_number == account_number) {
            // Get the new record details from the user
            printf("Enter new name: ");
            scanf("%s", current_record->name);

            printf("Enter new account number: ");
            scanf("%d", &current_record->account_number);

            printf("Enter new balance: ");
            scanf("%lf", &current_record->balance);

            // Print a confirmation message
            printf("Record updated successfully.\n");
            break;
        }
        current_record = current_record->next;
    }

    // If the record is not found, print an error message
    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

// Function to delete a record
void delete_record(Record* head) {
    // Get the account number of the record to delete
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Search for the record
    Record* current_record = head;
    Record* previous_record = NULL;
    while (current_record) {
        if (current_record->account_number == account_number) {
            // If the record is the first record, update the head of the linked list
            if (previous_record == NULL) {
                head = current_record->next;
            } else {
                previous_record->next = current_record->next;
            }

            // Free the memory occupied by the record
            free(current_record);

            // Print a confirmation message
            printf("Record deleted successfully.\n");
            break;
        }
        previous_record = current_record;
        current_record = current_record->next;
    }

    // If the record is not found, print an error message
    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    // Create a linked list of records
    Record* head = NULL;

    // Insert some records
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);

    // Search for a record
    search_record(head);

    // Update a record
    update_record(head);

    // Delete a record
    delete_record(head);

    return 0;
}