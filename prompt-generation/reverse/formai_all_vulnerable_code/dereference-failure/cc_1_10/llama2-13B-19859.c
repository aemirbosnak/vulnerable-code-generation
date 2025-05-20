//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <utime.h>

#define MAX_PASSWORDS 10
#define MAX_ENTRIES 100
#define PASSWORD_LENGTH 20
#define SALT_LENGTH 10

typedef struct password_entry {
    char *username;
    char *password;
    struct password_entry *next;
} password_entry_t;

password_entry_t *password_list = NULL;

void init_password_list();
void add_password(char *username, char *password);
void remove_password(char *username);
void print_passwords();

int main() {
    init_password_list();

    char *username = "johndoe";
    char *password = "password123";
    add_password(username, password);

    username = "janedoe";
    password = "password456";
    add_password(username, password);

    print_passwords();

    return 0;
}

void init_password_list() {
    password_list = malloc(sizeof(password_entry_t));
    password_list->next = NULL;
}

void add_password(char *username, char *password) {
    password_entry_t *new_entry = malloc(sizeof(password_entry_t));
    new_entry->username = username;
    new_entry->password = password;
    new_entry->next = password_list;
    password_list = new_entry;
}

void remove_password(char *username) {
    password_entry_t *current = password_list;
    password_entry_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            if (prev == NULL) {
                password_list = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

void print_passwords() {
    password_entry_t *current = password_list;

    while (current != NULL) {
        printf("%s: %s\n", current->username, current->password);
        current = current->next;
    }
}