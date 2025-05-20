//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the password structure
typedef struct {
    char *username;
    char *password;
} password_t;

// Function to store a password in the password database
void add_password(password_t *passwords, int *num_passwords, const char *username, const char *password) {
    passwords[(*num_passwords)++] = (password_t) { username, password };
}

// Function to retrieve a password from the password database
password_t *get_password(const char *username, password_t *passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &passwords[i];
        }
    }
    return NULL;
}

// Function to check if a password exists in the database
int password_exists(const char *username, password_t *passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print all passwords in the database
void print_passwords(password_t *passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    // Initialize the password database
    password_t *passwords = malloc(sizeof(password_t) * 5);
    int num_passwords = 0;

    // Add some sample passwords
    add_password(passwords, &num_passwords, "user1", "password1");
    add_password(passwords, &num_passwords, "user2", "password2");
    add_password(passwords, &num_passwords, "user3", "password3");

    // Retrieve a password
    password_t *password = get_password("user2", passwords, num_passwords);
    if (password != NULL) {
        printf("Found password for %s: %s\n", password->username, password->password);
    } else {
        printf("No password found for %s\n", "user2");
    }

    // Check if a password exists
    if (password_exists("user4", passwords, num_passwords)) {
        printf("Password exists for %s\n", "user4");
    } else {
        printf("No password found for %s\n", "user4");
    }

    // Print all passwords
    print_passwords(passwords, num_passwords);

    free(passwords);
    return 0;
}