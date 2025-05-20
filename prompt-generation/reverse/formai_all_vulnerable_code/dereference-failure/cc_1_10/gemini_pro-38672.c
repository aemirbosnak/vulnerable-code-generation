//GEMINI-pro DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a password entry
typedef struct password_entry {
    char *service;
    char *username;
    char *password;
} password_entry;

// Linked list to store the password entries
typedef struct password_list {
    password_entry *entry;
    struct password_list *next;
} password_list;

// Function to create a new password entry
password_entry *create_password_entry(char *service, char *username, char *password) {
    password_entry *entry = malloc(sizeof(password_entry));
    if (entry == NULL) {
        return NULL;
    }

    entry->service = malloc(strlen(service) + 1);
    if (entry->service == NULL) {
        free(entry);
        return NULL;
    }
    strcpy(entry->service, service);

    entry->username = malloc(strlen(username) + 1);
    if (entry->username == NULL) {
        free(entry->service);
        free(entry);
        return NULL;
    }
    strcpy(entry->username, username);

    entry->password = malloc(strlen(password) + 1);
    if (entry->password == NULL) {
        free(entry->service);
        free(entry->username);
        free(entry);
        return NULL;
    }
    strcpy(entry->password, password);

    return entry;
}

// Function to add a password entry to the linked list
void add_password_entry(password_list **list, password_entry *entry) {
    password_list *new_entry = malloc(sizeof(password_list));
    if (new_entry == NULL) {
        return;
    }

    new_entry->entry = entry;
    new_entry->next = *list;
    *list = new_entry;
}

// Function to find a password entry by service name
password_entry *find_password_entry(password_list *list, char *service) {
    while (list != NULL) {
        if (strcmp(list->entry->service, service) == 0) {
            return list->entry;
        }

        list = list->next;
    }

    return NULL;
}

// Function to print the password entries
void print_password_entries(password_list *list) {
    while (list != NULL) {
        printf("%s: %s (%s)\n", list->entry->service, list->entry->username, list->entry->password);

        list = list->next;
    }
}

// Main function
int main() {
    // Create a new linked list to store the password entries
    password_list *list = NULL;

    // Add some password entries to the linked list
    add_password_entry(&list, create_password_entry("Facebook", "john.doe", "password123"));
    add_password_entry(&list, create_password_entry("Twitter", "jane.doe", "password456"));
    add_password_entry(&list, create_password_entry("Gmail", "bob.smith", "password789"));

    // Find a password entry by service name
    password_entry *entry = find_password_entry(list, "Facebook");

    // Print the password entry
    if (entry != NULL) {
        printf("Service: %s\n", entry->service);
        printf("Username: %s\n", entry->username);
        printf("Password: %s\n", entry->password);
    } else {
        printf("No password entry found for service: %s\n", "Facebook");
    }

    // Print all the password entries
    printf("\nAll password entries:\n");
    print_password_entries(list);

    return 0;
}