//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct account *next;
} Account;

Account *passwords = NULL;

Account *createAccount(char *username, char *password) {
    Account *newAccount = malloc(sizeof(Account));
    strcpy(newAccount->username, username);
    strcpy(newAccount->password, password);
    newAccount->next = NULL;
    return newAccount;
}

void addAccount(char *username, char *password) {
    if (passwords == NULL) {
        passwords = createAccount(username, password);
    } else {
        Account *currentAccount = passwords;
        while (currentAccount->next != NULL) {
            currentAccount = currentAccount->next;
        }
        currentAccount->next = createAccount(username, password);
    }
    printf("Account added successfully.\n");
}

void printAccounts() {
    if (passwords == NULL) {
        printf("No accounts saved.\n");
    } else {
        Account *currentAccount = passwords;
        printf("Accounts:\n");
        while (currentAccount != NULL) {
            printf("Username: %s, Password: %s\n", currentAccount->username, currentAccount->password);
            currentAccount = currentAccount->next;
        }
    }
}

void deleteAccount(char *username) {
    if (passwords == NULL) {
        printf("No accounts saved.\n");
    } else {
        Account *currentAccount = passwords;
        Account *previousAccount = NULL;
        while (currentAccount != NULL) {
            if (strcmp(currentAccount->username, username) == 0) {
                if (previousAccount == NULL) {
                    passwords = currentAccount->next;
                } else {
                    previousAccount->next = currentAccount->next;
                }
                free(currentAccount);
                printf("Account deleted successfully.\n");
                return;
            }
            previousAccount = currentAccount;
            currentAccount = currentAccount->next;
        }
        printf("Account not found.\n");
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int choice = 0;

    while (choice != 4) {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add account\n");
        printf("2. Print accounts\n");
        printf("3. Delete account\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                addAccount(username, password);
                break;
            case 2:
                printAccounts();
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                deleteAccount(username);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}