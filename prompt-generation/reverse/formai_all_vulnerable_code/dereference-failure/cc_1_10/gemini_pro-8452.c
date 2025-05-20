//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void free_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

bool add_email(list_t *list, char *email) {
    if (email == NULL || strlen(email) == 0) {
        return false;
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->email = malloc(strlen(email) + 1);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    return true;
}

bool remove_email(list_t *list, char *email) {
    if (email == NULL || strlen(email) == 0) {
        return false;
    }

    node_t *current = list->head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == list->tail) {
                list->tail = previous;
            }

            free(current->email);
            free(current);
            list->size--;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

void print_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    list_t *list = create_list();

    add_email(list, "alice@example.com");
    add_email(list, "bob@example.com");
    add_email(list, "charlie@example.com");
    add_email(list, "dave@example.com");
    add_email(list, "eve@example.com");

    print_list(list);

    remove_email(list, "bob@example.com");
    remove_email(list, "dave@example.com");

    printf("\n");
    print_list(list);

    free_list(list);

    return 0;
}