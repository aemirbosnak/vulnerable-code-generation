//GEMINI-pro DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious way to store passwords
typedef struct {
    char *name;
    char *password;
} password_t;

// A curious way to manage passwords
typedef struct {
    password_t *passwords;
    int num_passwords;
} password_manager_t;

// Create a new password manager
password_manager_t *password_manager_new() {
    password_manager_t *manager = malloc(sizeof(password_manager_t));
    manager->passwords = NULL;
    manager->num_passwords = 0;
    return manager;
}

// Add a new password to the manager
void password_manager_add(password_manager_t *manager, char *name, char *password) {
    manager->passwords = realloc(manager->passwords, (manager->num_passwords + 1) * sizeof(password_t));
    manager->passwords[manager->num_passwords].name = strdup(name);
    manager->passwords[manager->num_passwords].password = strdup(password);
    manager->num_passwords++;
}

// Get a password from the manager
char *password_manager_get(password_manager_t *manager, char *name) {
    for (int i = 0; i < manager->num_passwords; i++) {
        if (strcmp(manager->passwords[i].name, name) == 0) {
            return manager->passwords[i].password;
        }
    }
    return NULL;
}

// Delete a password from the manager
void password_manager_delete(password_manager_t *manager, char *name) {
    for (int i = 0; i < manager->num_passwords; i++) {
        if (strcmp(manager->passwords[i].name, name) == 0) {
            free(manager->passwords[i].name);
            free(manager->passwords[i].password);
            for (int j = i; j < manager->num_passwords - 1; j++) {
                manager->passwords[j] = manager->passwords[j + 1];
            }
            manager->num_passwords--;
            return;
        }
    }
}

// Free the memory used by the manager
void password_manager_free(password_manager_t *manager) {
    for (int i = 0; i < manager->num_passwords; i++) {
        free(manager->passwords[i].name);
        free(manager->passwords[i].password);
    }
    free(manager->passwords);
    free(manager);
}

// A curious way to use the password manager
int main() {
    password_manager_t *manager = password_manager_new();
    password_manager_add(manager, "Alice", "password1");
    password_manager_add(manager, "Bob", "password2");
    char *password = password_manager_get(manager, "Alice");
    printf("Alice's password is %s\n", password);
    password_manager_delete(manager, "Bob");
    password_manager_free(manager);
    return 0;
}