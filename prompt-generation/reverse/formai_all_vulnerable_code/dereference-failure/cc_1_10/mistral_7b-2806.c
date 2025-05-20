//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RAM_SIZE 1024 * 1024 // 1 MB
#define HEADER_SIZE 16
#define BLOCK_SIZE 32
#define FILE_NAME "/tmp/ram_usage.dat"

typedef struct _RamBlock {
    size_t size;
    char data[BLOCK_SIZE - HEADER_SIZE];
    struct _RamBlock* next;
} RamBlock;

RamBlock* head = NULL;
RamBlock* current = NULL;

void init_ram_monitor() {
    int fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    mmap(&head, RAM_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (head == MAP_FAILED) {
        perror("Error mapping memory");
        exit(EXIT_FAILURE);
    }

    head->size = 0;
    head->next = NULL;

    close(fd);
}

void free_ram_monitor() {
    if (head != NULL) {
        RamBlock* next_block = NULL;
        RamBlock* current_block = head;

        while (current_block != NULL) {
            next_block = current_block->next;
            munmap(current_block, current_block->size + HEADER_SIZE);
            current_block = next_block;
        }

        head = NULL;
    }
}

void write_to_ram(const char* data, size_t size) {
    if (head->size + size + HEADER_SIZE > RAM_SIZE) {
        fprintf(stderr, "RAM is full, can't allocate %zu bytes\n", size);
        return;
    }

    if (current == NULL) {
        current = (RamBlock*)((char*)head + head->size);
        current->size = 0;
    }

    current->size = size;
    memcpy(current->data, data, size);

    head->size += size + HEADER_SIZE;
    current = NULL;
}

size_t get_ram_usage() {
    size_t usage = head->size;
    RamBlock* current_block = head;

    while (current_block->next != NULL) {
        usage += current_block->size + HEADER_SIZE;
        current_block = current_block->next;
    }

    return usage;
}

void print_ram_usage() {
    printf("RAM usage:\n");
    printf("  Total: %zu bytes\n", RAM_SIZE);
    printf("  Used: %zu bytes\n", get_ram_usage());
    printf("  Free: %zu bytes\n", RAM_SIZE - get_ram_usage());
}

int main() {
    init_ram_monitor();

    const char* message = "Hello, world!";
    write_to_ram(message, strlen(message) + 1);

    print_ram_usage();

    free_ram_monitor();

    return 0;
}