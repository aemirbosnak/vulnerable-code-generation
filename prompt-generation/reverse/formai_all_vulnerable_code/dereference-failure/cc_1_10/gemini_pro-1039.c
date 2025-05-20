//GEMINI-pro DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A dynamic array to store the passwords
typedef struct {
    char *password;
    int len;
} password_t;

// Initialize the password manager
void init_password_manager(password_t **passwords) {
    *passwords = malloc(sizeof(password_t));
    (*passwords)->password = NULL;
    (*passwords)->len = 0;
}

// Add a password to the password manager
void add_password(password_t **passwords, char *password) {
    int len = strlen(password);

    // Reallocate the password array if necessary
    if ((*passwords)->len + len + 1 > (*passwords)->len) {
        (*passwords) = realloc(*passwords, sizeof(password_t) * ((*passwords)->len + len + 1));
    }

    // Add the password to the array
    (*passwords)[(*passwords)->len].password = password;
    (*passwords)[(*passwords)->len].len = len;
    (*passwords)->len++;
}

// Get a password from the password manager
char *get_password(password_t **passwords, int index) {
    if (index < 0 || index >= (*passwords)->len) {
        return NULL;
    }

    return (*passwords)[index].password;
}

// Delete a password from the password manager
void delete_password(password_t **passwords, int index) {
    if (index < 0 || index >= (*passwords)->len) {
        return;
    }

    // Free the password
    free((*passwords)[index].password);

    // Shift the passwords down
    for (int i = index; i < (*passwords)->len - 1; i++) {
        (*passwords)[i] = (*passwords)[i + 1];
    }

    // Decrement the password count
    (*passwords)->len--;
}

// Free the password manager
void free_password_manager(password_t **passwords) {
    for (int i = 0; i < (*passwords)->len; i++) {
        free((*passwords)[i].password);
    }

    free(*passwords);
}

// Main function
int main() {
    // Initialize the password manager
    password_t *passwords;
    init_password_manager(&passwords);

    // Add some passwords to the password manager
    add_password(&passwords, "password1");
    add_password(&passwords, "password2");
    add_password(&passwords, "password3");

    // Get a password from the password manager
    char *password = get_password(&passwords, 1);
    printf("Password: %s\n", password);

    // Delete a password from the password manager
    delete_password(&passwords, 1);

    // Free the password manager
    free_password_manager(&passwords);

    return 0;
}