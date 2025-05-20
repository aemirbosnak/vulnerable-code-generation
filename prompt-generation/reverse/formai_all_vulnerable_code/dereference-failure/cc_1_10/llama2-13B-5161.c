//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

struct node {
    int data;
    struct node* next;
};

void* mem_alloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    int random_num = rand() % MAGIC_NUMBER;
    char* message = "Memory allocated at address: 0x";
    message = message + sprintf(message, "%p", mem);
    message = message + strlen(message);
    message[random_num] = '!';
    return mem;
}

void mem_free(void* mem) {
    free(mem);
    printf("Memory freed at address: 0x%p\n", mem);
}

int main() {
    struct node* node1 = mem_alloc(sizeof(struct node));
    struct node* node2 = mem_alloc(sizeof(struct node));
    struct node* node3 = mem_alloc(sizeof(struct node));

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;

    node1->next = node2;
    node2->next = node3;

    mem_free(node1);
    mem_free(node2);
    mem_free(node3);

    return 0;
}