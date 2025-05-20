//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 30
#define COMMAND_LENGTH 100

void list_users() {
    struct passwd *pw;
    FILE *fp;

    printf("List of users on the system:\n");
    setpwent();
    while ((pw = getpwent()) != NULL) {
        printf("Username: %s, UID: %d, GID: %d\n", pw->pw_name, pw->pw_uid, pw->pw_gid);
    }
    endpwent();
}

void add_user(const char *username) {
    char command[COMMAND_LENGTH];
    if (strlen(username) > USERNAME_LENGTH) {
        printf("Username is too long. Maximum length is %d characters.\n", USERNAME_LENGTH);
        return;
    }

    snprintf(command, sizeof(command), "sudo useradd %s", username);
    if (system(command) == -1) {
        perror("Error adding user");
    } else {
        printf("User %s has been added.\n", username);
    }
}

void delete_user(const char *username) {
    char command[COMMAND_LENGTH];

    snprintf(command, sizeof(command), "sudo userdel %s", username);
    if (system(command) == -1) {
        perror("Error deleting user");
    } else {
        printf("User %s has been deleted.\n", username);
    }
}

void print_menu() {
    printf("\nSystem Administration Tool\n");
    printf("1. List users\n");
    printf("2. Add user\n");
    printf("3. Delete user\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char username[USERNAME_LENGTH];

    while (1) {
        print_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                list_users();
                break;
            case 2:
                printf("Enter username to add: ");
                fgets(username, USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';  // Remove trailing newline
                add_user(username);
                break;
            case 3:
                printf("Enter username to delete: ");
                fgets(username, USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';  // Remove trailing newline
                delete_user(username);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}