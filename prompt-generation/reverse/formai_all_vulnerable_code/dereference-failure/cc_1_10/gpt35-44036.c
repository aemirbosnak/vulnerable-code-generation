//FormAI DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Account;

void addAccountToFile(Account account, FILE* fp) {
    fprintf(fp, "%s:%s\n", account.username, account.password);
}

void displayAccount(Account account) {
    printf("Username: %s\n", account.username);
    printf("Password: %s\n", account.password);
}

void displayAllAccountsInFile(FILE* fp) {
    printf("All Accounts:\n");
    char line[PASSWORD_LENGTH + MAX_USERNAME_LENGTH + 2]; // Account information line
    while (fgets(line, PASSWORD_LENGTH + MAX_USERNAME_LENGTH + 2, fp) != NULL) {
        // Split line into username and password using the ':' separator
        char* token = strtok(line, ":");
        Account account;
        // Copy username and password into Account struct
        strncpy(account.username, token, MAX_USERNAME_LENGTH);
        token = strtok(NULL, ":"); // Get password token
        strncpy(account.password, token, PASSWORD_LENGTH);
        // Display account
        displayAccount(account);
    }
}

void addAccountToFilePrompt(FILE* fp) {
    Account account;
    printf("Enter username: ");
    scanf("%s", account.username);
    printf("Enter password: ");
    scanf("%s", account.password);
    addAccountToFile(account, fp);
    printf("Account added successfully!\n");
}

int main() {
    FILE* fp = fopen("passwords.db", "a+"); // Open file or create if it doesn't exist
    if (fp == NULL) {
        printf("Error opening password file!");
        exit(1);
    }
    int choice;
    do {
        printf("Password Manager Menu\n");
        printf("1. Add account\n");
        printf("2. Display all accounts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAccountToFilePrompt(fp);
                break;
            case 2:
                displayAllAccountsInFile(fp);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
    fclose(fp);
    return 0;
}