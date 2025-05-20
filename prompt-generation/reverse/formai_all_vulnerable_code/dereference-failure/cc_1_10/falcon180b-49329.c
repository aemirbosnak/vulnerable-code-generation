//Falcon-180B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    void *data;
    struct node *next;
};

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr!= NULL) {
        free(ptr);
    }
}

struct node *my_calloc(size_t count, size_t size) {
    struct node *head = NULL;
    void *ptr = my_malloc(count * size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    head = (struct node *) ptr;
    for (int i = 0; i < count - 1; i++) {
        head->next = (struct node *) ((char *) head + size);
        head = head->next;
    }
    head->next = NULL;
    return head;
}

void my_realloc(void **ptr, size_t size) {
    void *new_ptr = realloc(*ptr, size);
    if (new_ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    *ptr = new_ptr;
}

int main() {
    int size = 10;
    struct node *head = my_calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        head->data = i;
        head = head->next;
    }
    printf("Linked list created:\n");
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    my_realloc(&head, size * 2);
    printf("Linked list resized:\n");
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    my_free(head);
    return 0;
}