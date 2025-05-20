//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

typedef struct {
    char *name;
    size_t size;
} mem_info_t;

static mem_info_t *mem_info = NULL;
static size_t mem_info_count = 0;

static void add_mem_info(char *name, size_t size) {
    mem_info = realloc(mem_info, sizeof(mem_info_t) * (mem_info_count + 1));
    mem_info[mem_info_count].name = strdup(name);
    mem_info[mem_info_count].size = size;
    mem_info_count++;
}

static void print_mem_info() {
    for (size_t i = 0; i < mem_info_count; i++) {
        printf("%s: %zu bytes\n", mem_info[i].name, mem_info[i].size);
    }
}

static void free_mem_info() {
    for (size_t i = 0; i < mem_info_count; i++) {
        free(mem_info[i].name);
    }
    free(mem_info);
    mem_info = NULL;
    mem_info_count = 0;
}

static void *my_malloc(char *name, size_t size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        add_mem_info(name, size);
    }
    return ptr;
}

static void my_free(void *ptr) {
    for (size_t i = 0; i < mem_info_count; i++) {
        if (mem_info[i].name != NULL && ptr == mem_info[i].name) {
            free(mem_info[i].name);
            mem_info[i].name = NULL;
            mem_info[i].size = 0;
        }
    }
    free(ptr);
}

int main() {
    char *buf = my_malloc("buffer", BUF_SIZE);
    if (buf == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    // Use the buffer...

    my_free(buf);

    print_mem_info();

    free_mem_info();

    return EXIT_SUCCESS;
}