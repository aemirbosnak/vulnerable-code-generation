//GEMINI-pro DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password database is full.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

char *get_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return passwords[i].password;
        }
    }

    return NULL;
}

int main() {
    // Add some sample passwords to the database.
    add_password("admin", "password");
    add_password("user1", "password1");
    add_password("user2", "password2");

    // Get the password for a specific user.
    char *password = get_password("user1");
    if (password == NULL) {
        printf("Error: Password not found.\n");
        return 1;
    }

    // Print the password.
    printf("Password: %s\n", password);

    return 0;
}