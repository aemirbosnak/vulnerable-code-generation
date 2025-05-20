//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct neon_node {
    int data;
    struct neon_node *next;
    struct neon_node *prev;
} neon_node;

typedef struct neon_list {
    struct neon_node *head;
    struct neon_node *tail;
    size_t size;
} neon_list;

neon_list *neon_list_init() {
    neon_list *list = malloc(sizeof(neon_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void neon_list_push_back(neon_list *list, int data) {
    neon_node *new_node = malloc(sizeof(neon_node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    if (list->head == NULL) {
        list->head = new_node;
    }
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size++;
}

int neon_list_pop_back(neon_list *list) {
    if (list->head == NULL) {
        return -1;
    }
    int data = list->tail->data;
    neon_node *old_tail = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(old_tail);
    list->size--;
    return data;
}

void neon_list_print(neon_list *list) {
    printf("Neon List: ");
    neon_node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

neon_list *neon_list_clone(neon_list *list) {
    neon_list *new_list = neon_list_init();
    neon_node *current = list->head;
    while (current != NULL) {
        neon_list_push_back(new_list, current->data);
        current = current->next;
    }
    return new_list;
}

int main() {
    srand(time(NULL));
    neon_list *list = neon_list_init();
    for (int i = 0; i < 10; i++) {
        neon_list_push_back(list, rand() % 100);
    }
    neon_list_print(list);
    neon_list *clone = neon_list_clone(list);
    neon_list_print(clone);
    neon_list_pop_back(clone);
    neon_list_print(clone);
    neon_list_pop_back(clone);
    neon_list_print(clone);
    return 0;
}