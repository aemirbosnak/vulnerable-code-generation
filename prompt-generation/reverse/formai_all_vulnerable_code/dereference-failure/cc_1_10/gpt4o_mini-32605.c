//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void handleFileError(FILE *file, const char *filename) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s. Exiting!\n", filename);
        exit(EXIT_FAILURE);
    }
}

void handleMemoryError(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed! Exiting!\n");
        exit(EXIT_FAILURE);
    }
}

void readFileAndAllocateMemory(const char *filename) {
    FILE *file = fopen(filename, "r");
    handleFileError(file, filename);

    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    handleMemoryError(buffer);

    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("Read line: %s", buffer);
    }

    fclose(file);
    free(buffer);
}

void handleDivision(int numerator, int denominator) {
    if (denominator == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed! Exiting!\n");
        exit(EXIT_FAILURE);
    } else {
        double result = (double)numerator / denominator;
        printf("Division result of %d / %d is: %.2f\n", numerator, denominator, result);
    }
}

void findSquareRoot(double number) {
    if (number < 0) {
        fprintf(stderr, "Error: Cannot compute the square root of a negative number! Exiting!\n");
        exit(EXIT_FAILURE);
    } else {
        double result = sqrt(number);
        printf("The square root of %.2f is: %.2f\n", number, result);
    }
}

int main() {
    printf("Welcome to the Energetic C Error Handling Example Program!\n");
    
    // Error handling during file operations
    const char *filename = "testfile.txt";
    printf("Attempting to read from file: %s\n", filename);
    readFileAndAllocateMemory(filename);
    
    // Error handling during division
    int num1 = 10, num2 = 0;
    printf("Attempting to divide %d by %d\n", num1, num2);
    handleDivision(num1, num2); // This line would exit the program due to division by zero

    // Error handling during square root calculation
    double number = -4.0;
    printf("Attempting to find the square root of: %.2f\n", number);
    findSquareRoot(number); // This will also exit due to invalid input for square root

    printf("All operations completed successfully!\n");
    return 0;
}