//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char username[50];
    char shell[50];
    char homeDirectory[100];
    int uid;
    int gid;
    char lastLogin[50];
} UserInfo;

void fetchUserInfo(UserInfo* user, const char* username) {
    struct passwd *pw = getpwnam(username);
    if (pw == NULL) {
        printf("User %s not found.\n", username);
        return;
    }
    strncpy(user->username, pw->pw_name, sizeof(user->username));
    strncpy(user->homeDirectory, pw->pw_dir, sizeof(user->homeDirectory));
    strncpy(user->shell, pw->pw_shell, sizeof(user->shell));
    user->uid = pw->pw_uid;
    user->gid = pw->pw_gid;

    time_t now = time(NULL);
    struct tm *lt = localtime(&now);
    strftime(user->lastLogin, sizeof(user->lastLogin), "%Y-%m-%d %H:%M:%S", lt);
}

void printUserInfo(const UserInfo* user) {
    printf("User: %s\n", user->username);
    printf("UID: %d\n", user->uid);
    printf("GID: %d\n", user->gid);
    printf("Home Directory: %s\n", user->homeDirectory);
    printf("Shell: %s\n", user->shell);
    printf("Last Login: %s\n", user->lastLogin);
    printf("-----------------------------\n");
}

void listUsers() {
    struct passwd *pw;
    setpwent(); // Reset password file pointer
    while ((pw = getpwent()) != NULL) {
        UserInfo user;
        fetchUserInfo(&user, pw->pw_name);
        printUserInfo(&user);
    }
    endpwent(); // Close the password file
}

void createUser(const char* username, const char* password) {
    char command[MAX_LINE_LENGTH];

    snprintf(command, sizeof(command), "sudo useradd -m -s /bin/bash %s", username);
    if (system(command) == 0) {
        snprintf(command, sizeof(command), "echo \"%s:%s\" | sudo chpasswd", username, password);
        system(command);
        printf("User %s created successfully.\n", username);
    } else {
        printf("Failed to create user %s.\n", username);
    }
}

void deleteUser(const char* username) {
    char command[MAX_LINE_LENGTH];

    snprintf(command, sizeof(command), "sudo userdel -r %s", username);
    if (system(command) == 0) {
        printf("User %s deleted successfully.\n", username);
    } else {
        printf("Failed to delete user %s.\n", username);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [list|create|delete] [username] [password]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* action = argv[1];

    if (strcmp(action, "list") == 0) {
        listUsers();
    } else if (strcmp(action, "create") == 0 && argc == 4) {
        createUser(argv[2], argv[3]);
    } else if (strcmp(action, "delete") == 0 && argc == 3) {
        deleteUser(argv[2]);
    } else {
        printf("Invalid command or parameters.\n");
        printf("Usage: %s [list|create|delete] [username] [password]\n", argv[0]);
    }

    return EXIT_SUCCESS;
}