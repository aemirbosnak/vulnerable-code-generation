//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define SALT_MAX_LENGTH 10

typedef struct {
    char *password;
    char *salt;
} user_info;

user_info *users = NULL;
int num_users = 0;

void add_user(char *password, char *salt) {
    user_info *new_user = (user_info *)calloc(1, sizeof(user_info));
    new_user->password = password;
    new_user->salt = salt;
    users = realloc(users, (num_users + 1) * sizeof(user_info));
    users[num_users] = *new_user;
    num_users++;
}

int verify_password(char *password, int index) {
    user_info *user = users + index;
    char hash[100];
    char *salt = user->salt;
    int i = 0;

    for (; i < strlen(password); i++) {
        hash[i] = password[i] ^ salt[i];
    }

    for (; i < 100; i++) {
        hash[i] = hash[i] ^ (i % 2 ? salt[i] : password[i]);
    }

    return strcmp(hash, user->password) == 0;
}

int main() {
    char *passwords[3] = {"password1", "password2", "password3"};
    char *salt[3] = {"salt1", "salt2", "salt3"};
    int i;

    for (i = 0; i < 3; i++) {
        add_user(passwords[i], salt[i]);
    }

    for (i = 0; i < 3; i++) {
        if (verify_password(passwords[i], i)) {
            printf("Password %s is correct for user %d\n", passwords[i], i + 1);
        } else {
            printf("Password %s is incorrect for user %d\n", passwords[i], i + 1);
        }
    }

    return 0;
}