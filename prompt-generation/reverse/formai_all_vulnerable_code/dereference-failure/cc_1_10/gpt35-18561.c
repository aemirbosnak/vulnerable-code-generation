//FormAI DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_users = 0; // Number of users in the system

// Struct to represent a user account
typedef struct {
    char* username;
    char* password;
    char* fullname;
    int id;
} User;

// Array of user accounts
User users[50];

// Function to add a new user
void add_user() {
    // Get username input
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    // Check if username is already taken
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already taken.\n");
            return;
        }
    }

    // Get password input
    char password[20];
    printf("Enter password: ");
    scanf("%s", password);

    // Get full name input
    char fullname[50];
    printf("Enter full name: ");
    scanf("%s", fullname);

    // Create new user account
    User new_user;
    new_user.username = malloc(strlen(username) + 1);
    strcpy(new_user.username, username);
    new_user.password = malloc(strlen(password) + 1);
    strcpy(new_user.password, password);
    new_user.fullname = malloc(strlen(fullname) + 1);
    strcpy(new_user.fullname, fullname);
    new_user.id = num_users + 1;

    // Add user to array
    users[num_users] = new_user;
    num_users++;

    printf("User %s added successfully with ID %d.\n", new_user.username, new_user.id);
}

// Function to list all users
void list_users() {
    if (num_users == 0) {
        printf("No users in system.\n");
        return;
    }
    printf("ID\tUsername\tFull Name\n");
    for (int i = 0; i < num_users; i++) {
        printf("%d\t%s\t\t%s\n", users[i].id, users[i].username, users[i].fullname);
    }
}

// Function to delete a user
void delete_user() {
    // Get user ID input
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    // Find user with given ID
    int found_index = -1;
    for (int i = 0; i < num_users; i++) {
        if (users[i].id == id) {
            found_index = i;
            break;
        }
    }

    // Remove user if found
    if (found_index >= 0) {
        printf("User %s deleted successfully.\n", users[found_index].username);
        free(users[found_index].username);
        free(users[found_index].password);
        free(users[found_index].fullname);
        for (int i = found_index; i < num_users - 1; i++) {
            users[i] = users[i + 1];
            users[i].id--;
        }
        num_users--;
    } else {
        printf("User with ID %d not found.\n", id);
    }
}

// Main function
int main() {
    int choice;
    do {
        printf("\nUser Account Management Menu\n");
        printf("1. Add User\n");
        printf("2. List Users\n");
        printf("3. Delete User\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                list_users();
                break;
            case 3:
                delete_user();
                break;
            case 4:
                printf("Exiting user account management program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}