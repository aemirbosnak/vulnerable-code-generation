//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdlib.h>
#include <string.h>

struct Node {
    char *data;
    struct Node *next;
};

struct Node *create_node(char *data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

void free_node(struct Node *node) {
    free(node->data);
    free(node);
}

struct List {
    struct Node *head;
    struct Node *tail;
};

struct List *create_list() {
    struct List *list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void free_list(struct List *list) {
    struct Node *node = list->head;
    while (node != NULL) {
        struct Node *next = node->next;
        free_node(node);
        node = next;
    }
    free(list);
}

void push_back(struct List *list, char *data) {
    struct Node *node = create_node(data);
    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

char *pop_front(struct List *list) {
    if (list->head == NULL) {
        return NULL;
    }
    char *data = strdup(list->head->data);
    struct Node *node = list->head;
    list->head = node->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free_node(node);
    return data;
}

int main() {
    struct List *list = create_list();
    push_back(list, "Hello");
    push_back(list, "World");
    char *data = pop_front(list);
    printf("%s\n", data);
    free(data);
    data = pop_front(list);
    printf("%s\n", data);
    free(data);
    free_list(list);
    return 0;
}