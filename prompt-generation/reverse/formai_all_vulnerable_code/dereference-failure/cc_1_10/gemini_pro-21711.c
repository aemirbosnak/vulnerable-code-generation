//GEMINI-pro DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct password_entry {
    char *username;
    char *password;
} password_entry;

password_entry *passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password array is full.\n");
        return;
    }

    passwords[num_passwords] = malloc(sizeof(password_entry));
    passwords[num_passwords]->username = strdup(username);
    passwords[num_passwords]->password = strdup(password);
    num_passwords++;
}

char *get_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->username, username) == 0) {
            return passwords[i]->password;
        }
    }

    return NULL;
}

int main() {
    add_password("user1", "password1");
    add_password("user2", "password2");
    add_password("user3", "password3");

    char *password = get_password("user2");
    if (password != NULL) {
        printf("Password for user2 is %s\n", password);
    } else {
        printf("Error: Password not found for user2.\n");
    }

    return 0;
}