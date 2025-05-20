//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password_record {
    char *username;
    char *password;
    struct password_record *next;
};

struct password_manager {
    struct password_record *first;
    struct password_record *last;
};

struct password_manager *create_password_manager() {
    struct password_manager *manager = malloc(sizeof(struct password_manager));
    manager->first = NULL;
    manager->last = NULL;
    return manager;
}

void add_password(struct password_manager *manager, char *username, char *password) {
    struct password_record *record = malloc(sizeof(struct password_record));
    record->username = strdup(username);
    record->password = strdup(password);
    record->next = NULL;

    if (manager->first == NULL) {
        manager->first = record;
        manager->last = record;
    } else {
        manager->last->next = record;
        manager->last = record;
    }
}

char *get_password(struct password_manager *manager, char *username) {
    struct password_record *record = manager->first;

    while (record != NULL) {
        if (strcmp(record->username, username) == 0) {
            return record->password;
        }
        record = record->next;
    }

    return NULL;
}

void print_passwords(struct password_manager *manager) {
    struct password_record *record = manager->first;

    while (record != NULL) {
        printf("%s: %s\n", record->username, record->password);
        record = record->next;
    }
}

void free_password_manager(struct password_manager *manager) {
    struct password_record *record = manager->first;

    while (record != NULL) {
        struct password_record *next = record->next;
        free(record->username);
        free(record->password);
        free(record);
        record = next;
    }

    free(manager);
}

int main() {
    struct password_manager *manager = create_password_manager();

    add_password(manager, "john", "password1");
    add_password(manager, "mary", "password2");
    add_password(manager, "bob", "password3");

    char *password = get_password(manager, "john");
    printf("Password for john: %s\n", password);

    print_passwords(manager);

    free_password_manager(manager);

    return 0;
}