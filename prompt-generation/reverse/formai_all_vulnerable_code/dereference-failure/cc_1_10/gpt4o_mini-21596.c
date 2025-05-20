//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

// Function to add a user
void add_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    if (system(command) == 0) {
        printf("User '%s' added successfully.\n", username);
    } else {
        perror("Failed to add user");
    }
}

// Function to delete a user
void delete_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo userdel %s", username);
    if (system(command) == 0) {
        printf("User '%s' deleted successfully.\n", username);
    } else {
        perror("Failed to delete user");
    }
}

// Function to list all users
void list_users() {
    struct passwd *pw;
    FILE *fp;
    int count = 0;

    printf("List of users in the system:\n");
    fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Failed to open /etc/passwd");
        return;
    }
    
    while ((pw = getpwent()) != NULL) {
        printf("%d: %s\n", ++count, pw->pw_name);
    }

    endpwent();
    fclose(fp);
}

// Main program
int main() {
    int choice;
    char username[50];

    while (1) {
        printf("\nSystem Administration Tool\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                add_user(username);
                break;
            case 2:
                printf("Enter username to delete: ");
                scanf("%s", username);
                delete_user(username);
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}