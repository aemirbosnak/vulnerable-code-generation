//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Define the Banking Record System (BRS) structure
typedef struct brs {
    char name[50];
    int account_number;
    double balance;
    struct brs* next;
} brs;

// Function to insert a new record into the BRS
void insert_record(brs* head, char* name, int account_number, double balance) {
    brs* new_record = malloc(sizeof(brs));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }
}

// Function to search for a record in the BRS
brs* search_record(brs* head, int account_number) {
    brs* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            return current_record;
        }
        current_record = current_record->next;
    }

    return NULL;
}

// Function to update a record in the BRS
void update_record(brs* head, int account_number, double new_balance) {
    brs* record = search_record(head, account_number);

    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a record from the BRS
void delete_record(brs* head, int account_number) {
    brs* previous_record = NULL;
    brs* current_record = head;

    while (current_record) {
        if (current_record->account_number == account_number) {
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                head = current_record->next;
            }
            free(current_record);
            return;
        }
        previous_record = current_record;
        current_record = current_record->next;
    }

    return;
}

int main() {
    brs* head = NULL;

    insert_record(head, "Romeo", 1234, 1000);
    insert_record(head, "Juliet", 5678, 2000);
    insert_record(head, "Benvolio", 9841, 3000);

    update_record(head, 1234, 2000);

    delete_record(head, 5678);

    brs* record = search_record(head, 1234);

    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %f\n", record->balance);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}