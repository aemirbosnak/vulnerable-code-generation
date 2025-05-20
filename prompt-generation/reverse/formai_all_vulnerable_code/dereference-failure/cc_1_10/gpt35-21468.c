//FormAI DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random password
char* generatePassword(int len) {
    char* password = (char*) malloc(len + 1);

    const char* allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+[]{}|;':\"<>,.?/";

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        password[i] = allowedChars[rand() % strlen(allowedChars)];
    }
    password[len] = '\0';

    return password;
}

// Function to store the passwords to a file
void storePasswords(char* username, char* password) {
    FILE* file = fopen("passwords.txt", "a");
    fprintf(file, "%s,%s\n", username, password);
    fclose(file);
}

// Function to retrieve the passwords from file
char* retrievePassword(char* username) {
    FILE* file = fopen("passwords.txt", "r");
    
    char line[100];
    while (fgets(line, 100, file)) {
        char* token = strtok(line, ",");
        if (strcmp(username, token) == 0) {
            char* password = strtok(NULL, ",");
            password[strcspn(password, "\n")] = 0; // remove newline character
            return password;
        }
    }

    fclose(file);
    return "";
}

int main() {
    char username[20];
    char password[20];
    char choice;

    printf("Welcome to our Password Management System!\n\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Generate a new password\n");
        printf("2. Store a password\n");
        printf("3. Retrieve a password\n");
        printf("4. Exit\n");
        printf("Choice: ");

        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("Please enter the length of the password to generate: ");
                int len;
                scanf("%d", &len);
                char* newPassword = generatePassword(len);
                printf("Your new password is: %s\n\n", newPassword);
                free(newPassword);
                break;

            case '2':
                printf("Please enter your username: ");
                scanf("%s", username);
                printf("Please enter your password: ");
                scanf("%s", password);
                storePasswords(username, password);
                printf("Your password has been stored.\n\n");
                break;

            case '3':
                printf("Please enter your username: ");
                scanf("%s", username);
                char* retrievedPassword = retrievePassword(username);
                if (strcmp(retrievedPassword, "") == 0) {
                    printf("Password not found.\n\n");
                } else {
                    printf("Your password is: %s\n\n", retrievedPassword);
                }
                break;

            case '4':
                printf("Thank you for using our Password Management System!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose again.\n\n");
                break;
        }
    }

    return 0;
}