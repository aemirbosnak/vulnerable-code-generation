//GEMINI-pro DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Credential {
    char *service;
    char *username;
    char *password;
};

struct CredentialManager {
    struct Credential *credentials;
    int num_credentials;
    int capacity;
};

struct CredentialManager *create_manager(int initial_capacity) {
    struct CredentialManager *manager = malloc(sizeof(struct CredentialManager));
    manager->credentials = malloc(initial_capacity * sizeof(struct Credential));
    manager->num_credentials = 0;
    manager->capacity = initial_capacity;
    return manager;
}

void destroy_manager(struct CredentialManager *manager) {
    for (int i = 0; i < manager->num_credentials; i++) {
        free(manager->credentials[i].service);
        free(manager->credentials[i].username);
        free(manager->credentials[i].password);
    }
    free(manager->credentials);
    free(manager);
}

void add_credential(struct CredentialManager *manager, char *service, char *username, char *password) {
    if (manager->num_credentials == manager->capacity) {
        manager->capacity *= 2;
        manager->credentials = realloc(manager->credentials, manager->capacity * sizeof(struct Credential));
    }
    manager->credentials[manager->num_credentials].service = strdup(service);
    manager->credentials[manager->num_credentials].username = strdup(username);
    manager->credentials[manager->num_credentials].password = strdup(password);
    manager->num_credentials++;
}

struct Credential *find_credential(struct CredentialManager *manager, char *service) {
    for (int i = 0; i < manager->num_credentials; i++) {
        if (strcmp(manager->credentials[i].service, service) == 0) {
            return &manager->credentials[i];
        }
    }
    return NULL;
}

void print_credentials(struct CredentialManager *manager) {
    for (int i = 0; i < manager->num_credentials; i++) {
        printf("%s: %s/%s\n", manager->credentials[i].service, manager->credentials[i].username, manager->credentials[i].password);
    }
}

int main() {
    struct CredentialManager *manager = create_manager(10);
    add_credential(manager, "Facebook", "johndoe", "password123");
    add_credential(manager, "Google", "janedoe", "password456");
    add_credential(manager, "Amazon", "johndoe", "password789");

    struct Credential *credential = find_credential(manager, "Facebook");
    if (credential != NULL) {
        printf("Found credential for Facebook: %s/%s\n", credential->username, credential->password);
    } else {
        printf("No credential found for Facebook\n");
    }

    print_credentials(manager);

    destroy_manager(manager);

    return 0;
}