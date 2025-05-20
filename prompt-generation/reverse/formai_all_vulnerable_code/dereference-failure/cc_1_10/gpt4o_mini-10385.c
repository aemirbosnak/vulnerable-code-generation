//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256
#define MAX_NUMBERS 100

// Function to allocate memory safely
char* allocate_memory(size_t size) {
    char *ptr = (char *)malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to read numbers from a file
void read_numbers(const char *filename, int **numbers, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *numbers = (int *)allocate_memory(MAX_NUMBERS * sizeof(int));
    *count = 0;

    while (fscanf(file, "%d", &((*numbers)[*count])) == 1) {
        (*count)++;
        if (*count >= MAX_NUMBERS) {
            fprintf(stderr, "Warning: Exceeded maximum number count. Truncating...\n");
            break;
        }
    }

    fclose(file);
}

// Function to calculate the average of an array of numbers
double calculate_average(int *numbers, int count) {
    if (count == 0) {
        fprintf(stderr, "No numbers to calculate average.\n");
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    
    return sum / count;
}

// Function to write average to output file
void write_average_to_file(const char *filename, double average) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Average: %.2f\n", average);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    
    int *numbers = NULL;
    int count = 0;

    // Read numbers from the specified input file
    read_numbers(input_file, &numbers, &count);
    
    // Calculate average
    double average = calculate_average(numbers, count);

    // Write average to the specified output file
    write_average_to_file(output_file, average);

    // Clean up
    free(numbers);
    printf("Average written to %s successfully.\n", output_file);
    
    return EXIT_SUCCESS;
}