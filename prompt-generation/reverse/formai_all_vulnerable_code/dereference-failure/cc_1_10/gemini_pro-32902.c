//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
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
};

struct node *create_node(char *name, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->email = malloc(strlen(email) + 1);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

struct list *create_list() {
    struct list *new_list = malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

void add_node(struct list *list, char *name, char *email) {
    struct node *new_node = create_node(name, email);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%s <%s>\n", current_node->name, current_node->email);
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
    add_node(list, "John Smith", "john.smith@example.com");
    add_node(list, "Jane Doe", "jane.doe@example.com");
    add_node(list, "Alice Jones", "alice.jones@example.com");
    print_list(list);
    free_list(list);
    return 0;
}