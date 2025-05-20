//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store banking records
typedef struct bank_record {
    char name[50];
    int account_no;
    double balance;
    struct bank_record* next;
} bank_record;

// Function to insert a new record at the end
void insert_record(bank_record* head) {
    bank_record* new_record = (bank_record*)malloc(sizeof(bank_record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }
    new_record->next = NULL;
}

// Function to search for a record
void search_record(bank_record* head) {
    char search_name[50];
    int search_account_no;

    printf("Enter name: ");
    scanf("%s", search_name);

    printf("Enter account number: ");
    scanf("%d", &search_account_no);

    bank_record* current_record = head;
    while (current_record) {
        if (strcmp(current_record->name, search_name) == 0 && current_record->account_no == search_account_no) {
            printf("Name: %s\n", current_record->name);
            printf("Account Number: %d\n", current_record->account_no);
            printf("Balance: %.2lf\n", current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

// Function to update a record
void update_record(bank_record* head) {
    char update_name[50];
    int update_account_no;

    printf("Enter name: ");
    scanf("%s", update_name);

    printf("Enter account number: ");
    scanf("%d", &update_account_no);

    bank_record* current_record = head;
    while (current_record) {
        if (strcmp(current_record->name, update_name) == 0 && current_record->account_no == update_account_no) {
            printf("Enter new balance: ");
            scanf("%lf", &current_record->balance);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

// Function to delete a record
void delete_record(bank_record* head) {
    char delete_name[50];
    int delete_account_no;

    printf("Enter name: ");
    scanf("%s", delete_name);

    printf("Enter account number: ");
    scanf("%d", &delete_account_no);

    bank_record* current_record = head;
    bank_record* previous_record = NULL;

    while (current_record) {
        if (strcmp(current_record->name, delete_name) == 0 && current_record->account_no == delete_account_no) {
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                head = current_record->next;
            }
            free(current_record);
            break;
        }
        previous_record = current_record;
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    bank_record* head = NULL;

    // Insert some records
    insert_record(head);
    insert_record(head);
    insert_record(head);

    // Search for a record
    search_record(head);

    // Update a record
    update_record(head);

    // Delete a record
    delete_record(head);

    // Search for the updated record
    search_record(head);

    return 0;
}