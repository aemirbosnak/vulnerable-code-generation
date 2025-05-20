//FormAI DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    int account_number;
    char name[50];
    float balance;
};

void add_record(struct customer *, int *);
void display_records(struct customer *, int);
void search_record(struct customer *, int);
void delete_record(struct customer *, int *);

int main() {
    int choice, num_records = 0;
    struct customer *records = NULL;

    while (1) {
        printf("===== Welcome to the C Banking Record System =====\n");
        printf("1. Add a Record\n");
        printf("2. Display all Records\n");
        printf("3. Search for a Record\n");
        printf("4. Delete a Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                search_record(records, num_records);
                break;
            case 4:
                delete_record(records, &num_records);
                break;
            case 5:
                printf("Thank you for using the C Banking Record System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

void add_record(struct customer *records, int *num_records){
    char name[50];
    float balance;

    if (*num_records == 0) {
        records = (struct customer *) malloc(sizeof(struct customer));
    } else {
        records = (struct customer *) realloc(records, (*num_records + 1) * sizeof(struct customer));
    }

    printf("Enter customer name: ");
    scanf(" %[^\n]%*c", name);
    printf("Enter account number: ");
    scanf("%d", &records[*num_records].account_number);
    strcpy(records[*num_records].name, name);
    printf("Enter account balance: ");
    scanf("%f", &balance);
    records[*num_records].balance = balance;

    printf("Record added successfully!\n");
    (*num_records)++;
}

void display_records(struct customer *records, int num_records){
    if (records == NULL || num_records == 0) {
        printf("No records found!\n");
    } else {
        printf("Account Number\tName\tBalance\n");
        for (int i = 0; i < num_records; i++) {
            printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
        }
    }
}

void search_record(struct customer *records, int num_records){
    int account_number, i;

    if (records == NULL || num_records == 0) {
        printf("No records found!\n");
    } else {
        printf("Enter account number to search for: ");
        scanf("%d", &account_number);

        for (i = 0; i < num_records; i++) {
            if (account_number == records[i].account_number) {
                printf("Account Holder Name: %s\n", records[i].name);
                printf("Account Balance: %.2f\n", records[i].balance);
                break;
            }
        }

        if (i == num_records) {
            printf("Record not found!\n");
        }
    }
}

void delete_record(struct customer *records, int *num_records){
    int account_number, i, j;

    if (records == NULL || *num_records == 0) {
        printf("No records found!\n");
    } else {
        printf("Enter account number to delete: ");
        scanf("%d", &account_number);

        for (i = 0; i < *num_records; i++) {
            if (account_number == records[i].account_number) {
                for (j = i; j < *num_records - 1; j++) {
                    records[j] = records[j + 1];
                }
                (*num_records)--;
                printf("Record deleted successfully!\n");
                break;
            }
        }

        if (i == *num_records) {
            printf("Record not found!\n");
        }
    }
}