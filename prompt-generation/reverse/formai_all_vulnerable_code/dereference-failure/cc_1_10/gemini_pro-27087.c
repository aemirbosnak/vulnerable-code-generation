//GEMINI-pro DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password_entry {
    char *username;
    char *password;
    struct password_entry *next;
} password_entry;

typedef struct password_list {
    password_entry *first;
    password_entry *last;
} password_list;

password_list *passwords = NULL;

// Function to create a new password entry
password_entry *create_password_entry(char *username, char *password) {
    password_entry *entry = malloc(sizeof(password_entry));
    entry->username = strdup(username);
    entry->password = strdup(password);
    entry->next = NULL;
    return entry;
}

// Function to add a new password entry to the list
void add_password_entry(char *username, char *password) {
    password_entry *entry = create_password_entry(username, password);
    if (passwords == NULL) {
        passwords = malloc(sizeof(password_list));
        passwords->first = entry;
        passwords->last = entry;
    } else {
        passwords->last->next = entry;
        passwords->last = entry;
    }
}

// Function to find a password entry by username
password_entry *find_password_entry(char *username) {
    password_entry *entry = passwords->first;
    while (entry != NULL) {
        if (strcmp(entry->username, username) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// Function to print a password entry
void print_password_entry(password_entry *entry) {
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n", entry->password);
}

// Function to free a password entry
void free_password_entry(password_entry *entry) {
    free(entry->username);
    free(entry->password);
    free(entry);
}

// Function to free the entire password list
void free_password_list() {
    password_entry *entry = passwords->first;
    while (entry != NULL) {
        password_entry *next = entry->next;
        free_password_entry(entry);
        entry = next;
    }
    free(passwords);
}

int main() {
    // Add some password entries to the list
    add_password_entry("john", "password1");
    add_password_entry("mary", "password2");
    add_password_entry("bob", "password3");

    // Print the list of password entries
    password_entry *entry = passwords->first;
    while (entry != NULL) {
        print_password_entry(entry);
        entry = entry->next;
    }

    // Find a password entry by username
    entry = find_password_entry("mary");
    if (entry != NULL) {
        printf("Found password entry for user %s\n", entry->username);
    } else {
        printf("Could not find password entry for user mary\n");
    }

    // Free the password list
    free_password_list();

    return 0;
}