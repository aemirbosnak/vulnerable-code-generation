//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements that can be sorted
#define MAX_ELEMENTS 100

// Define the structure for an element
typedef struct {
    int value;
    int index;
} Element;

// Define the function to compare two elements
int compare(Element* a, Element* b) {
    if (a->value < b->value) {
        return -1;
    } else if (a->value > b->value) {
        return 1;
    } else {
        return 0;
    }
}

// Define the function to swap two elements
void swap(Element* a, Element* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// Define the function to perform bubble sort
void bubbleSort(Element* elements, int numElements) {
    int i, j;
    for (i = 0; i < numElements - 1; i++) {
        for (j = 0; j < numElements - i - 1; j++) {
            if (compare(elements + j, elements + j + 1) > 0) {
                swap(elements + j, elements + j + 1);
            }
        }
    }
}

// Define the main function
int main() {
    int numElements;
    Element* elements;

    // Get the number of elements to be sorted
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &numElements);

    // Allocate memory for the elements
    elements = (Element*) malloc(sizeof(Element) * numElements);

    // Get the values of the elements
    printf("Enter the values of the elements:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &elements[i].value);
        elements[i].index = i;
    }

    // Sort the elements using bubble sort
    printf("Sorting the elements...\n");
    bubbleSort(elements, numElements);

    // Print the sorted elements
    printf("Sorted elements:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d - %d\n", elements[i].value, elements[i].index);
    }

    // Free the memory allocated for the elements
    free(elements);

    return 0;
}