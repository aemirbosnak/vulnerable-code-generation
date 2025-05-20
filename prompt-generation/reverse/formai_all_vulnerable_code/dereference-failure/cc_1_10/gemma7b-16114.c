//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

void insert_record(Record* head) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }
}

void search_record(Record* head) {
    char search_name[50];
    printf("Enter name: ");
    scanf("%s", search_name);

    Record* current_record = head;
    while (current_record) {
        if (strcmp(search_name, current_record->name) == 0) {
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

void update_record(Record* head) {
    char update_name[50];
    printf("Enter name: ");
    scanf("%s", update_name);

    Record* current_record = head;
    while (current_record) {
        if (strcmp(update_name, current_record->name) == 0) {
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

void delete_record(Record* head) {
    char delete_name[50];
    printf("Enter name: ");
    scanf("%s", delete_name);

    Record* current_record = head;
    Record* previous_record = NULL;

    while (current_record) {
        if (strcmp(delete_name, current_record->name) == 0) {
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
    Record* head = NULL;

    int choice;
    printf("1. Insert Record\n");
    printf("2. Search Record\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insert_record(head);
            break;
        case 2:
            search_record(head);
            break;
        case 3:
            update_record(head);
            break;
        case 4:
            delete_record(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}