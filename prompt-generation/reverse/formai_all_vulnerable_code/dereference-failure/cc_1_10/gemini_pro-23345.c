//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold each element's data
typedef struct {
    int value;
    char *description;
} element_t;

// Define a comparison function to sort the elements
int compare_elements(const void *a, const void *b) {
    element_t *e1 = (element_t *)a;
    element_t *e2 = (element_t *)b;

    return e1->value - e2->value;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified enough arguments
    if (argc < 2) {
        printf("Usage: %s <number of elements>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the number of elements to sort
    int n = atoi(argv[1]);

    // Allocate memory for the array of elements
    element_t *elements = malloc(n * sizeof(element_t));
    if (elements == NULL) {
        printf("Error: Could not allocate memory for the array of elements.\n");
        return EXIT_FAILURE;
    }

    // Get the values and descriptions for each element
    for (int i = 0; i < n; i++) {
        printf("Enter the value for element %d: ", i + 1);
        scanf("%d", &elements[i].value);

        printf("Enter the description for element %d: ", i + 1);
        elements[i].description = malloc(256);
        scanf(" %[^\n]", elements[i].description);
    }

    // Sort the array of elements
    qsort(elements, n, sizeof(element_t), compare_elements);

    // Print the sorted array of elements
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d (%s)\n", i + 1, elements[i].value, elements[i].description);
    }

    // Free the memory allocated for the array of elements
    for (int i = 0; i < n; i++) {
        free(elements[i].description);
    }
    free(elements);

    return EXIT_SUCCESS;
}