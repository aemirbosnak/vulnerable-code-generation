//GEMINI-pro DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct password {
    char *name;
    char *password;
} password;

password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }

    passwords[num_passwords].name = strdup(name);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

char *get_password(char *name) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return passwords[i].password;
        }
    }

    return NULL;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    // Add some sample passwords.
    add_password("Alice", "password1");
    add_password("Bob", "password2");
    add_password("Charlie", "password3");

    // Print the passwords.
    print_passwords();

    // Get the password for Alice.
    char *password = get_password("Alice");

    // Print the password.
    printf("Alice's password is: %s\n", password);

    return 0;
}