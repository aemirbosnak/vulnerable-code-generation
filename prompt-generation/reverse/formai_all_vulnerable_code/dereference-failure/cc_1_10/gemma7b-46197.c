//Gemma-7B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

struct password_node {
    char *password;
    struct password_node *next;
};

void add_password(struct password_node **head, char *password) {
    struct password_node *new_node = malloc(sizeof(struct password_node));
    new_node->password = strdup(password);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

char *search_password(struct password_node *head, char *password) {
    while (head) {
        if (strcmp(head->password, password) == 0) {
            return head->password;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    struct password_node *passwords = NULL;

    // Add some passwords
    add_password(&passwords, "secret");
    add_password(&passwords, "my_secret");
    add_password(&passwords, "another_secret");

    // Search for a password
    char *password = search_password(passwords, "my_secret");

    // Print the password
    if (password) {
        printf("Password: %s\n", password);
    } else {
        printf("Password not found.\n");
    }

    return 0;
}