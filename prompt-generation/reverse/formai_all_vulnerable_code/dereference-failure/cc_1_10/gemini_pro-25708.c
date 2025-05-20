//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 256

typedef struct {
    char *password;
    char *hint;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password, char *hint) {
    if (num_passwords == MAX_PASSWORDS) {
        fprintf(stderr, "Error: Too many passwords.\n");
        return;
    }

    passwords[num_passwords].password = malloc(strlen(password) + 1);
    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].hint = malloc(strlen(hint) + 1);
    strcpy(passwords[num_passwords].hint, hint);
    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].password, passwords[i].hint);
    }
}

void get_password(char *password) {
    char *p = getpass("Enter password: ");
    strcpy(password, p);
}

int main() {
    add_password("password1", "hint1");
    add_password("password2", "hint2");
    add_password("password3", "hint3");

    print_passwords();

    char password[MAX_PASSWORD_LEN];
    get_password(password);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(password, passwords[i].password) == 0) {
            printf("Password found: %s\n", passwords[i].hint);
            return 0;
        }
    }

    printf("Password not found.\n");
    return 1;
}