//Falcon-180B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password *new_password = &passwords[num_passwords];
    new_password->username = strdup(username);
    new_password->password = strdup(password);

    num_passwords++;
}

bool find_password(char *username, char **password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            *password = passwords[i].password;
            return true;
        }
    }

    return false;
}

void delete_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            num_passwords--;
            return;
        }
    }
}

void print_passwords() {
    printf("Username\tPassword\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example1", "password1");
    add_password("example2", "password2");

    print_passwords();

    char *found_password;
    find_password("example1", &found_password);
    printf("Found password for example1: %s\n", found_password);

    delete_password("example2");

    print_passwords();

    return 0;
}