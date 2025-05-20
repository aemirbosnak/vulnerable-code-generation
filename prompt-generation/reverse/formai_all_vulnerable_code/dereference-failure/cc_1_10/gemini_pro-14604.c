//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *list_create() {
    list_t *list = malloc(sizeof(list_t));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_destroy(list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node->data);
        free(node);
        node = next;
    }
    free(list);
}

int list_add(list_t *list, char *data) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        return -1;
    }
    node->data = strdup(data);
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
    return 0;
}

char *list_get(list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    node_t *node = list->head;
    while (index > 0) {
        node = node->next;
        index--;
    }
    return node->data;
}

int list_remove(list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    node_t *node = list->head;
    if (index == 0) {
        list->head = node->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    } else {
        while (index > 1) {
            node = node->next;
            index--;
        }
        node->next = node->next->next;
        if (node->next == NULL) {
            list->tail = node;
        }
    }
    free(node->data);
    free(node);
    list->size--;
    return 0;
}

int main() {
    list_t *list = list_create();
    if (list == NULL) {
        return EXIT_FAILURE;
    }

    // Add some data to the list.
    list_add(list, "Hello");
    list_add(list, "World");
    list_add(list, "!");

    // Print the data in the list.
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list_get(list, i));
    }

    // Remove some data from the list.
    list_remove(list, 1);

    // Print the data in the list again.
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list_get(list, i));
    }

    // Destroy the list.
    list_destroy(list);

    return EXIT_SUCCESS;
}