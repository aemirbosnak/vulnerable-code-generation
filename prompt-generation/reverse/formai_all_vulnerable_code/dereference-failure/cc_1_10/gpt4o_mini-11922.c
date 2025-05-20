//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_USERS 100
#define USERNAME_LEN 32

void list_users();
void add_user(const char *username);
void remove_user(const char *username);
int user_exists(const char *username);

int main() {
    int choice;
    char username[USERNAME_LEN];

    while(1) {
        printf("\nSimple Linux User Management Tool\n");
        printf("1. List Users\n");
        printf("2. Add User\n");
        printf("3. Remove User\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                list_users();
                break;
            case 2:
                printf("Enter username to add: ");
                scanf("%s", username);
                if(user_exists(username)) {
                    printf("User %s already exists!\n", username);
                } else {
                    add_user(username);
                }
                break;
            case 3:
                printf("Enter username to remove: ");
                scanf("%s", username);
                if(!user_exists(username)) {
                    printf("User %s does not exist!\n", username);
                } else {
                    remove_user(username);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void list_users() {
    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Failed to open /etc/passwd");
        return;
    }

    printf("\nList of users on the system:\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ":");
        printf("- %s\n", username);
    }
    
    fclose(fp);
}

void add_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    if (system(command) == 0) {
        printf("User %s added successfully!\n", username);
    } else {
        fprintf(stderr, "Failed to add user %s!\n", username);
    }
}

void remove_user(const char *username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo userdel %s", username);
    if (system(command) == 0) {
        printf("User %s removed successfully!\n", username);
    } else {
        fprintf(stderr, "Failed to remove user %s!\n", username);
    }
}

int user_exists(const char *username) {
    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Failed to open /etc/passwd");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *user = strtok(line, ":");
        if (strcmp(user, username) == 0) {
            fclose(fp);
            return 1; // User exists
        }
    }
    
    fclose(fp);
    return 0; // User does not exist
}