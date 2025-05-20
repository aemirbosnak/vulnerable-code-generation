//Falcon-180B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements that can be sorted
#define MAX_ELEMENTS 1000

// Define the structure of an element to be sorted
typedef struct {
    char *name;
    int age;
} Element;

// Function to compare two elements based on their age
int compare_elements(Element *a, Element *b) {
    if (a->age < b->age) {
        return -1;
    } else if (a->age > b->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the elements in the array
void print_elements(Element *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s (%d years old)\n", array[i].name, array[i].age);
    }
}

// Function to sort the array of elements using bubble sort
void bubble_sort(Element *array, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (compare_elements(array + j, array + j + 1) > 0) {
                Element temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int i, num_elements;
    Element *array;

    // Ask the user for the number of elements to be sorted
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &num_elements);

    // Allocate memory for the array of elements
    array = (Element *) malloc(num_elements * sizeof(Element));

    // Ask the user for the name and age of each element
    printf("Enter the name and age of each element:\n");
    for (i = 0; i < num_elements; i++) {
        scanf("%s %d", array[i].name, &array[i].age);
    }

    // Sort the array of elements
    bubble_sort(array, num_elements);

    // Print the sorted array of elements
    printf("Sorted array of elements:\n");
    print_elements(array, num_elements);

    // Free the memory allocated for the array of elements
    free(array);

    return 0;
}