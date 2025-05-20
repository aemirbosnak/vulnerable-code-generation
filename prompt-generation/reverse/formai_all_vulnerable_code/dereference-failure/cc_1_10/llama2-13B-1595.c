//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 1024

struct node {
    char *str;
    struct node *next;
};

void *malloc_impl(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

void free_impl(void *ptr) {
    free(ptr);
}

void *memset_impl(void *ptr, int c, size_t count) {
    memset(ptr, c, count);
    return ptr;
}

struct node *new_list(const char *str) {
    struct node *new_node = malloc_impl(sizeof(struct node));
    new_node->str = malloc_impl(strlen(str) + 1);
    strcpy(new_node->str, str);
    new_node->next = NULL;
    return new_node;
}

void del_list(struct node **head_ref) {
    struct node *curr = *head_ref;
    while (curr != NULL) {
        struct node *next = curr->next;
        free_impl(curr->str);
        free_impl(curr);
        curr = next;
    }
    *head_ref = NULL;
}

int main() {
    struct node *head = NULL;
    head = new_list("Hello");
    head = new_list("World");
    head = new_list("!");

    printf("Initial list: %s\n", head->str);

    del_list(&head);

    printf("Final list: %s\n", head->str);

    return 0;
}