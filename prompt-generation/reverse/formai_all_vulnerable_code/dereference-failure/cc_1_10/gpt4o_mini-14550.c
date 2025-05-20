//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_NUMBERS 100

void print_error(const char* message) {
    fprintf(stderr, "Error: %s - %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

void read_numbers(int* arr, size_t* count) {
    FILE* file = fopen("numbers.txt", "r");
    if (!file) {
        print_error("Failed to open 'numbers.txt'");
    }

    *count = 0;
    while (*count < MAX_NUMBERS && fscanf(file, "%d", &arr[*count]) == 1) {
        (*count)++;
    }

    if (ferror(file)) {
        fclose(file);
        print_error("Error reading from file");
    }

    fclose(file);
    printf("Successfully read %zu numbers from 'numbers.txt'\n", *count);
}

double calculate_average(const int* arr, size_t count) {
    if (count == 0) {
        print_error("Cannot calculate average of zero numbers");
    }

    long sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += arr[i];
    }
    return (double)sum / count;
}

void write_output(const char* filename, double average) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        print_error("Failed to open output file for writing");
    }

    if (fprintf(file, "Average: %.2f\n", average) < 0) {
        fclose(file);
        print_error("Error writing to output file");
    }

    fclose(file);
    printf("Output written successfully to '%s'\n", filename);
}

int main() {
    int numbers[MAX_NUMBERS];
    size_t count;

    read_numbers(numbers, &count);
    
    double average = calculate_average(numbers, count);

    write_output("output.txt", average);

    return 0;
}