//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 30
#define PASSWORD_LENGTH 30

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void handleError(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

void addUser(const char* username, const char* password) {
    if (user_count >= MAX_USERS) {
        handleError("Maximum user limit reached!");
    }
    if (strlen(username) >= USERNAME_LENGTH) {
        handleError("Username too long!");
    }
    if (strlen(password) >= PASSWORD_LENGTH) {
        handleError("Password too long!");
    }
    
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
    printf("User %s added successfully!\n", username);
}

int findUser(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i; // return the index of the user
        }
    }
    return -1; // user not found
}

void authenticateUser(const char* username, const char* password) {
    int idx = findUser(username);
    if (idx == -1) {
        handleError("User not found!");
    }
    if (strcmp(users[idx].password, password) != 0) {
        handleError("Incorrect password!");
    }

    printf("User %s authenticated successfully!\n", username);
}

void displayUsers() {
    if (user_count == 0) {
        printf("No users available!\n");
        return;
    }
    printf("List of users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("- %s\n", users[i].username);
    }
}

void freeResources() {
    // In a real-world application, this would handle freeing dynamic memory,
    // closing files, etc. Here, we simply print a message.
    printf("Cleaning up resources...\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> [options]\n", argv[0]);
        printf("Commands:\n");
        printf("  add <username> <password>    Add a new user\n");
        printf("  auth <username> <password>   Authenticate a user\n");
        printf("  list                          List all users\n");
        freeResources();
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc == 4) {
        addUser(argv[2], argv[3]);
    } else if (strcmp(argv[1], "auth") == 0 && argc == 4) {
        authenticateUser(argv[2], argv[3]);
    } else if (strcmp(argv[1], "list") == 0) {
        displayUsers();
    } else {
        handleError("Invalid command or insufficient arguments!");
    }

    freeResources();
    return 0;
}