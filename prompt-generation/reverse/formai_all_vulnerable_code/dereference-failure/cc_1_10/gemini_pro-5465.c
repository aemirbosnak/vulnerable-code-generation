//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to compare two strings
int compare(const void* a, const void* b) {
    const char* str1 = (const char*)a;
    const char* str2 = (const char*)b;
    return strcmp(str1, str2);
}

// Function to print an array of strings
void print_array(char** array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
}

int main(int argc, char** argv) {
    // Check if there are any arguments
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the number of strings to sort
    size_t num_strings = argc - 1;

    // Allocate memory for the array of strings
    char** strings = (char**)malloc(sizeof(char*) * num_strings);
    if (strings == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Copy the strings from the command line arguments into the array
    for (size_t i = 0; i < num_strings; i++) {
        strings[i] = (char*)malloc(sizeof(char) * (strlen(argv[i + 1]) + 1));
        if (strings[i] == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }
        strcpy(strings[i], argv[i + 1]);
    }

    // Sort the array of strings
    qsort(strings, num_strings, sizeof(char*), compare);

    // Print the sorted array of strings
    print_array(strings, num_strings);

    // Free the allocated memory
    for (size_t i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return EXIT_SUCCESS;
}