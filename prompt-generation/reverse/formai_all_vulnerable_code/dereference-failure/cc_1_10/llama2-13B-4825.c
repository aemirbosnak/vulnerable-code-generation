//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for the element to be searched
typedef struct {
    int key;
    char name[20];
} element_t;

// Define a function to generate a random list of elements
void generate_list(int num_elements) {
    element_t *list = malloc(num_elements * sizeof(element_t));
    int i;

    for (i = 0; i < num_elements; i++) {
        list[i].key = rand() % 100;
        sprintf(list[i].name, "User %d", i);
    }
}

// Define a function to search for an element in the list
int search_list(element_t *list, int num_elements, int key) {
    int i, j;

    for (i = 0; i < num_elements; i++) {
        if (list[i].key == key) {
            // Found the element!
            printf("Found %d at index %d\n", key, i);
            return i;
        }
    }

    // Not found
    return -1;
}

int main() {
    int num_elements = 10;
    element_t *list = malloc(num_elements * sizeof(element_t));
    generate_list(num_elements);

    int key = rand() % 100;
    int index = search_list(list, num_elements, key);

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    free(list);
    return 0;
}