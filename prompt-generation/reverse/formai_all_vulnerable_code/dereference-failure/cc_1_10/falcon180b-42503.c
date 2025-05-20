//Falcon-180B DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 80

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    password_t *new_password = &passwords[num_passwords];
    new_password->username = strdup(username);
    new_password->password = strdup(password);

    num_passwords++;
}

int find_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void list_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example.com", "password1");
    add_password("example2.com", "password2");

    list_passwords();

    int index = find_password("example.com");
    if (index!= -1) {
        printf("Password for %s: %s\n", passwords[index].username, passwords[index].password);
    } else {
        printf("No password found.\n");
    }

    return 0;
}