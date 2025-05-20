//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAGIC_NUMBER 0xDEADBEEF

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    struct node *head;
};

void *malloc_with_flair(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("MALLOC FAILED WITH SIZE %zu\n", size);
        return NULL;
    }
    // add some flair to the memory
    *((int *)ptr) = MAGIC_NUMBER;
    return ptr;
}

void free_with_flair(void *ptr) {
    if (ptr == NULL) {
        printf("FREE NULL POINTER\n");
        return;
    }
    // remove the flair from the memory
    int magic = *((int *)ptr);
    if (magic != MAGIC_NUMBER) {
        printf("FREE POINTER WITHOUT MAGIC NUMBER\n");
        return;
    }
    free(ptr);
}

int main() {
    struct linked_list *list = malloc(sizeof(struct linked_list));
    if (list == NULL) {
        printf("MALLOC FAILED FOR LINKED LIST\n");
        return 1;
    }
    list->head = malloc_with_flair(sizeof(struct node));
    if (list->head == NULL) {
        printf("MALLOC FAILED FOR LINKED LIST HEAD\n");
        return 1;
    }
    // add some nodes to the list
    for (int i = 0; i < 10; i++) {
        struct node *node = malloc_with_flair(sizeof(struct node));
        if (node == NULL) {
            printf("MALLOC FAILED FOR NODE %d\n", i);
            return 1;
        }
        node->data = i;
        node->next = list->head;
        list->head = node;
    }
    // print the list
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
    // free the list
    free_with_flair(list);
    return 0;
}