//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
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

void free_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

int add_to_list(struct list *list, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->email = strdup(email);
    new_node->next = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
    return 0;
}

int remove_from_list(struct list *list, char *email) {
    struct node *current = list->head;
    struct node *previous = NULL;
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

int find_in_list(struct list *list, char *email) {
    struct node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            return 0;
        }
        current = current->next;
    }
    return -1;
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    struct list *list = create_list();
    add_to_list(list, "a@example.com");
    add_to_list(list, "b@example.com");
    add_to_list(list, "c@example.com");
    print_list(list);
    remove_from_list(list, "b@example.com");
    print_list(list);
    free_list(list);
    return 0;
}