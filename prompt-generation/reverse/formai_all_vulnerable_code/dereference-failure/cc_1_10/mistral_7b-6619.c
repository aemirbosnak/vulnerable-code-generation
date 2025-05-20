//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define HEARTS "♥♥♥♥♥"
#define RAM_SIZE (1024 * 1024) // 1MB
#define BUF_SIZE 4096

typedef struct {
    char name[20];
    size_t size;
    char* ptr;
} AllocBlock;

AllocBlock* blocks = NULL;
size_t num_blocks = 0;
size_t total_allocated = 0;

void* my_malloc(size_t size) {
    if (num_blocks >= 100) {
        printf("Too many allocations!\n");
        exit(EXIT_FAILURE);
    }

    AllocBlock* new_block = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (new_block == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    strcpy(new_block->name, "Anonymous Block");
    new_block->size = size;
    new_block->ptr = (char*) new_block + sizeof(AllocBlock);

    total_allocated += sizeof(AllocBlock) + size;
    num_blocks++;

    return new_block->ptr;
}

void print_ram_status() {
    printf("\n");
    printf("%s RAM USAGE MONITOR\n", HEARTS);
    printf("---------------------\n");
    printf("Total Allocated: %lu bytes\n", total_allocated);
    printf("Allocated Blocks: %d\n", num_blocks);
    printf("---------------------\n");

    AllocBlock* current_block = blocks;
    while (current_block != NULL) {
        printf("%s: Size %lu bytes, Address %p\n", current_block->name, current_block->size, current_block);
        current_block = (AllocBlock*) current_block->ptr;
    }
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    int* a = (int*) my_malloc(sizeof(int));
    *a = 42;

    char* str = (char*) my_malloc(5 * sizeof(char));
    strcpy(str, "Hello, World!");

    int i;
    for (i = 0; i < 10; i++) {
        int* num = (int*) my_malloc(sizeof(int));
        *num = i * i;

        print_ram_status();
    }

    for (i = 0; i < num_blocks; i++) {
        free(blocks[i].ptr);
    }

    munmap(blocks, num_blocks * BUF_SIZE);

    return 0;
}