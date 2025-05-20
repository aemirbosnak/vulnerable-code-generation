//FormAI DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank account record
struct record {
    int account_number;
    char name[50];
    int balance;
};

int main() {
    int n;
    printf("Welcome to the Unique C Banking Record System\n");
    printf("How many records would you like to enter? ");
    scanf("%d", &n);

    // initialize array of bank account records
    struct record* bank_records = malloc(n * sizeof(struct record));

    // get input from user for each bank account record
    for (int i = 0; i < n; i++) {
        printf("\nRecord #%d\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &bank_records[i].account_number);
        printf("Name: ");
        scanf("%s", bank_records[i].name);
        printf("Balance: ");
        scanf("%d", &bank_records[i].balance);
    }

    // print out all bank account records
    printf("\nBank Account Records\n");
    for (int i = 0; i < n; i++) {
        printf("------------\n");
        printf("Record #%d\n", i + 1);
        printf("Account Number: %d\n", bank_records[i].account_number);
        printf("Name: %s\n", bank_records[i].name);
        printf("Balance: %d\n", bank_records[i].balance);
    }

    // get input from user to search for a specific bank account record
    int search_account_number;
    printf("\nEnter an account number to search for: ");
    scanf("%d", &search_account_number);
    for (int i = 0; i < n; i++) {
        if (bank_records[i].account_number == search_account_number) {
            printf("------------\n");
            printf("Record #%d\n", i + 1);
            printf("Account Number: %d\n", bank_records[i].account_number);
            printf("Name: %s\n", bank_records[i].name);
            printf("Balance: %d\n", bank_records[i].balance);
            break;
        }
        if (i == n - 1) {
            printf("\nRecord with account number %d not found.\n", search_account_number);
        }
    }

    // sort bank account records by balance in descending order
    struct record temp;
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (bank_records[i].balance < bank_records[i + 1].balance) {
                temp = bank_records[i];
                bank_records[i] = bank_records[i + 1];
                bank_records[i + 1] = temp;
                sorted = 0;
            }
        }
    }

    // print out bank account records sorted by balance in descending order
    printf("\nBank Account Records (Sorted by Balance in Descending Order)\n");
    for (int i = 0; i < n; i++) {
        printf("------------\n");
        printf("Record #%d\n", i + 1);
        printf("Account Number: %d\n", bank_records[i].account_number);
        printf("Name: %s\n", bank_records[i].name);
        printf("Balance: %d\n", bank_records[i].balance);
    }

    // free memory allocated for bank account records array
    free(bank_records);

    printf("\nThank you for using the Unique C Banking Record System!");
    return 0;
}