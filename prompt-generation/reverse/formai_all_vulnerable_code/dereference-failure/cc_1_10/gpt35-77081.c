//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void createNewUser() {
    User newUser;

    printf("Enter your username (maximum of 20 characters): ");
    scanf("%s", newUser.username);
    printf("Enter your password (maximum of 20 characters): ");
    scanf("%s", newUser.password);

    FILE *fp;
    fp = fopen("users.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%s %s\n", newUser.username, newUser.password);
    printf("User created successfully!\n");

    fclose(fp);
}

void authenticateUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    FILE *fp;
    fp = fopen("users.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    while (fgets(line, sizeof(line), fp)) {
        char *token;
        token = strtok(line, " ");

        if (strcmp(token, username) == 0) {
            found = 1;
            token = strtok(NULL, " ");

            if (strcmp(token, password) == 0) {
                printf("Login successful!\n");
            } else {
                printf("Invalid password!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("User not found!\n");
    }

    fclose(fp);
}

int main() {
    int option;

    while (1) {
        printf("\n--Password Manager--\n");
        printf("1. Create a new user account\n");
        printf("2. Authenticate user credentials\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createNewUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}