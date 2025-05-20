//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define FILE_PATH "numbers.txt"

void handleFileError(FILE *file) {
    if (file == NULL) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
}

void handleMemoryError(int *array) {
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void handleReadError(int count, int max_count) {
    if (count < 0 || count > max_count) {
        fprintf(stderr, "Error reading numbers, count: %d, expected max: %d\n", count, max_count);
        exit(EXIT_FAILURE);
    }
}

void validateNumber(int number) {
    if (number < 0 || number > 10000) { // Arbitrarily chosen limits for this paranoid example
        fprintf(stderr, "Invalid number found: %d\n", number);
        exit(EXIT_FAILURE);
    }
}

int main() {
    FILE *file_ptr = fopen(FILE_PATH, "r");
    handleFileError(file_ptr);

    int *numbers = malloc(sizeof(int) * MAX_NUMBERS);
    handleMemoryError(numbers);

    int count = 0;
    while (count < MAX_NUMBERS) {
        int result = fscanf(file_ptr, "%d", &numbers[count]);
        if (result == EOF) {
            break; // End of file encountered
        }
        else if (result != 1) {
            fprintf(stderr, "Failed to read a number. Skipping and continuing.\n");
            // Clear the corrupted input
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        validateNumber(numbers[count]);
        count++;
    }

    handleReadError(count, MAX_NUMBERS);
    fclose(file_ptr);

    printf("Successfully read %d numbers from %s:\n", count, FILE_PATH);
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Additional paranoid re-check to make sure numbers are within limits before processing
    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0 || numbers[i] > 10000) {
            fprintf(stderr, "Critical Error: Number %d out of expected range!\n", numbers[i]);
            free(numbers);
            exit(EXIT_FAILURE);
        }
    }

    // Let's sum up the numbers as an example processing step
    long total_sum = 0;
    for (int i = 0; i < count; i++) {
        total_sum += numbers[i];
    }

    printf("Total Sum of Numbers: %ld\n", total_sum);

    free(numbers);
    return 0;
}