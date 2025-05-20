//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: rigorous
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

void add_node(struct list *list, const char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->email = malloc(strlen(email) + 1);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void remove_node(struct list *list, const char *email) {
    struct node *current_node = list->head;
    struct node *previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->email, email) == 0) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            if (current_node == list->tail) {
                list->tail = previous_node;
            }
            free(current_node->email);
            free(current_node);
            list->size--;
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

void print_list(const struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%s\n", current_node->email);
        current_node = current_node->next;
    }
}

int main() {
    struct list *list = create_list();
    add_node(list, "alice@example.com");
    add_node(list, "bob@example.com");
    add_node(list, "charlie@example.com");
    print_list(list);
    remove_node(list, "bob@example.com");
    print_list(list);
    return 0;
}