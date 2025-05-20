//FormAI DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 3

typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

typedef struct {
    Password* passwords;
    int size;
    int capacity;
} PasswordManager;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* getPasswordFromUser() {
    char* password = malloc(sizeof(char) * MAX_PASSWORD_LENGTH);
    int length = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF && length < MAX_PASSWORD_LENGTH - 1) {
        if (!isspace(c)) {
            password[length++] = c;
        }
    }
    password[length] = '\0';
    return password;
}

void printPassword(Password password) {
    printf("Website: %s\n", password.website);
    printf("Username: %s\n", password.username);
    printf("Password: %s\n", password.password);
}

void printPasswords(PasswordManager* manager) {
    printf("Passwords:\n");
    for (int i = 0; i < manager->size; i++) {
        printPassword(manager->passwords[i]);
    }
}

void addPassword(PasswordManager* manager) {
    if (manager->size == manager->capacity) {
        manager->capacity *= 2;
        manager->passwords = realloc(manager->passwords, sizeof(Password) * manager->capacity);
    }
    Password new_password;
    printf("Enter website: ");
    fgets(new_password.website, sizeof(new_password.website), stdin);
    new_password.website[strcspn(new_password.website, "\n")] = '\0';
    printf("Enter username: ");
    fgets(new_password.username, sizeof(new_password.username), stdin);
    new_password.username[strcspn(new_password.username, "\n")] = '\0';
    printf("Enter password: ");
    char* password = getPasswordFromUser();
    strncpy(new_password.password, password, MAX_PASSWORD_LENGTH);
    free(password);
    manager->passwords[manager->size++] = new_password;
    printf("\nPassword added successfully!\n");
}

void removePassword(PasswordManager* manager) {
    printf("Enter website to delete: ");
    char website[50];
    fgets(website, sizeof(website), stdin);
    website[strcspn(website, "\n")] = '\0';
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(manager->passwords[i].website, website) == 0) {
            for (int j = i + 1; j < manager->size; j++) {
                manager->passwords[j - 1] = manager->passwords[j];
            }
            manager->size--;
            printf("\nPassword deleted successfully!\n");
            return;
        }
    }
    printf("\nWebsite not found!\n");
}

void changePassword(PasswordManager* manager) {
    printf("Enter website to change password: ");
    char website[50];
    fgets(website, sizeof(website), stdin);
    website[strcspn(website, "\n")] = '\0';
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(manager->passwords[i].website, website) == 0) {
            printf("Enter new password: ");
            char* password = getPasswordFromUser();
            strncpy(manager->passwords[i].password, password, MAX_PASSWORD_LENGTH);
            free(password);
            printf("\nPassword changed successfully!\n");
            return;
        }
    }
    printf("\nWebsite not found!\n");
}

void viewPassword(PasswordManager* manager) {
    printf("Enter website to view password: ");
    char website[50];
    fgets(website, sizeof(website), stdin);
    website[strcspn(website, "\n")] = '\0';
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(manager->passwords[i].website, website) == 0) {
            printPassword(manager->passwords[i]);
            return;
        }
    }
    printf("\nWebsite not found!\n");
}

void savePasswordsToFile(PasswordManager* manager) {
    FILE* fout = fopen("passwords.txt", "w");
    for (int i = 0; i < manager->size; i++) {
        fprintf(fout, "%s, %s, %s\n", manager->passwords[i].website,
                                      manager->passwords[i].username,
                                      manager->passwords[i].password);
    }
    fclose(fout);
    printf("\nPasswords saved to file!\n");
}

void readPasswordsFromFile(PasswordManager* manager) {
    FILE* fin = fopen("passwords.txt", "r");
    if (fin) {
        char line[100];
        while (fgets(line, sizeof(line), fin)) {
            char* website = strtok(line, ",");
            char* username = strtok(NULL, ",");
            char* password = strtok(NULL, ",");
            Password new_password;
            strcpy(new_password.website, website);
            strcpy(new_password.username, username);
            strcpy(new_password.password, password);
            manager->passwords[manager->size++] = new_password;
        }
        fclose(fin);
        printf("\nPasswords loaded from file!\n");
    } else {
        printf("\nCannot open file!\n");
    }
}

void printMenu() {
    printf("Menu:\n");
    printf("1. Add password\n");
    printf("2. Remove password\n");
    printf("3. Change password\n");
    printf("4. View password\n");
    printf("5. Print passwords\n");
    printf("6. Save passwords to file\n");
    printf("7. Load passwords from file\n");
    printf("8. Exit\n");
}

int main() {
    PasswordManager manager;
    manager.size = 0;
    manager.capacity = 1;
    manager.passwords = malloc(sizeof(Password) * manager.capacity);

    int choice = 0;
    while (1) {
        printMenu();
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input!\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                addPassword(&manager);
                break;
            case 2:
                removePassword(&manager);
                break;
            case 3:
                changePassword(&manager);
                break;
            case 4:
                viewPassword(&manager);
                break;
            case 5:
                printPasswords(&manager);
                break;
            case 6:
                savePasswordsToFile(&manager);
                break;
            case 7:
                readPasswordsFromFile(&manager);
                break;
            case 8:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}