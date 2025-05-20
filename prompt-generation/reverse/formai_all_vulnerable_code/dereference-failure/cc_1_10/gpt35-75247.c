//FormAI DATASET v1.0 Category: Banking Record System ; Style: recursive
// A recursive banking record system using linked list data structure
#include<stdio.h>
#include<stdlib.h>

// Structure definition for banking record
struct bankRecord {
    int account_no;
    char name[50];
    int balance;
    struct bankRecord* next;
};

// Function to insert new record or update the existing record
struct bankRecord* insertOrUpdate(struct bankRecord* head, int account_no, char* name, int balance) {
    if(head == NULL) {
        struct bankRecord* record = (struct bankRecord*)malloc(sizeof(struct bankRecord));
        record->account_no = account_no;
        strcpy(record->name, name);
        record->balance = balance;
        record->next = NULL;
        return record;
    }
    else if(head->account_no == account_no) {
        head->balance += balance;
        printf("Account %d updated successfully!\n", account_no);
        return head;
    }
    else if(head->next == NULL) {
        struct bankRecord* record = (struct bankRecord*)malloc(sizeof(struct bankRecord));
        record->account_no = account_no;
        strcpy(record->name, name);
        record->balance = balance;
        record->next = NULL;
        head->next = record;
        printf("New account %d added successfully!\n", account_no);
        return head;
    }
    else {
        head->next = insertOrUpdate(head->next, account_no, name, balance);
        return head;
    }
}

// Function to display the bank records
void displayRecords(struct bankRecord* head) {
    if(head == NULL) {
        printf("No records found!\n");
        return;
    }
    struct bankRecord* current = head;
    printf("Account No.\tName\t\tBalance\n");
    while(current != NULL) {
        printf("%d\t\t%s\t\t%d\n", current->account_no, current->name, current->balance);
        current = current->next;
    }
}

// Main function to test the program
int main() {
    struct bankRecord* head = NULL;
    int choice, account_no, balance;
    char name[50];

    do {
        printf("\n1. Add new record");
        printf("\n2. Update existing record");
        printf("\n3. Display all records");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter account no : ");
                scanf("%d", &account_no);
                printf("Enter name : ");
                scanf("%s", name);
                printf("Enter balance : ");
                scanf("%d", &balance);
                head = insertOrUpdate(head, account_no, name, balance);
                break;
            case 2:
                printf("\nEnter account no : ");
                scanf("%d", &account_no);
                printf("Enter balance : ");
                scanf("%d", &balance);
                head = insertOrUpdate(head, account_no, "", balance);
                break;
            case 3:
                displayRecords(head);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 4);

    return 0;
}