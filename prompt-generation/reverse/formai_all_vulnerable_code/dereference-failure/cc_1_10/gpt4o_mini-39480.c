//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char *website;
    char *username;
    char *password;
} Credential;

typedef struct {
    Credential *credentials;
    int count;
    int capacity;
} PasswordManager;

void initPasswordManager(PasswordManager *manager) {
    manager->count = 0;
    manager->capacity = INITIAL_CAPACITY;
    manager->credentials = (Credential *)malloc(manager->capacity * sizeof(Credential));
}

void freePasswordManager(PasswordManager *manager) {
    for (int i = 0; i < manager->count; i++) {
        free(manager->credentials[i].website);
        free(manager->credentials[i].username);
        free(manager->credentials[i].password);
    }
    free(manager->credentials);
}

void addCredential(PasswordManager *manager, const char *website, const char *username, const char *password) {
    if (manager->count >= manager->capacity) {
        manager->capacity *= 2;
        manager->credentials = (Credential *)realloc(manager->credentials, manager->capacity * sizeof(Credential));
    }
    manager->credentials[manager->count].website = strdup(website);
    manager->credentials[manager->count].username = strdup(username);
    manager->credentials[manager->count].password = strdup(password);
    manager->count++;
    printf("Credential added for %s.\n", website);
}

void displayCredentials(const PasswordManager *manager) {
    printf("\nStored Credentials:\n");
    for (int i = 0; i < manager->count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", manager->credentials[i].website, manager->credentials[i].username, manager->credentials[i].password);
    }
}

void deleteCredential(PasswordManager *manager, const char *website) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->credentials[i].website, website) == 0) {
            free(manager->credentials[i].website);
            free(manager->credentials[i].username);
            free(manager->credentials[i].password);
            for (int j = i; j < manager->count - 1; j++) {
                manager->credentials[j] = manager->credentials[j + 1];
            }
            manager->count--;
            printf("Deleted credential for %s.\n", website);
            return;
        }
    }
    printf("No credential found for %s.\n", website);
}

int main() {
    PasswordManager manager;
    initPasswordManager(&manager);

    int choice;
    char website[MAX_LENGTH], username[MAX_LENGTH], password[MAX_LENGTH];

    while (1) {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add Credential\n");
        printf("2. View Credentials\n");
        printf("3. Delete Credential\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter website: ");
                fgets(website, MAX_LENGTH, stdin);
                website[strcspn(website, "\n")] = 0; // Remove newline
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                addCredential(&manager, website, username, password);
                break;
            case 2:
                displayCredentials(&manager);
                break;
            case 3:
                printf("Enter website to delete: ");
                fgets(website, MAX_LENGTH, stdin);
                website[strcspn(website, "\n")] = 0; // Remove newline
                deleteCredential(&manager, website);
                break;
            case 4:
                freePasswordManager(&manager);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}