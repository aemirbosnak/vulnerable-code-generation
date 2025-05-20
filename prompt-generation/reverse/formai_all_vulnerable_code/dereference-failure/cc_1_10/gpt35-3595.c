//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* username;
    char* password;
} User;

User* createUser(char* username, char* password) {
    User* user = (User*) malloc(sizeof(User));
    user->username = (char*) malloc(strlen(username) + 1);
    user->password = (char*) malloc(strlen(password) + 1);
    strncpy(user->username, username, strlen(username) + 1);
    strncpy(user->password, password, strlen(password) + 1);
    return user;
}

void deleteUser(User* user) {
    free(user->username);
    free(user->password);
    free(user);
}

bool authenticate(User* user, char* password) {
    if (strcmp(user->password, password) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    // Create a new user
    User* user = createUser("admin", "password");

    // Authenticate the user
    char* password = (char*) malloc(9);
    printf("Enter password: ");
    scanf("%s", password);
    bool authenticated = authenticate(user, password);
    if (authenticated) {
        printf("Authentication success!\n");
    }
    else {
        printf("Authentication failed!\n");
    }
    free(password);

    // Delete the user
    deleteUser(user);

    return 0;
}