//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

struct password {
    char *name;
    char *password;
};

void add_password(struct password **passwords, int *num_passwords, const char *name, const char *password) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached\n");
        return;
    }

    struct password *new_password = malloc(sizeof(struct password));
    new_password->name = name;
    new_password->password = password;

    passwords[(*num_passwords)++] = new_password;

    if (*num_passwords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached\n");
    }
}

void print_passwords(struct password **passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s (%s)\n", i + 1, passwords[i]->name, passwords[i]->password);
    }
}

int main() {
    struct password **passwords = malloc(MAX_PASSWORDS * sizeof(struct password *));
    int num_passwords = 0;

    add_password(&passwords, &num_passwords, "John", "Doe123");
    add_password(&passwords, &num_passwords, "Jane", "Doe456");
    add_password(&passwords, &num_passwords, "Bob", "Smith789");

    print_passwords(passwords, num_passwords);

    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i]);
    }

    free(passwords);

    return 0;
}