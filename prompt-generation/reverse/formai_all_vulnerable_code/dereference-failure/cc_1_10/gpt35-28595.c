//FormAI DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORD_SIZE 128
#define MAX_USERNAME_SIZE 128
#define MAX_ENTRIES 10

// define a struct for password entries
typedef struct password_entry {
    char *username;
    char *password;
    struct password_entry *next;
} password_entry_t;

// function to create a new password entry
password_entry_t* create_password_entry(const char *username, const char *password) {
    password_entry_t *entry = (password_entry_t*)malloc(sizeof(password_entry_t));
    entry->username = (char*)malloc(strlen(username)+1);
    entry->password = (char*)malloc(strlen(password)+1);
    strcpy(entry->username, username);
    strcpy(entry->password, password);
    entry->next = NULL;
    return entry;
}

// function to add a new password entry to a linked list
void add_password_entry(password_entry_t **head, password_entry_t *entry) {
    if (*head == NULL) {
        *head = entry;
    } else {
        password_entry_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
    }
}

// function to find a password by username
char* find_password_by_username(password_entry_t *head, const char *username) {
    while (head != NULL) {
        if (strcmp(head->username, username) == 0) {
            return head->password;
        }
        head = head->next;
    }
    return NULL;
}

// function to delete a password entry
void delete_password_entry(password_entry_t **head, const char *username) {
    password_entry_t *current = *head;
    password_entry_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->username);
            free(current->password);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    password_entry_t *head = NULL;

    // add some initial password entries to the list
    add_password_entry(&head, create_password_entry("user1", "password1"));
    add_password_entry(&head, create_password_entry("user2", "password2"));
    add_password_entry(&head, create_password_entry("user3", "password3"));
    add_password_entry(&head, create_password_entry("user4", "password4"));
    add_password_entry(&head, create_password_entry("user5", "password5"));

    // get a password by username
    char *password = find_password_by_username(head, "user3");
    if (password != NULL) {
        printf("Password for user3: %s\n", password);
    } else {
        printf("User3 not found.\n");
    }

    // delete a password entry
    delete_password_entry(&head, "user4");

    // add a new password entry
    add_password_entry(&head, create_password_entry("user6", "password6"));

    // print all passwords
    password_entry_t *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->username, current->password);
        current = current->next;
    }

    // free memory
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current->username);
        free(current->password);
        free(current);
    }

    return 0;
}