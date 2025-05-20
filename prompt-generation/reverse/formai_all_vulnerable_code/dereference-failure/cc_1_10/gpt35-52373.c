//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

/**
 * Data structure to hold password information.
 */
typedef struct {
    char website[50];
    char username[50];
    char password[50];
} Password;

/**
 * Get password from user input.
 */
void get_password(Password *p) {
    printf("Enter website: ");
    scanf("%s", p->website);

    printf("Enter username: ");
    scanf("%s", p->username);

    printf("Enter password: ");
    scanf("%s", p->password);
}

/**
 * Check password strength based on length and characters.
 */
bool is_strong(char *password) {
    int length = strlen(password);
    bool uppercase = false;
    bool lowercase = false;
    bool digit = false;
    bool special = false;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = true;
        } else if (islower(password[i])) {
            lowercase = true;
        } else if (isdigit(password[i])) {
            digit = true;
        } else {
            special = true;
        }
    }

    return (length >= 8 && uppercase && lowercase && digit && special);
}

/**
 * Store password to file.
 */
void store_password(Password p) {
    FILE *file = fopen("passwords.txt", "a");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    fprintf(file, "%s %s %s\n", p.website, p.username, p.password);
    fclose(file);
}

/**
 * Main function to handle user input and operations.
 */
int main() {
    printf("Welcome to Password Manager!\n\n");

    while (true) {
        printf("1. Add password\n");
        printf("2. Search password\n");
        printf("3. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {  // Add password
            Password p;
            get_password(&p);

            if (is_strong(p.password)) {
                store_password(p);
                printf("\nPassword added successfully!\n\n");
            } else {
                printf("\nPassword is not strong enough.\n");
                printf("Password must contain at least 8 characters including\n");
                printf("lowercase letter, uppercase letter, digit, and special character.\n\n");
            }
        } else if (choice == 2) {  // Search password
            char website[50];
            printf("Enter website to search: ");
            scanf("%s", website);

            FILE *file = fopen("passwords.txt", "r");

            if (file == NULL) {
                printf("Error: could not open file.\n");
                continue;
            }

            char line[150];
            bool found = false;

            while (fgets(line, sizeof(line), file)) {
                char *token = strtok(line, " ");
                Password p;

                strcpy(p.website, token);
                token = strtok(NULL, " ");

                strcpy(p.username, token);
                token = strtok(NULL, " ");

                strcpy(p.password, token);
                token = strtok(NULL, " ");

                if (strcmp(p.website, website) == 0) {
                    printf("\nWebsite: %s\n", p.website);
                    printf("Username: %s\n", p.username);
                    printf("Password: %s\n\n", p.password);
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("\nPassword not found.\n\n");
            }

            fclose(file);
        } else if (choice == 3) {  // Exit
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Error: invalid choice.\n\n");
        }
    }

    return 0;
}