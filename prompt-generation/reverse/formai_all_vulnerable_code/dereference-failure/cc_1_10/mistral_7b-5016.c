//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define ARRAY_SIZE 10

typedef struct {
    int value;
    char name[20];
} Element;

void bubble_sort(void *base, size_t size, size_t stride) {
    int i, j, swapped;
    char *data = (char *) base;

    for (i = 0; i < ARRAY_SIZE - 1; ++i) {
        for (j = 0; j < ARRAY_SIZE - i - 1; ++j) {
            Element *a = (Element *) (data + j * (sizeof(Element) + sizeof(char[20])));
            Element *b = (Element *) (data + (j + 1) * (sizeof(Element) + sizeof(char[20])));

            if (a->value > b->value) {
                swapped = 1;

                // Swap values
                *((int *) &a->value) ^= *((int *) &b->value);
                *((int *) &b->value) ^= *((int *) &a->value);
                *((int *) &a->value) ^= *((int *) &b->value);

                // Swap names
                size_t name_len = strlen(a->name) > strlen(b->name) ? strlen(a->name) : strlen(b->name);
                memmove(a->name + strlen(b->name), a->name, name_len);
                memmove(a->name, b->name, strlen(b->name));
                memmove(b->name + strlen(a->name), b->name + strlen(a->name), name_len);
                memmove(b->name, a->name, strlen(a->name));
            }
        }

        if (!swapped) {
            break;
        }

        swapped = 0;
    }
}

int main() {
    Element array[ARRAY_SIZE];

    // Initialize elements with values and names
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        snprintf(array[i].name, sizeof(array[i].name), "Element %d", i);
        array[i].value = i;
    }

    // Map the memory to access it as a contiguous block
    void *mapped_base = mmap(NULL, sizeof(Element) * ARRAY_SIZE + ARRAY_SIZE * sizeof(char[20]), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapped_base == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    memcpy(mapped_base, array, sizeof(Element) * ARRAY_SIZE + ARRAY_SIZE * sizeof(char[20]));

    // Call the invasive sorting function
    bubble_sort(mapped_base, sizeof(Element), sizeof(Element) + sizeof(char[20]));

    // Unmap the memory
    munmap(mapped_base, sizeof(Element) * ARRAY_SIZE + ARRAY_SIZE * sizeof(char[20]));

    // Print the sorted elements
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("Element %d: %s\n", i, ((Element *) mapped_base)[i].name);
    }

    return 0;
}