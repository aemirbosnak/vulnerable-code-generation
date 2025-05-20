//GEMINI-pro DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the structure of a password entry
typedef struct password_entry {
    char *website;
    char *username;
    char *password;
    struct password_entry *next;
} password_entry;

// Define the head of the linked list of password entries
password_entry *head = NULL;

// Define the function to add a new password entry to the linked list
void add_password_entry(char *website, char *username, char *password) {
    // Allocate memory for the new password entry
    password_entry *new_entry = (password_entry *)malloc(sizeof(password_entry));

    // Set the values of the new password entry
    new_entry->website = strdup(website);
    new_entry->username = strdup(username);
    new_entry->password = strdup(password);
    new_entry->next = NULL;

    // If the linked list is empty, set the head of the linked list to the new password entry
    if (head == NULL) {
        head = new_entry;
    } else {
        // Otherwise, add the new password entry to the end of the linked list
        password_entry *current_entry = head;
        while (current_entry->next != NULL) {
            current_entry = current_entry->next;
        }
        current_entry->next = new_entry;
    }
}

// Define the function to search for a password entry in the linked list
password_entry *search_password_entry(char *website) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return NULL;
    } else {
        // Otherwise, search for the password entry in the linked list
        password_entry *current_entry = head;
        while (current_entry != NULL) {
            if (strcmp(current_entry->website, website) == 0) {
                return current_entry;
            }
            current_entry = current_entry->next;
        }
    }
    // If the password entry was not found, return NULL
    return NULL;
}

// Define the function to delete a password entry from the linked list
void delete_password_entry(char *website) {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    } else {
        // Otherwise, search for the password entry in the linked list
        password_entry *current_entry = head;
        password_entry *previous_entry = NULL;
        while (current_entry != NULL) {
            if (strcmp(current_entry->website, website) == 0) {
                // If the password entry was found, delete it from the linked list
                if (previous_entry == NULL) {
                    // If the password entry is the first entry in the linked list, set the head of the linked list to the next entry
                    head = current_entry->next;
                } else {
                    // Otherwise, set the next pointer of the previous entry to the next entry of the current entry
                    previous_entry->next = current_entry->next;
                }
                // Free the memory allocated for the password entry
                free(current_entry->website);
                free(current_entry->username);
                free(current_entry->password);
                free(current_entry);
                return;
            }
            previous_entry = current_entry;
            current_entry = current_entry->next;
        }
    }
}

// Define the function to print the linked list of password entries
void print_password_entries() {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    } else {
        // Otherwise, print the password entries in the linked list
        password_entry *current_entry = head;
        while (current_entry != NULL) {
            printf("Website: %s\n", current_entry->website);
            printf("Username: %s\n", current_entry->username);
            printf("Password: %s\n\n", current_entry->password);
            current_entry = current_entry->next;
        }
    }
}

// Define the main function
int main() {
    // Add some password entries to the linked list
    add_password_entry("www.google.com", "username1", "password1");
    add_password_entry("www.facebook.com", "username2", "password2");
    add_password_entry("www.twitter.com", "username3", "password3");

    // Search for a password entry in the linked list
    password_entry *entry = search_password_entry("www.google.com");
    if (entry != NULL) {
        printf("Found password entry for %s\n", entry->website);
    } else {
        printf("Password entry for %s not found\n", "www.google.com");
    }

    // Delete a password entry from the linked list
    delete_password_entry("www.facebook.com");

    // Print the linked list of password entries
    print_password_entries();

    return 0;
}