//Falcon-180B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

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

    int len = strlen(username);
    if (len > MAX_PASSWORD_LENGTH) {
        printf("Error: Username too long.\n");
        return;
    }

    int pass_len = strlen(password);
    if (pass_len > MAX_PASSWORD_LENGTH) {
        printf("Error: Password too long.\n");
        return;
    }

    passwords[num_passwords].username = malloc(len + 1);
    strcpy(passwords[num_passwords].username, username);

    passwords[num_passwords].password = malloc(pass_len + 1);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            num_passwords--;
            passwords[i] = passwords[num_passwords];
        }
    }
}

void display_passwords() {
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char *username = "test";
    char *password = "test123";

    add_password(username, password);
    display_passwords();

    remove_password(username);
    display_passwords();

    return 0;
}