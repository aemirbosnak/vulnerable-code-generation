//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password {
    char *name; // name of the password
    char *value; // value of the password
    struct password *next; // pointer to the next password in the list
} Password;

Password* create_password(char *name, char *value) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->value = strdup(value);
    new_password->next = NULL;
    return new_password;
}

void free_password(Password *password) {
    free(password->name);
    free(password->value);
    free(password);
}

void add_password(Password **head, Password *new_password) {
    if (*head == NULL) {
        *head = new_password;
        return;
    }
    Password *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_password;
}

Password* get_password(Password *head, char *name) {
    Password *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void display_passwords(Password *head) {
    Password *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->value);
        current = current->next;
    }
}

void delete_password(Password **head, char *name) {
    Password *current = *head;
    Password *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free_password(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    Password *passwords = NULL;

    add_password(&passwords, create_password("Facebook", "mypassword123"));
    add_password(&passwords, create_password("Gmail", "secretpassword"));
    add_password(&passwords, create_password("Twitter", "password123"));

    printf("Current Passwords:\n");
    display_passwords(passwords);

    printf("\nDelete Twitter Password\n");
    delete_password(&passwords, "Twitter");

    printf("\nCurrent Passwords:\n");
    display_passwords(passwords);

    Password *facebook_password = get_password(passwords, "Facebook");
    if (facebook_password != NULL) {
        printf("\nFacebook Password: %s\n", facebook_password->value);
    } else {
        printf("\nFacebook Password not found.\n");
    }

    printf("\nAdd LinkedIn Password\n");
    add_password(&passwords, create_password("LinkedIn", "newpassword"));

    printf("\nCurrent Passwords:\n");
    display_passwords(passwords);

    return 0;
}