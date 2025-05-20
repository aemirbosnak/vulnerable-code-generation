//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Password {
    char* username;
    char* password;
};

struct Password* create_password(char* username, char* password) {
    struct Password* new_password = malloc(sizeof(struct Password));
    if (new_password == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(new_password->username, username);
    strcpy(new_password->password, password);
    return new_password;
}

int main() {
    struct Password* passwords = NULL;
    char username[50], password[50];
    printf("Welcome to the Password Management System!\n");
    printf("Enter your username:\n");
    fgets(username, sizeof(username), stdin);
    printf("Enter your password:\n");
    fgets(password, sizeof(password), stdin);
    struct Password* new_password = create_password(username, password);
    if (new_password!= NULL) {
        passwords = new_password;
        printf("Password added successfully.\n");
    } else {
        printf("Failed to add password.\n");
    }
    while (1) {
        printf("What would you like to do?\n");
        printf("1. View all passwords\n");
        printf("2. Add a new password\n");
        printf("3. Exit\n");
        int choice;
        fgets(&choice, sizeof(choice), stdin);
        int len = strlen(choice);
        if (len == 0) {
            printf("Invalid choice.\n");
        } else if (choice == '1') {
            if (passwords == NULL) {
                printf("No passwords found.\n");
            } else {
                printf("Username: %s\n", passwords->username);
                printf("Password: %s\n", passwords->password);
            }
        } else if (choice == '2') {
            struct Password* new_password = create_password(username, password);
            if (new_password!= NULL) {
                passwords = new_password;
                printf("Password added successfully.\n");
            } else {
                printf("Failed to add password.\n");
            }
        } else if (choice == '3') {
            printf("Bye, %s!\n", username);
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    if (passwords!= NULL) {
        free(passwords);
    }
    return 0;
}