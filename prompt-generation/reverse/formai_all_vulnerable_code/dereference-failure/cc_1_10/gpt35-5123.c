//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 5
#define MAX_PASSWORD_LENGTH 20

int passwordCount = 0;
char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];

void addPassword() {
    if (passwordCount < MAX_PASSWORDS) {
        char* password = malloc(MAX_PASSWORD_LENGTH);
        printf("Please enter a new password: ");
        scanf("%s", password);
        strncpy(passwords[passwordCount], password, MAX_PASSWORD_LENGTH);
        passwordCount++;
        printf("Password added successfully.\n");
    } else {
        printf("You have reached the maximum number of passwords allowed.\n");
    }
}

void deletePassword() {
    if (passwordCount > 0) {
        int index;
        printf("Please enter the index of the password to delete: ");
        scanf("%d", &index);
        if (index >=0 && index < passwordCount) {
            memset(passwords[index], 0, MAX_PASSWORD_LENGTH);
            for (int i = index; i < passwordCount - 1; i++) {
                strncpy(passwords[i], passwords[i+1], MAX_PASSWORD_LENGTH);
            }
            passwordCount--;
            printf("Password deleted successfully.\n");
        } else {
            printf("Invalid index. Please try again.\n");
        }
    } else {
        printf("There are no passwords to delete.\n");
    }
}

void listPasswords() {
    if (passwordCount > 0) {
        printf("List of passwords:\n");
        for (int i = 0; i < passwordCount; i++) {
            printf("[%d] %s\n", i, passwords[i]);
        }
    } else {
        printf("There are no passwords to list.\n");
    }
}

void menu() {
    printf("\nPassword Management System\n");
    printf("----------------------------\n");
    printf("1. Add a new password\n");
    printf("2. Delete an existing password\n");
    printf("3. List all passwords\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addPassword(); break;
            case 2: deletePassword(); break;
            case 3: listPasswords(); break;
            case 4: printf("Thank you for using Password Management System.\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 4);

    return 0;
}