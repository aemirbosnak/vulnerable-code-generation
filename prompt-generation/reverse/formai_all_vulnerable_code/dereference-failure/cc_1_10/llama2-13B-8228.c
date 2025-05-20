//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAGIC_NUMBER 42

struct node {
    int data;
    struct node* next;
};

void* mem_alloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return mem;
}

void mem_free(void* mem) {
    free(mem);
    printf("Memory freed successfully\n");
}

struct node* new_node(int data) {
    struct node* node = mem_alloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    head = new_node(MAGIC_NUMBER);
    head->next = new_node(MAGIC_NUMBER + 1);
    head->next->next = new_node(MAGIC_NUMBER + 2);
    head->next->next->next = new_node(MAGIC_NUMBER + 3);

    print_list(head);

    mem_free(head);
    return 0;
}