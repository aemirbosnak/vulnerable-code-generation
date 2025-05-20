//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256

struct node {
    char *data;
    struct node *next;
};

struct list {
    struct node *head;
};

void init_list(struct list *list) {
    list->head = NULL;
}

void insert_node(struct list *list, char *data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    struct list list;

    // Insert some nodes
    insert_node(&list, "apple");
    insert_node(&list, "banana");
    insert_node(&list, "cherry");

    // Print the list
    print_list(&list);

    // Free the memory
    struct node *current = list.head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}