//GEMINI-pro DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char *website;
    char *username;
    char *password;
};

struct password_manager {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords;
};

struct password_manager *password_manager_create() {
    struct password_manager *manager = malloc(sizeof(struct password_manager));
    manager->num_passwords = 0;
    return manager;
}

void password_manager_destroy(struct password_manager *manager) {
    for (int i = 0; i < manager->num_passwords; i++) {
        free(manager->passwords[i].website);
        free(manager->passwords[i].username);
        free(manager->passwords[i].password);
    }
    free(manager);
}

void password_manager_add_password(struct password_manager *manager, char *website, char *username, char *password) {
    if (manager->num_passwords == MAX_PASSWORDS) {
        fprintf(stderr, "Error: Password manager is full\n");
        return;
    }
    manager->passwords[manager->num_passwords].website = strdup(website);
    manager->passwords[manager->num_passwords].username = strdup(username);
    manager->passwords[manager->num_passwords].password = strdup(password);
    manager->num_passwords++;
}

char *password_manager_get_password(struct password_manager *manager, char *website, char *username) {
    for (int i = 0; i < manager->num_passwords; i++) {
        if (strcmp(manager->passwords[i].website, website) == 0 && strcmp(manager->passwords[i].username, username) == 0) {
            return manager->passwords[i].password;
        }
    }
    return NULL;
}

void password_manager_print(struct password_manager *manager) {
    for (int i = 0; i < manager->num_passwords; i++) {
        printf("%s %s %s\n", manager->passwords[i].website, manager->passwords[i].username, manager->passwords[i].password);
    }
}

int main() {
    struct password_manager *manager = password_manager_create();
    password_manager_add_password(manager, "example.com", "username", "password");
    password_manager_add_password(manager, "anotherwebsite.com", "anotherusername", "anotherpassword");
    char *password = password_manager_get_password(manager, "example.com", "username");
    printf("Password for example.com is: %s\n", password);
    password_manager_print(manager);
    password_manager_destroy(manager);
    return 0;
}