//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to open a file and handle errors
FILE* openFile(const char* filename, const char* mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return file;
}

// Function to allocate memory and handle errors
void* allocateMemory(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to create an array of integers, fill it, and handle errors
int* createIntArray(size_t size) {
    int* array = allocateMemory(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        array[i] = i + 1; // Fill array with values 1 to size
    }
    return array;
}

// Function to write an array to a file and handle errors
void writeArrayToFile(FILE* file, int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (fprintf(file, "%d\n", array[i]) < 0) {
            fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

// Function to read an array from a file and handle errors
int* readArrayFromFile(FILE* file, size_t* size) {
    int capacity = 10;
    int* array = allocateMemory(capacity * sizeof(int));
    *size = 0;
    
    while (1) {
        if (*size >= capacity) {
            capacity *= 2; // Double the capacity
            array = realloc(array, capacity * sizeof(int));
            if (array == NULL) {
                fprintf(stderr, "Memory reallocation failed: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
        
        if (fscanf(file, "%d", &array[*size]) != 1) {
            if (feof(file)) break; // End of file reached
            fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        (*size)++;
    }
    
    return array;
}

// Function to display an array
void displayArray(int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    const char* filename = "numbers.txt";
    
    // Open file for writing
    FILE* file = openFile(filename, "w");
    
    // Create and write array to file
    size_t size = 20;
    int* array = createIntArray(size);
    writeArrayToFile(file, array, size);
    fclose(file);
    
    // Free the allocated memory
    free(array);
    
    // Open file for reading
    file = openFile(filename, "r");
    
    // Read array from file
    size_t readSize;
    int* readArray = readArrayFromFile(file, &readSize);
    fclose(file);
    
    // Display the read array
    printf("Array read from file: ");
    displayArray(readArray, readSize);
    
    // Free the read array
    free(readArray);
    
    return 0;
}