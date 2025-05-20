//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_USERS 1024

// Structure to hold user information
typedef struct {
    char username[32];
    char home_directory[MAX_PATH];
    char shell[MAX_PATH];
} User;

// Function to get the user's information
void get_user_info(User *user, const char *username) {
    struct passwd *pw = getpwnam(username);
    if (pw) {
        strcpy(user->username, pw->pw_name);
        strcpy(user->home_directory, pw->pw_dir);
        strcpy(user->shell, pw->pw_shell);
    } else {
        fprintf(stderr, "User %s not found.\n", username);
        exit(EXIT_FAILURE);
    }
}

// Function to list all files in a directory
void list_files(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Files in %s:\n", dir_path);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') // Ignore hidden files
            printf(" - %s\n", entry->d_name);
    }

    closedir(dp);
}

// Function to create a new user
void create_user(const char *username) {
    char command[MAX_PATH];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    system(command);
    printf("User %s created successfully.\n", username);
}

// Function to delete a user
void delete_user(const char *username) {
    char command[MAX_PATH];
    snprintf(command, sizeof(command), "sudo userdel -r %s", username);
    system(command);
    printf("User %s deleted successfully.\n", username);
}

// Function to display Help Menu
void display_help() {
    printf("\nSystem Administration Helper\n");
    printf("Usage:\n");
    printf("  adduser <username>  - Create a new user.\n");
    printf("  deluser <username>  - Delete an existing user.\n");
    printf("  listfiles <directory> - List files in a directory.\n");
    printf("  userinfo <username> - Get user information.\n");
    printf("  help                - Display this help message.\n");
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_help();
        return -1;
    }

    if (strcmp(argv[1], "adduser") == 0 && argc == 3) {
        create_user(argv[2]);
    } else if (strcmp(argv[1], "deluser") == 0 && argc == 3) {
        delete_user(argv[2]);
    } else if (strcmp(argv[1], "listfiles") == 0 && argc == 3) {
        list_files(argv[2]);
    } else if (strcmp(argv[1], "userinfo") == 0 && argc == 3) {
        User user;
        get_user_info(&user, argv[2]);
        printf("Username: %s\nHome Directory: %s\nShell: %s\n", 
            user.username, user.home_directory, user.shell);
    } else if (strcmp(argv[1], "help") == 0) {
        display_help();
    } else {
        fprintf(stderr, "Invalid command or arguments.\n");
        display_help();
        return -1;
    }

    return 0;
}