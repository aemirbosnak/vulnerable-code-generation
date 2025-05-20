//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory for an array and initialize it
int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}

// Function to read integers from a file and store them in an array
void readNumbersFromFile(const char* filename, int* arr, int size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Error reading number at index %d. Check if the file has enough numbers.\n", i);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    
    fclose(file);
}

// Function to print the elements of an array
void printArray(int* arr, int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the average of an array
double calculateAverage(int* arr, int size) {
    if (size == 0) {
        fprintf(stderr, "Cannot calculate average of an empty array.\n");
        exit(EXIT_FAILURE);
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return (double)sum / size;
}

// Function to write the average to a file
void writeAverageToFile(const char* filename, double average) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file to write average: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "Average: %.2f\n", average);
    fclose(file);
}

// Main function to drive the program
int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <size> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* inputFile = argv[1];
    int size = atoi(argv[2]);
    const char* outputFile = argv[3];

    if (size <= 0) {
        fprintf(stderr, "Error: Size must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    int* numbers = createArray(size);
    readNumbersFromFile(inputFile, numbers, size);
    printArray(numbers, size);

    double average = calculateAverage(numbers, size);
    writeAverageToFile(outputFile, average);

    free(numbers);
    return 0;
}