//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void init_mem(void* ptr, size_t size) {
    memset(ptr, 0, size);
}

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    init_mem(ptr, size);
    return ptr;
}

void* my_calloc(size_t count, size_t size) {
    void* ptr = calloc(count, size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    init_mem(ptr, count * size);
    return ptr;
}

void my_free(void* ptr) {
    free(ptr);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    head = my_malloc(sizeof(Node));
    tail = my_malloc(sizeof(Node));

    head->data = 1;
    head->next = tail;

    tail->data = 2;
    tail->next = NULL;

    printf("Linked list created:\n");
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    my_free(head);
    my_free(tail);

    return 0;
}