//FormAI DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_ENTRIES 10

struct PasswordEntry {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct PasswordVault {
    int numEntries;
    struct PasswordEntry entries[MAX_ENTRIES];
};

void clear() {
    printf("\033[H\033[J");
}

void encrypt(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] += i % 3 + 1;
    }
}

void decrypt(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] -= i % 3 + 1;
    }
}

void addEntry(struct PasswordVault* vault) {
    clear();
    printf("Enter a new username: ");
    scanf("%s", vault->entries[vault->numEntries].username);
    printf("Enter a new password: ");
    scanf("%s", vault->entries[vault->numEntries].password);
    encrypt(vault->entries[vault->numEntries].username);
    encrypt(vault->entries[vault->numEntries].password);
    vault->numEntries++;
    clear();
    printf("New entry added successfully.\n\n");
}

void removeEntry(struct PasswordVault* vault) {
    clear();
    char username[MAX_USERNAME_LENGTH];
    printf("Enter the username of the entry to remove: ");
    scanf("%s", username);
    for (int i = 0; i < vault->numEntries; i++) {
        char tempUsername[MAX_USERNAME_LENGTH];
        strcpy(tempUsername, vault->entries[i].username);
        decrypt(tempUsername);
        if (strcmp(tempUsername, username) == 0) {
            int j;
            for (j = i; j < vault->numEntries - 1; j++) {
                memcpy(&vault->entries[j], &vault->entries[j+1], sizeof(struct PasswordEntry));
            }
            memset(&vault->entries[j], 0, sizeof(struct PasswordEntry));
            vault->numEntries--;
            clear();
            printf("Entry removed successfully.\n\n");
            return;
        }
    }
    clear();
    printf("Entry not found.\n\n");
}

void viewEntries(struct PasswordVault* vault) {
    clear();
    printf("--- Password Vault ---\n\n");
    for (int i = 0; i < vault->numEntries; i++) {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        strcpy(username, vault->entries[i].username);
        strcpy(password, vault->entries[i].password);
        decrypt(username);
        decrypt(password);
        printf("%d. %s: %s\n", i+1, username, password);
    }
    printf("\n");
}

void menu() {
    printf("--- Password Manager ---\n\n");
    printf("1. Add entry\n");
    printf("2. Remove entry\n");
    printf("3. View entries\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

int main() {
    struct PasswordVault vault = {0};
    int choice = 0;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(&vault);
                break;
            case 2:
                removeEntry(&vault);
                break;
            case 3:
                viewEntries(&vault);
                break;
            case 4:
                clear();
                printf("Goodbye.\n");
                return 0;
            default:
                clear();
                printf("Invalid choice.\n\n");
                break;
        }
    } while (1);

    return 0;
}