//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void add_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    if (system(command) == 0) {
        printf("User %s added successfully.\n", username);
    } else {
        printf("Failed to add user %s.\n", username);
    }
}

void remove_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo userdel -r %s", username);
    if (system(command) == 0) {
        printf("User %s removed successfully.\n", username);
    } else {
        printf("Failed to remove user %s.\n", username);
    }
}

void list_users() {
    struct passwd *pw;
    setpwent();  // Reset the user buffer
    printf("List of users:\n");
    while ((pw = getpwent()) != NULL) {
        printf("Username: %s\n", pw->pw_name);
    }
    endpwent(); // Close user buffer
}

void display_menu() {
    printf("\n--- User Management Menu ---\n");
    printf("1. Add User\n");
    printf("2. Remove User\n");
    printf("3. List Users\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char username[50];

    while (1) {
        display_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                add_user(username);
                break;
            case 2:
                printf("Enter username to remove: ");
                scanf("%s", username);
                remove_user(username);
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}