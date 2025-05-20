//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store password information
typedef struct {
    char *username;
    char *password;
    struct password_info *next;
} password_info_t;

// Function to create a new password entry
password_info_t *create_password_entry(char *username, char *password) {
    password_info_t *new_entry = (password_info_t *) malloc(sizeof(password_info_t));
    new_entry->username = username;
    new_entry->password = password;
    new_entry->next = NULL;
    return new_entry;
}

// Function to print all password entries
void print_password_entries(password_info_t *head) {
    if (head == NULL) {
        printf("No password entries found.\n");
        return;
    }

    printf("Username: %s, Password: %s\n", head->username, head->password);
    print_password_entries(head->next);
}

// Function to search for a password entry
password_info_t *search_password_entry(password_info_t *head, char *username) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->username, username) == 0) {
        return head;
    }

    return search_password_entry(head->next, username);
}

// Function to update a password entry
void update_password_entry(password_info_t *head, char *username, char *new_password) {
    password_info_t *found_entry = search_password_entry(head, username);
    if (found_entry == NULL) {
        printf("Password entry not found.\n");
        return;
    }

    found_entry->password = new_password;
}

// Function to remove a password entry
void remove_password_entry(password_info_t *head, char *username) {
    password_info_t *found_entry = search_password_entry(head, username);
    if (found_entry == NULL) {
        printf("Password entry not found.\n");
        return;
    }

    if (found_entry == head) {
        head = found_entry->next;
    }

    free(found_entry);
}

int main() {
    password_info_t *head = NULL;

    // Add password entries
    head = create_password_entry("user1", "password1");
    head = create_password_entry("user2", "password2");
    head = create_password_entry("user3", "password3");

    // Print all password entries
    print_password_entries(head);

    // Search for a password entry
    password_info_t *found_entry = search_password_entry(head, "user2");
    if (found_entry != NULL) {
        printf("Found password entry for user2: %s\n", found_entry->password);
    } else {
        printf("Password entry for user2 not found.\n");
    }

    // Update a password entry
    update_password_entry(head, "user2", "new_password2");

    // Remove a password entry
    remove_password_entry(head, "user3");

    return 0;
}