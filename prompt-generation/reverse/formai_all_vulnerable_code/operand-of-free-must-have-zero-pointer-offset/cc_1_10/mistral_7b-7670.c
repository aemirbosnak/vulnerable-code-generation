//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void* shadow_dance(size_t size, char *name) {
    void *mem_block = malloc(size + sizeof(size_t) + strlen(name) + 1);
    if (mem_block == NULL) {
        fprintf(stderr, "Out of memory for %s\n", name);
        return NULL;
    }

    size_t *len_ptr = (size_t *)mem_block;
    *len_ptr = size;
    strcpy((char *)mem_block + sizeof(size_t), name);

    return (char *)mem_block + sizeof(size_t) + strlen(name) + 1;
}

int main(void) {
    char *str = NULL;
    size_t len = 0;

    str = shadow_dance(SIZE, "moon_whisperer");
    if (str == NULL) {
        return 1;
    }

    memset(str, '*', SIZE);

    puts("The shadow has spoken...");
    puts(str);

    len = *(size_t *)((char *)str - sizeof(size_t));
    free(str);

    str = shadow_dance(len, "sun_bringer");
    if (str == NULL) {
        return 1;
    }

    strcpy(str, "The sun brings life...");

    puts("The shadow speaks anew...");
    puts(str);

    free(str);

    return 0;
}