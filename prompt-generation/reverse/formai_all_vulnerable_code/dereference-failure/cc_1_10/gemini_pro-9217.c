//GEMINI-pro DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password data structure
typedef struct {
    char *username;
    char *website;
    char *password;
} Password;

// Node for a linked list of passwords
typedef struct Node {
    Password password;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Function to create a new password
Password *create_password(char *username, char *website, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->username = strdup(username);
    new_password->website = strdup(website);
    new_password->password = strdup(password);
    return new_password;
}

// Function to add a new password to the linked list
void add_password(Password *password) {
    Node *new_node = malloc(sizeof(Node));
    new_node->password = *password;
    new_node->next = head;
    head = new_node;
}

// Function to search for a password
Password *search_password(char *username, char *website) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->password.username, username) == 0 && strcmp(current->password.website, website) == 0) {
            return &current->password;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print all passwords
void print_passwords() {
    Node *current = head;
    while (current != NULL) {
        printf("Username: %s\n", current->password.username);
        printf("Website: %s\n", current->password.website);
        printf("Password: %s\n\n", current->password.password);
        current = current->next;
    }
}

// Function to clear all passwords
void clear_passwords() {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->password.username);
        free(current->password.website);
        free(current->password.password);
        free(current);
        current = next;
    }
    head = NULL;
}

// Main function
int main() {
    // Create some passwords
    Password *password1 = create_password("bob", "example.com", "password1");
    Password *password2 = create_password("alice", "example.com", "password2");
    Password *password3 = create_password("charlie", "example.com", "password3");

    // Add the passwords to the linked list
    add_password(password1);
    add_password(password2);
    add_password(password3);

    // Search for a password
    Password *found_password = search_password("bob", "example.com");
    if (found_password != NULL) {
        printf("Found password: %s\n", found_password->password);
    } else {
        printf("Password not found.\n");
    }

    // Print all passwords
    printf("All passwords:\n");
    print_passwords();

    // Clear all passwords
    clear_passwords();

    return 0;
}