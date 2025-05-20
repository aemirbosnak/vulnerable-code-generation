//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: synchronous
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
    int size;
} list_t;

list_t *create_list() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

int add_to_list(list_t *list, char *email) {
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

    list->size++;
    return 0;
}

int remove_from_list(list_t *list, char *email) {
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
            return 0;
        }

        previous = current;
        current = current->next;
    }

    return -1;
}

int find_in_list(list_t *list, char *email) {
    node_t *current = list->head;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            return 1;
        }

        current = current->next;
    }

    return 0;
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

    add_to_list(list, "john@example.com");
    add_to_list(list, "mary@example.com");
    add_to_list(list, "bob@example.com");

    print_list(list);

    remove_from_list(list, "mary@example.com");

    print_list(list);

    int found = find_in_list(list, "bob@example.com");
    printf("Found bob@example.com: %d\n", found);

    destroy_list(list);

    return 0;
}