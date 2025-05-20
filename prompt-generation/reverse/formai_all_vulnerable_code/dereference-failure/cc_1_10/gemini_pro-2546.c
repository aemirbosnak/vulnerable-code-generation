//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    char *email;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
    int size;
};

struct list *create_list() {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_to_list(struct list *list, char *name, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->email = strdup(email);
    new_node->next = NULL;

    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void remove_from_list(struct list *list, char *name) {
    struct node *current_node = list->head;
    struct node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            if (current_node == list->tail) {
                list->tail = previous_node;
            }

            free(current_node->name);
            free(current_node->email);
            free(current_node);

            list->size--;

            break;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

void print_list(struct list *list) {
    struct node *current_node = list->head;

    while (current_node != NULL) {
        printf("%s: %s\n", current_node->name, current_node->email);
        current_node = current_node->next;
    }
}

void free_list(struct list *list) {
    struct node *current_node = list->head;

    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->name);
        free(current_node->email);
        free(current_node);
        current_node = next_node;
    }

    free(list);
}

int main() {
    struct list *list = create_list();

    add_to_list(list, "John", "john@example.com");
    add_to_list(list, "Jane", "jane@example.com");
    add_to_list(list, "Bob", "bob@example.com");
    add_to_list(list, "Alice", "alice@example.com");

    print_list(list);

    remove_from_list(list, "Bob");

    printf("\n");

    print_list(list);

    free_list(list);

    return 0;
}