//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 20

struct account {
    char name[MAX_NAME_LENGTH];
    int balance;
};

int main() {
    FILE *file;
    int num_accounts = 0;
    char input[MAX_NAME_LENGTH + MAX_AMOUNT_LENGTH + 10];
    char *name, *amount;
    int balance;

    // Open the file
    file = fopen("accounts.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in the accounts
    while (fscanf(file, "%s %s %d", input, name, amount)!= EOF) {
        balance = atoi(amount);
        strcpy(input, name);
        strcat(input, " ");
        strcat(input, amount);
        printf("%s\n", input);
        num_accounts++;
    }

    fclose(file);

    // Open the file for writing
    file = fopen("accounts.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write the accounts
    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account name: ");
        scanf("%s", input);
        strcpy(input, " ");
        strcat(input, input);
        printf("Enter account balance: ");
        scanf("%s", input);
        strcpy(input, " ");
        strcat(input, input);
        fprintf(file, "%s\n", input);
    }

    fclose(file);

    printf("Done.\n");

    return 0;
}