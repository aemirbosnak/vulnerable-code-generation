//FormAI DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct memory_chunk {
    struct memory_chunk *next;
    size_t size;
    int is_free;
};

struct memory_chunk *first_chunk = NULL;

void *custom_malloc(size_t size) {
    struct memory_chunk *chunk, *prev;
    size_t total_size = size + sizeof(struct memory_chunk);

    if(!first_chunk) {
        first_chunk = (struct memory_chunk *) sbrk(total_size);
        first_chunk->next = NULL;
        first_chunk->size = size;
        first_chunk->is_free = 0;
        return (void *) first_chunk + sizeof(struct memory_chunk);
    }

    chunk = first_chunk;

    while(chunk) {
        if(chunk->is_free && chunk->size >= size) {
            if(chunk->size >= total_size + sizeof(struct memory_chunk)) {
                struct memory_chunk *temp = (struct memory_chunk *) (((void *) chunk) + total_size);
                temp->next = chunk->next;
                temp->size = chunk->size - total_size;
                temp->is_free = 1;
                chunk->next = temp;
                chunk->size = size;
            }

            chunk->is_free = 0;
            return (void *) chunk + sizeof(struct memory_chunk);
        }

        prev = chunk;
        chunk = chunk->next;
    }

    chunk = (struct memory_chunk *) sbrk(total_size);
    chunk->next = NULL;
    chunk->size = size;
    chunk->is_free = 0;
    prev->next = chunk;

    return (void *) chunk + sizeof(struct memory_chunk);
}

void custom_free(void *ptr) {
    struct memory_chunk *chunk = (struct memory_chunk *) (ptr - sizeof(struct memory_chunk));
    chunk->is_free = 1;
}

int main() {
    int *a = (int *) custom_malloc(sizeof(int));
    int *b = (int *) custom_malloc(sizeof(int));
    int *c = (int *) custom_malloc(sizeof(int));

    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("c: %p\n", c);

    custom_free(a);

    int *d = (int *) custom_malloc(sizeof(int));

    printf("d: %p\n", d);

    return 0;
}