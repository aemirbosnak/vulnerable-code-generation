//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_CMD_LEN 256

typedef struct UserInfo {
    char username[50];
    char homeDirectory[100];
    char shell[100];
} UserInfo;

// Function prototypes
void displayWelcomeMessage();
void listUsers(UserInfo users[], int userCount);
int getUserCount();
void getUserDetails(UserInfo users[], int userCount);
void createBackup(int userCount, UserInfo users[]);
int executeCommand(const char* cmd);

int main() {
    UserInfo users[MAX_USERS];
    int userCount = getUserCount();

    displayWelcomeMessage();
    getUserDetails(users, userCount);
    listUsers(users, userCount);
    
    createBackup(userCount, users);
    
    return 0;
}

void displayWelcomeMessage() {
    printf("*****************************************\n");
    printf("*       Linux System Administration     *\n");
    printf("*      User Information and Backup      *\n");
    printf("*****************************************\n\n");
}

int getUserCount() {
    return sysconf(_SC_NPROCESSORS_ONLN);  // This is just a placeholder
}

void getUserDetails(UserInfo users[], int userCount) {
    struct passwd *pw;
    setpwent(); // Rewind user database

    int i = 0;
    while ((pw = getpwent()) != NULL && i < userCount) {
        strncpy(users[i].username, pw->pw_name, sizeof(users[i].username));
        strncpy(users[i].homeDirectory, pw->pw_dir, sizeof(users[i].homeDirectory));
        strncpy(users[i].shell, pw->pw_shell, sizeof(users[i].shell));
        i++;
    }
    endpwent(); // Close user database
}

void listUsers(UserInfo users[], int userCount) {
    printf("List of Users:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s\n", users[i].username);
        printf("Home Directory: %s\n", users[i].homeDirectory);
        printf("Shell: %s\n", users[i].shell);
        printf("-------------------------------------------------\n");
    }
}

void createBackup(int userCount, UserInfo users[]) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char backupFileName[100];
    snprintf(backupFileName, sizeof(backupFileName), "backup_%d-%02d-%02d_%02d:%02d:%02d.txt",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    FILE *file = fopen(backupFileName, "w");
    if (file == NULL) {
        perror("Failed to create backup file");
        return;
    }
    
    fprintf(file, "User Information Backup - %d-%02d-%02d %02d:%02d:%02d\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(file, "-------------------------------------------------\n");
    
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "Username: %s\n", users[i].username);
        fprintf(file, "Home Directory: %s\n", users[i].homeDirectory);
        fprintf(file, "Shell: %s\n", users[i].shell);
        fprintf(file, "-------------------------------------------------\n");
    }
    fclose(file);
    
    printf("Backup created successfully: %s\n", backupFileName);
}

int executeCommand(const char* cmd) {
    int ret = system(cmd);
    if (ret == -1) {
        perror("Error executing command");
    }
    return ret;
}