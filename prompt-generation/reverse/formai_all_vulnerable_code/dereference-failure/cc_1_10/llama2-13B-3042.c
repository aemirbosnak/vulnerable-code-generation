//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USER_NAME_LENGTH 20

typedef struct {
    char username[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_info;

int main() {
    int i;
    user_info users[5];

    // Initialize users array
    for (i = 0; i < 5; i++) {
        users[i].username[0] = '\0';
        users[i].password[0] = '\0';
    }

    // Password management menu
    while (1) {
        printf("Welcome to the password management system!\n");
        printf("Please select an option from the following menu:\n");
        printf("1. Add new user\n");
        printf("2. Modify existing user\n");
        printf("3. Delete user\n");
        printf("4. View all users\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        // Handle user input
        switch (choice) {
            case 1:
                // Add new user
                printf("Enter the new user's username: ");
                fgets(users[i].username, MAX_USER_NAME_LENGTH, stdin);
                printf("Enter the new user's password: ");
                fgets(users[i].password, MAX_PASSWORD_LENGTH, stdin);
                break;

            case 2:
                // Modify existing user
                printf("Enter the user ID to modify (1-4): ");
                scanf("%d", &i);
                printf("Enter the new username: ");
                fgets(users[i].username, MAX_USER_NAME_LENGTH, stdin);
                printf("Enter the new password: ");
                fgets(users[i].password, MAX_PASSWORD_LENGTH, stdin);
                break;

            case 3:
                // Delete user
                printf("Enter the user ID to delete (1-4): ");
                scanf("%d", &i);
                break;

            case 4:
                // View all users
                printf("Here are the current users:\n");
                for (i = 0; i < 5; i++) {
                    printf("User %d: %s %s\n", i + 1, users[i].username, users[i].password);
                }
                break;

            case 5:
                // Quit
                return 0;
                break;
        }
    }

    return 0;
}