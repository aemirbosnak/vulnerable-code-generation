//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>

#define USERNAME_LENGTH 32
#define PASSWORD_LENGTH 128

void add_user(const char *username, const char *password) {
    char command[256];
    snprintf(command, sizeof(command), "sudo useradd -m %s", username);
    system(command);
    
    snprintf(command, sizeof(command), "echo '%s:%s' | sudo chpasswd", username, password);
    system(command);
}

void remove_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo userdel -r %s", username);
    system(command);
}

void list_users() {
    struct passwd *pw;
    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Failed to open /etc/passwd");
        return;
    }
    
    printf("Current User Accounts:\n");
    while ((pw = fgetpwent(fp)) != NULL) {
        printf("- %s\n", pw->pw_name);
    }
    fclose(fp);
}

int main() {
    int choice;
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Welcome to the Irregular System Admin Tool\n");
    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Add a User\n");
        printf("2. Remove a User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline

                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline

                add_user(username, password);
                printf("User %s added successfully!\n", username);
                break;
            case 2:
                printf("Enter username to remove: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline

                remove_user(username);
                printf("User %s removed successfully!\n", username);
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("Exiting, farewell!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
    return 0;
}