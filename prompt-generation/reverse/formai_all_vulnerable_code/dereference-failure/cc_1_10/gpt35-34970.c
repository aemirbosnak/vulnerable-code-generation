//FormAI DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a linked list to store user and password information
typedef struct node {
    char* user;
    char* pass;
    struct node* next;
} User;

void insert(User** head, char* user, char* pass) {
    User* new_user = (User*)malloc(sizeof(User));
    new_user->user = user;
    new_user->pass = pass;
    new_user->next = *head;
    *head = new_user;
}

void delete(User** head, char* user) {
    User* current = *head;
    User* prev = NULL;

    while (current != NULL && strcmp(current->user, user) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("User not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int check(User* head, char* user, char* pass) {
    User* current = head;

    while (current != NULL) {
        if (strcmp(current->user, user) == 0 && strcmp(current->pass, pass) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    User* head = NULL;
    char input[100];
    char* user;
    char* pass;

    // Populate the linked list with some example users and passwords
    insert(&head, "admin", "pass123");
    insert(&head, "user1", "pass1");
    insert(&head, "user2", "pass2");
    insert(&head, "user3", "pass3");

    printf("\nWelcome to my Authentication System!\n");
    printf("Please enter your username and password (separated by a space):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Split the input into individual strings for the username and password
        user = strtok(input, " ");
        pass = strtok(NULL, " \n");

        // Strip any potential newline character from the end of the password
        if (pass[strlen(pass) - 1] == '\n') {
            pass[strlen(pass) - 1] = '\0';
        }

        // Check if the entered credentials are valid
        if (check(head, user, pass)) {
            printf("Login successful!\n");

            // Do some system administration-like tasks here
            printf("\nWelcome to the System Administration panel!\n");
            printf("You are now authorized to perform the following tasks:\n");
            printf("1. Add a new user\n");
            printf("2. Delete an existing user\n");
            printf("3. Change your password\n");
            printf("\nEnter the number of the task you wish to perform (or 'exit' to logout):\n");

            while (fgets(input, sizeof(input), stdin) != NULL) {
                if (strcmp(input, "1\n") == 0) {
                    printf("Enter the new user's username and password (separated by a space):\n");

                    // Split the input into individual strings for the new username and password
                    user = strtok(NULL, " ");
                    pass = strtok(NULL, " \n");

                    // Strip any potential newline character from the end of the password
                    if (pass[strlen(pass) - 1] == '\n') {
                        pass[strlen(pass) - 1] = '\0';
                    }

                    // Add the new user to the linked list
                    insert(&head, user, pass);

                    printf("New user added successfully!\n");

                    // Prompt the user for another action
                    printf("\nEnter the number of the task you wish to perform (or 'exit' to logout):\n");
                } else if (strcmp(input, "2\n") == 0) {
                    printf("Enter the username of the user you wish to delete:\n");

                    // Strip any potential newline character from the end of the username
                    if (user[strlen(user) - 1] == '\n') {
                        user[strlen(user) - 1] = '\0';
                    }

                    // Delete the specified user from the linked list
                    delete(&head, user);

                    // Prompt the user for another action
                    printf("\nEnter the number of the task you wish to perform (or 'exit' to logout):\n");
                } else if (strcmp(input, "3\n") == 0) {
                    printf("Enter your new password:\n");

                    // Get the new password from the user and update the linked list
                    fgets(input, sizeof(input), stdin);
                    if (input[strlen(input) - 1] == '\n') {
                        input[strlen(input) - 1] = '\0';
                    }
                    strcpy(pass, input);

                    printf("Password changed successfully!\n");

                    // Prompt the user for another action
                    printf("\nEnter the number of the task you wish to perform (or 'exit' to logout):\n");
                } else if (strcmp(input, "exit\n") == 0) {
                    printf("Logging out...\n");
                    break;
                } else {
                    printf("Invalid input. Please enter a number between 1 and 3 (or 'exit' to logout):\n");
                }
            }

            // Return to the main authentication loop
            printf("\nWelcome to my Authentication System!\n");
            printf("Please enter your username and password (separated by a space):\n");
        } else {
            printf("Invalid username or password. Please try again (or 'exit' to quit):\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}