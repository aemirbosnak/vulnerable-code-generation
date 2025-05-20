//Falcon2-11B DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LEN 100
#define MAX_USER_LEN 50

typedef struct {
    char* username;
    char* password;
} User;

typedef struct {
    User users[100];
    int num_users;
} PasswordManager;

bool add_user(PasswordManager* pw_manager, char* username, char* password) {
    if (pw_manager->num_users >= MAX_USER_LEN) {
        return false;
    }
    User* new_user = (User*)malloc(sizeof(User));
    new_user->username = strdup(username);
    new_user->password = strdup(password);
    pw_manager->users[pw_manager->num_users] = *new_user;
    pw_manager->num_users++;
    return true;
}

bool find_user(PasswordManager* pw_manager, char* username, User* user) {
    for (int i = 0; i < pw_manager->num_users; i++) {
        if (strcmp(pw_manager->users[i].username, username) == 0) {
            strcpy(user->username, pw_manager->users[i].username);
            strcpy(user->password, pw_manager->users[i].password);
            return true;
        }
    }
    return false;
}

int main() {
    PasswordManager pw_manager;
    pw_manager.num_users = 0;

    char* username = "user1";
    char* password = "pass1";

    if (add_user(&pw_manager, username, password)) {
        printf("User %s added successfully\n", username);
    } else {
        printf("Failed to add user\n");
    }

    User user;
    if (find_user(&pw_manager, username, &user)) {
        printf("Username: %s\n", user.username);
        printf("Password: %s\n", user.password);
    } else {
        printf("User not found\n");
    }

    return 0;
}