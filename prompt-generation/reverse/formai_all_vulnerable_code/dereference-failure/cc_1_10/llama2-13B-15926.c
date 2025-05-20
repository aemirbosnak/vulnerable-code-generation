//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define MAX_USERS 10

typedef struct {
    char *username;
    char *password;
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user(char *username, char *password) {
    if (num_users == MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    users[num_users].username = username;
    users[num_users].password = password;
    num_users++;
}

void list_users() {
    for (int i = 0; i < num_users; i++) {
        printf("%d. %s %s\n", i + 1, users[i].username, users[i].password);
    }
}

void remove_user(char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            memset(users[i].username, 0, strlen(users[i].username));
            memset(users[i].password, 0, strlen(users[i].password));
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    add_user("user1", "password1");
    add_user("user2", "password2");
    add_user("user3", "password3");

    list_users();

    remove_user("user2");

    list_users();

    return 0;
}