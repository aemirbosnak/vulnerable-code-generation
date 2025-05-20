//GEMINI-pro DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
    char *website;
} Password;

Password *passwords;
int num_passwords = 0;

void add_password(char *username, char *password, char *website) {
    passwords = realloc(passwords, (num_passwords + 1) * sizeof(Password));
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].website = strdup(website);
    num_passwords++;
}

void print_password(Password *password) {
    printf("Username: %s\n", password->username);
    printf("Password: %s\n", password->password);
    printf("Website: %s\n\n", password->website);
}

void print_all_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        print_password(&passwords[i]);
    }
}

void find_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            print_password(&passwords[i]);
            return;
        }
    }
    printf("Username not found!\n");
}

int main() {
    add_password("johndoe", "password123", "example.com");
    add_password("janedoe", "password456", "example2.com");
    add_password("johndoe2", "password789", "example3.com");

    printf("All passwords:\n");
    print_all_passwords();

    printf("Find password for 'johndoe':\n");
    find_password("johndoe");

    return 0;
}