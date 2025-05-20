//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 5
#define MAX_PASSWORD_LENGTH 20

// Structure to store passwords
typedef struct {
    char *password;
    int password_length;
} password_t;

// Function to store a password
void add_password(password_t **passwords, int *num_passwords, const char *password) {
    // Check if the password is too long
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Error: Password too long!\n");
        return;
    }

    // Allocate memory for the new password
    password_t *new_password = (password_t *)malloc(sizeof(password_t));
    new_password->password = (char *)malloc(strlen(password) + 1);
    strcpy(new_password->password, password);
    new_password->password_length = strlen(password);

    // Add the new password to the list
    *num_passwords += 1;
    passwords = realloc(passwords, (*num_passwords) * sizeof(password_t));
    passwords[*num_passwords - 1] = new_password;
}

// Function to retrieve a password
const char *get_password(password_t **passwords, int num_passwords, int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Invalid index!\n");
        return NULL;
    }

    return passwords[index]->password;
}

// Function to check if a password is in the list
int password_exist(password_t **passwords, int num_passwords, const char *password) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    password_t *passwords = NULL;
    int num_passwords = 0;

    // Add some passwords
    add_password(&passwords, &num_passwords, "hello");
    add_password(&passwords, &num_passwords, "world");
    add_password(&passwords, &num_passwords, "retro");

    // Retrieve a password
    const char *password = get_password(&passwords, num_passwords, 1);
    printf("Retrieved password: %s\n", password);

    // Check if a password exists
    if (password_exist(&passwords, num_passwords, "hello")) {
        printf("Password 'hello' exists.\n");
    } else {
        printf("Password 'hello' does not exist.\n");
    }

    return 0;
}