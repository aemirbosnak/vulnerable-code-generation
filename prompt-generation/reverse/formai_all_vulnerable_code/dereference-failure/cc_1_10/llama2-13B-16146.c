//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

typedef struct {
    char *password;
    bool valid;
} password_t;

password_t passwords[MAX_PASSWORDS];
int curr_password = 0;

void add_password(const char *password) {
    passwords[curr_password].password = strdup(password);
    passwords[curr_password].valid = true;
    curr_password++;
}

bool check_password(const char *password) {
    for (int i = 0; i < curr_password; i++) {
        if (strcmp(password, passwords[i].password) == 0) {
            return passwords[i].valid;
        }
    }
    return false;
}

void print_passwords() {
    for (int i = 0; i < curr_password; i++) {
        printf("%d. %s (%s)\n", i + 1, passwords[i].password, passwords[i].valid ? "valid" : "invalid");
    }
}

int main() {
    add_password("password1");
    add_password("password2");
    add_password("password3");
    add_password("password4");

    if (check_password("password1")) {
        printf("Password 'password1' is valid\n");
    } else {
        printf("Password 'password1' is invalid\n");
    }

    if (check_password("password2")) {
        printf("Password 'password2' is valid\n");
    } else {
        printf("Password 'password2' is invalid\n");
    }

    print_passwords();

    return 0;
}