//FormAI DATASET v1.0 Category: Banking Record System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bank_record {
    char name[20];
    int account_no;
    float balance;
    struct bank_record* next;
} account;

account* head = NULL;

void insert_record(char name[], int acc_no, float bal) {
    account* temp = (account*)malloc(sizeof(account));
    strcpy(temp->name, name);
    temp->account_no = acc_no;
    temp->balance = bal;

    if (head == NULL) {
        head = temp;
        temp->next = NULL;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void display_record() {
    account* temp = head;
    while (temp != NULL) {
        printf("\n\nName: %s", temp->name);
        printf("\nAccount No.: %d", temp->account_no);
        printf("\nBalance: %.2f", temp->balance);
        temp = temp->next;
    }
}

int main() {
    int choice, acc_no;
    float balance;
    char name[20];

    do {
        printf("\n\n----- Bank Record System -----\n");
        printf("\n1. Insert record\n2. Display record\n3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter Name: ");
            scanf("%s", name);
            printf("\nEnter Account No.: ");
            scanf("%d", &acc_no);
            printf("\nEnter Balance: ");
            scanf("%f", &balance);
            insert_record(name, acc_no, balance);
            printf("\nRecord inserted sucessfully!");
            break;
        case 2:
            display_record();
            break;
        case 3:
            printf("\nThank you! Goodbye!");
            return 0;
            break;
        default:
            printf("\nInvalid choice! Please try again.");
            break;
        }
    } while (choice != 3);
    return 0;
}