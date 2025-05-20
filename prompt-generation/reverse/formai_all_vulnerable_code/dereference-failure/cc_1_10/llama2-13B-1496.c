//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 5

typedef struct {
    char *username;
    char *password[MAX_PASSWORDS];
} user_info_t;

user_info_t users[5];

void add_user(char *username, char *password);
void list_users();
void delete_user(char *username);
void change_password(char *username, char *old_password, char *new_password);

int main() {
    int i;

    // Initialize users
    for (i = 0; i < MAX_PASSWORDS; i++) {
        users[i].username = NULL;
        users[i].password[i] = NULL;
    }

    // Add users
    add_user("user1", "password1");
    add_user("user2", "password2");
    add_user("user3", "password3");

    // List users
    list_users();

    // Delete user
    delete_user("user2");

    // Change password
    change_password("user1", "old_password1", "new_password1");

    return 0;
}

void add_user(char *username, char *password) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (users[i].username == NULL) {
            break;
        }
    }

    if (i == MAX_PASSWORDS) {
        printf("Error: Maximum number of users reached\n");
        return;
    }

    users[i].username = strdup(username);
    users[i].password[i] = strdup(password);
}

void list_users() {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (users[i].username != NULL) {
            printf("%s: %s\n", users[i].username, users[i].password[i]);
        }
    }
}

void delete_user(char *username) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            break;
        }
    }

    if (i == MAX_PASSWORDS) {
        printf("Error: User not found\n");
        return;
    }

    free(users[i].username);
    for (int j = i; j < MAX_PASSWORDS - 1; j++) {
        users[j] = users[j + 1];
    }
    users[MAX_PASSWORDS - 1].username = NULL;
    users[MAX_PASSWORDS - 1].password[0] = NULL;
}

void change_password(char *username, char *old_password, char *new_password) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            break;
        }
    }

    if (i == MAX_PASSWORDS) {
        printf("Error: User not found\n");
        return;
    }

    if (strcmp(users[i].password[0], old_password) != 0) {
        printf("Error: Incorrect old password\n");
        return;
    }

    users[i].password[0] = strdup(new_password);
}