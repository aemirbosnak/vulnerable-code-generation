//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements in the array
#define MAX_ARRAY_SIZE 1000000

// Define the type of the array elements
typedef uint32_t element_type;

// Define the function to generate a random array
void generate_random_array(element_type *array, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
    }
}

// Define the function to sort the array
void sort_array(element_type *array, uint32_t size)
{
    for (uint32_t i = 0; i < size - 1; i++)
    {
        for (uint32_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                element_type temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Define the function to search for an element in the array
uint32_t search_array(element_type *array, uint32_t size, element_type element)
{
    for (uint32_t i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }

    return -1;
}

// Define the main function
int main()
{
    // Generate a random array
    element_type *array = (element_type *)malloc(sizeof(element_type) * MAX_ARRAY_SIZE);
    generate_random_array(array, MAX_ARRAY_SIZE);

    // Sort the array
    sort_array(array, MAX_ARRAY_SIZE);

    // Search for an element in the array
    uint32_t element = 5000;
    uint32_t index = search_array(array, MAX_ARRAY_SIZE, element);

    // Print the result
    if (index != -1)
    {
        printf("Element %u found at index %u\n", element, index);
    }
    else
    {
        printf("Element %u not found\n", element);
    }

    // Free the allocated memory
    free(array);

    return 0;
}