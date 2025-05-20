//Falcon-180B DATASET v1.0 Category: Password management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords.\n");
        return;
    }

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Error: Username already exists.\n");
            return;
        }
    }

    passwords[num_passwords].username = (char *)malloc(strlen(username) + 1);
    strcpy(passwords[num_passwords].username, username);

    passwords[num_passwords].password = (char *)malloc(strlen(password) + 1);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(Password));

            num_passwords--;
            return;
        }
    }

    printf("Error: Username not found.\n");
}

void print_passwords() {
    printf("Username\tPassword\n");
    printf("------------------------------------------------\n");

    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example1", "password1");
    add_password("example2", "password2");
    add_password("example3", "password3");

    print_passwords();

    remove_password("example2");

    print_passwords();

    return 0;
}