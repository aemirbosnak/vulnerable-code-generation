//GEMINI-pro DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char *username;
    char *password;
};

struct linked_list {
    struct password *data;
    struct linked_list *next;
};

struct linked_list *head = NULL;

void add_password(char *username, char *password) {
    struct linked_list *new_node = malloc(sizeof(struct linked_list));
    new_node->data = malloc(sizeof(struct password));
    new_node->data->username = malloc(strlen(username) + 1);
    strcpy(new_node->data->username, username);
    new_node->data->password = malloc(strlen(password) + 1);
    strcpy(new_node->data->password, password);
    new_node->next = head;
    head = new_node;
}

void print_passwords() {
    struct linked_list *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->data->username, current->data->password);
        current = current->next;
    }
}

void free_passwords() {
    struct linked_list *current = head;
    while (current != NULL) {
        struct linked_list *next = current->next;
        free(current->data->username);
        free(current->data->password);
        free(current->data);
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    add_password("admin", "password");
    add_password("user1", "password1");
    add_password("user2", "password2");
    print_passwords();
    free_passwords();
    return 0;
}