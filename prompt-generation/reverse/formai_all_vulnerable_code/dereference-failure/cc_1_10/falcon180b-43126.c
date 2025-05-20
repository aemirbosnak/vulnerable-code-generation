//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached\n");
        return;
    }

    Password *new_password = &passwords[num_passwords];
    new_password->username = strdup(username);
    new_password->password = strdup(password);

    num_passwords++;
}

void remove_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (int j = i; j < num_passwords - 1; j++) {
                Password *temp_password = &passwords[j];
                passwords[j] = passwords[j+1];
                passwords[j+1] = *temp_password;
            }

            num_passwords--;
            break;
        }
    }
}

void display_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

int main() {
    add_password("example1", "password1");
    add_password("example2", "password2");
    add_password("example3", "password3");

    display_passwords();

    remove_password("example2");

    display_passwords();

    return 0;
}