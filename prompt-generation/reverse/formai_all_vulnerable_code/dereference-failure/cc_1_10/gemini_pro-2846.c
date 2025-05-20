//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: accurate
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

void add_email(list_t *list, char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->email = strdup(email);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void remove_email(list_t *list, char *email) {
    node_t *curr = list->head;
    node_t *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) {
            if (prev == NULL) {
                list->head = curr->next;
            } else {
                prev->next = curr->next;
            }

            free(curr->email);
            free(curr);

            if (list->tail == curr) {
                list->tail = prev;
            }

            break;
        }

        prev = curr;
        curr = curr->next;
    }
}

void print_list(list_t *list) {
    node_t *curr = list->head;

    while (curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
}

int main() {
    list_t *list = create_list();

    add_email(list, "john@example.com");
    add_email(list, "jane@example.com");
    add_email(list, "bob@example.com");

    print_list(list);

    remove_email(list, "jane@example.com");

    print_list(list);

    return 0;
}