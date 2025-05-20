//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
    int size;
} linked_list_t;

linked_list_t *create_linked_list(void) {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void destroy_linked_list(linked_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    free(list);
}

int insert_at_head(linked_list_t *list, char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = strdup(data);
    new_node->next = list->head;

    if (list->head == NULL) {
        list->tail = new_node;
    }

    list->head = new_node;
    list->size++;

    return 0;
}

int insert_at_tail(linked_list_t *list, char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = strdup(data);
    new_node->next = NULL;

    if (list->tail == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }

    list->tail = new_node;
    list->size++;

    return 0;
}

int insert_at_index(linked_list_t *list, char *data, int index) {
    if (index < 0 || index > list->size) {
        return -1;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = strdup(data);

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else if (index == list->size) {
        new_node->next = NULL;
        list->tail->next = new_node;
    } else {
        node_t *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    list->size++;

    return 0;
}

int delete_at_head(linked_list_t *list) {
    if (list->size == 0) {
        return -1;
    }

    node_t *current = list->head;
    list->head = current->next;

    if (list->size == 1) {
        list->tail = NULL;
    }

    free(current->data);
    free(current);
    list->size--;

    return 0;
}

int delete_at_tail(linked_list_t *list) {
    if (list->size == 0) {
        return -1;
    }

    node_t *current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }

    node_t *to_delete = current->next;
    list->tail = current;
    current->next = NULL;

    free(to_delete->data);
    free(to_delete);
    list->size--;

    return 0;
}

int delete_at_index(linked_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }

    node_t *current = list->head;
    if (index == 0) {
        list->head = current->next;
    } else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        node_t *to_delete = current->next;
        current->next = to_delete->next;

        if (index == list->size - 1) {
            list->tail = current;
        }

        free(to_delete->data);
        free(to_delete);
        list->size--;
    }

    return 0;
}

int find_index_of(linked_list_t *list, char *data) {
    node_t *current = list->head;
    int index = 0;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}

void print_linked_list(linked_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main(void) {
    linked_list_t *list = create_linked_list();

    insert_at_head(list, "Hello");
    insert_at_tail(list, "World");
    insert_at_index(list, "!", 1);

    print_linked_list(list); // Output: Hello ! World

    delete_at_head(list);
    delete_at_tail(list);
    delete_at_index(list, 0);

    print_linked_list(list); // Output:

    destroy_linked_list(list);

    return 0;
}