//GEMINI-pro DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
} user_t;

#define MAX_USERS 100

user_t users[MAX_USERS];

int num_users = 0;

void add_user(char *username, char *password) {
    if (num_users >= MAX_USERS) {
        printf("Sorry, too many users. Try again later.\n");
        return;
    }

    users[num_users].username = strdup(username);
    users[num_users].password = strdup(password);
    num_users++;
}

int find_user(char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

int authenticate_user(char *username, char *password) {
    int index = find_user(username);

    if (index == -1) {
        printf("Sorry, that user doesn't exist.\n");
        return 0;
    }

    if (strcmp(users[index].password, password) == 0) {
        printf("Welcome back, %s!\n", username);
        return 1;
    } else {
        printf("Sorry, wrong password.\n");
        return 0;
    }
}

int main() {
    // Add some sample users to the database.
    add_user("alice", "password");
    add_user("bob", "password");
    add_user("charlie", "password");

    // Get the username and password from the user.
    char username[256];
    char password[256];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate the user.
    int authenticated = authenticate_user(username, password);

    // Print a message based on the authentication result.
    if (authenticated) {
        printf("You have successfully logged in.\n");
    } else {
        printf("Sorry, login failed.\n");
    }

    return 0;
}