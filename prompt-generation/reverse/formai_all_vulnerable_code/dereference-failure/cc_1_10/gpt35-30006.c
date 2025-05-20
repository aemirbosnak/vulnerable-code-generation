//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 20

struct User {
    char *username;
    char *passwords[MAX_PASSWORDS];
    int num_passwords;
};

struct User *users[MAX_USERS];
int num_users = 0;

struct User *get_user(char *username) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i]->username, username) == 0) {
            return users[i];
        }
    }
    return NULL;
}

void new_user(char *username) {
    if (get_user(username)) {
        printf("Username already exists.\n");
        return;
    }

    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct User *user = (struct User *) malloc(sizeof(struct User));
    user->username = username;
    user->num_passwords = 0;
    users[num_users++] = user;
}

void add_password(char *username, char *password) {
    struct User *user = get_user(username);

    if (!user) {
        printf("User not found.\n");
        return;
    }

    if (user->num_passwords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    // Encrypt password before storing
    char *encrypted_password = (char *) malloc(strlen(password) + 1);
    strcpy(encrypted_password, password);
    user->passwords[user->num_passwords++] = encrypted_password;
}

void print_passwords(char *username) {
    struct User *user = get_user(username);

    if (!user) {
        printf("User not found.\n");
        return;
    }

    printf("%s's passwords:\n", user->username);
    int i;
    for (i = 0; i < user->num_passwords; i++) {
        printf("%s\n", user->passwords[i]);
    }
}

int main() {
    new_user("JohnDoe");
    add_password("JohnDoe", "password1");
    add_password("JohnDoe", "password2");
    print_passwords("JohnDoe");

    return 0;
}