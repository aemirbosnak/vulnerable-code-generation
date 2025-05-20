//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define INITIAL_ARRAY_SIZE 2

typedef struct {
    char** data;
    size_t size;
    size_t capacity;
} DynamicStringArray;

// Function to initialize the dynamic string array
void initStringArray(DynamicStringArray* array) {
    array->data = (char**)malloc(INITIAL_ARRAY_SIZE * sizeof(char*));
    array->size = 0;
    array->capacity = INITIAL_ARRAY_SIZE;
}

// Function to resize the dynamic string array
void resizeStringArray(DynamicStringArray* array) {
    array->capacity *= 2;
    array->data = (char**)realloc(array->data, array->capacity * sizeof(char*));
}

// Function to add a string to the dynamic string array
void addString(DynamicStringArray* array, const char* str) {
    if (array->size == array->capacity) {
        resizeStringArray(array);
    }
    array->data[array->size] = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(array->data[array->size], str);
    array->size++;
}

// Function to free the memory used by the dynamic string array
void freeStringArray(DynamicStringArray* array) {
    for (size_t i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
}

// Function to print the strings in the dynamic string array
void printStringArray(const DynamicStringArray* array) {
    for (size_t i = 0; i < array->size; i++) {
        printf("String %zu: %s\n", i + 1, array->data[i]);
    }
}

// Main function
int main() {
    DynamicStringArray myArray;
    initStringArray(&myArray);

    char input[MAX_STRING_LENGTH];
    char continueInput;

    printf("Dynamic String Array Example\n");

    do {
        printf("Enter a string: ");
        fgets(input, MAX_STRING_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline character

        addString(&myArray, input);

        printf("Do you want to add another string? (y/n): ");
        scanf(" %c", &continueInput);
        getchar(); // consume the newline character from input buffer
    } while (continueInput == 'y' || continueInput == 'Y');

    printf("\nYou have entered the following strings:\n");
    printStringArray(&myArray);

    freeStringArray(&myArray);
    return 0;
}