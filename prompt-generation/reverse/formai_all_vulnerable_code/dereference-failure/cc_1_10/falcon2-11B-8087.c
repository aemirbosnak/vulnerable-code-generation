//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int size;
    int* data;
} Memory;

void initialize_memory(Memory* mem, int size) {
    mem->size = size;
    mem->data = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        mem->data[i] = 0;
    }
}

int compare_memories(const void* m1, const void* m2) {
    Memory* m1_mem = (Memory*) m1;
    Memory* m2_mem = (Memory*) m2;

    if (m1_mem->size!= m2_mem->size) {
        return 1;
    }

    for (int i = 0; i < m1_mem->size; i++) {
        if (m1_mem->data[i]!= m2_mem->data[i]) {
            return 1;
        }
    }

    return 0;
}

void print_memory(const Memory* mem) {
    for (int i = 0; i < mem->size; i++) {
        printf("%d ", mem->data[i]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    Memory mem1, mem2;

    initialize_memory(&mem1, size);
    initialize_memory(&mem2, size);

    memset(mem1.data, 1, size * sizeof(int));
    memset(mem2.data, 2, size * sizeof(int));

    qsort((void*) &mem1, 1, sizeof(Memory), compare_memories);
    qsort((void*) &mem2, 1, sizeof(Memory), compare_memories);

    printf("Memory 1:\n");
    print_memory(&mem1);
    printf("Memory 2:\n");
    print_memory(&mem2);

    free(mem1.data);
    free(mem2.data);

    return 0;
}