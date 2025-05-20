//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_node {
    char *data;
    struct list_node *next;
};

struct list {
    struct list_node *head;
    struct list_node *tail;
};

void add_to_list(struct list *list, char *data) {
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if (new_node == NULL) {
        printf("Failed to allocate memory\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(struct list *list) {
    struct list_node *node = list->head;
    while (node!= NULL) {
        printf("%s ", node->data);
        node = node->next;
    }
    printf("\n");
}

void free_list(struct list *list) {
    struct list_node *node = list->head;
    while (node!= NULL) {
        struct list_node *temp = node;
        node = node->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    struct list *list = malloc(sizeof(struct list));
    if (list == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    add_to_list(list, "Hello");
    add_to_list(list, "World");
    print_list(list);
    free_list(list);
    return 0;
}