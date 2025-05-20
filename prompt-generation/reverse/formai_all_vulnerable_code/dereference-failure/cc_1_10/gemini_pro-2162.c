//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

list_t *create_list() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_to_list(list_t *list, char *email) {
    node_t *node = malloc(sizeof(node_t));
    node->email = strdup(email);
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void remove_from_list(list_t *list, char *email) {
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
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
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

int main() {
    list_t *list = create_list();
    add_to_list(list, "john@example.com");
    add_to_list(list, "jane@example.com");
    add_to_list(list, "bob@example.com");
    print_list(list);
    remove_from_list(list, "bob@example.com");
    print_list(list);
    free_list(list);
    return 0;
}