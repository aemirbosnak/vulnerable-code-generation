//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 10

typedef struct {
    char *password;
    bool is_locked;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(const char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].is_locked = false;
    num_passwords++;
}

void lock_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Invalid password index.\n");
        return;
    }

    passwords[index].is_locked = true;
}

void unlock_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Invalid password index.\n");
        return;
    }

    passwords[index].is_locked = false;
}

void display_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        if (passwords[i].is_locked) {
            printf("Password %d (%s): Locked\n", i + 1, passwords[i].password);
        } else {
            printf("Password %d (%s): Unlocked\n", i + 1, passwords[i].password);
        }
    }
}

int main() {
    add_password("password1");
    add_password("password2");
    add_password("password3");

    lock_password(1);
    lock_password(2);

    display_passwords();

    unlock_password(1);
    unlock_password(2);

    display_passwords();

    return 0;
}