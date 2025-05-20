//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>

void display_uptime() {
    struct sysinfo info;
    sysinfo(&info);
    
    printf("System Uptime: %ld days, %ld hours, %ld minutes\n", 
           info.uptime / 86400, (info.uptime % 86400) / 3600, 
           (info.uptime % 3600) / 60);
}

void display_memory_usage() {
    struct sysinfo info;
    sysinfo(&info);
    
    printf("Total RAM: %ld MB\n", info.totalram / (1024 * 1024));
    printf("Free RAM: %ld MB\n", info.freeram / (1024 * 1024));
    printf("Used RAM: %ld MB\n", (info.totalram - info.freeram) / (1024 * 1024));
}

void list_users() {
    struct passwd *pw;
    printf("User List:\n");
    while ((pw = getpwent()) != NULL) {
        printf("Username: %s, User ID: %d, Group ID: %d\n", pw->pw_name, pw->pw_uid, pw->pw_gid);
    }
    endpwent();
}

void add_user(const char* username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    if (system(command) == 0) {
        printf("User %s added successfully.\n", username);
    } else {
        printf("Failed to add user %s.\n", username);
    }
}

void delete_user(const char* username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo userdel %s", username);
    if (system(command) == 0) {
        printf("User %s deleted successfully.\n", username);
    } else {
        printf("Failed to delete user %s.\n", username);
    }
}

void change_password(const char* username) {
    char command[256];
    snprintf(command, sizeof(command), "sudo passwd %s", username);
    printf("You will be prompted for a new password for user %s.\n", username);
    system(command);
}

void display_menu() {
    printf("\n=== System Administration Menu ===\n");
    printf("1. Display System Uptime\n");
    printf("2. Display Memory Usage\n");
    printf("3. List Users\n");
    printf("4. Add User\n");
    printf("5. Delete User\n");
    printf("6. Change User Password\n");
    printf("7. Exit\n");
    printf("===================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char username[100];

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_uptime();
                break;
            case 2:
                display_memory_usage();
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("Enter username to add: ");
                scanf("%s", username);
                add_user(username);
                break;
            case 5:
                printf("Enter username to delete: ");
                scanf("%s", username);
                delete_user(username);
                break;
            case 6:
                printf("Enter username to change password: ");
                scanf("%s", username);
                change_password(username);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}