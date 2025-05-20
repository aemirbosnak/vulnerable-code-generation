//Falcon-180B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password *passwords = NULL;
int num_passwords = 0;

void add_password(char *username, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->username = strdup(username);
    new_password->password = strdup(password);
    passwords = realloc(passwords, sizeof(Password) * ++num_passwords);
    passwords[num_passwords - 1] = *new_password;
    free(new_password);
}

int find_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

char *get_password(char *username) {
    int index = find_password(username);
    if (index == -1) {
        return NULL;
    }
    return passwords[index].password;
}

int main() {
    add_password("example@gmail.com", "password123");
    add_password("test@gmail.com", "password456");

    char *password1 = get_password("example@gmail.com");
    char *password2 = get_password("test@gmail.com");

    printf("Password for example@gmail.com: %s\n", password1);
    printf("Password for test@gmail.com: %s\n", password2);

    return 0;
}