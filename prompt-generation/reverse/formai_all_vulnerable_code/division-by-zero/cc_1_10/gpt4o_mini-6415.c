//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

// Function prototypes
void generateRandomNumbers(int arr[], int size, int lower, int upper);
void calculateStatistics(int arr[], int size, float *mean, float *median, int *mode);
void displayResults(int arr[], int size, float mean, float median, int mode);

int main() {
    int numbers[MAX_NUMBERS];
    float mean, median;
    int mode;

    int lower, upper, count;

    // Input range and count of numbers
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper);
    printf("Enter the total number of random numbers to generate (max %d): ", MAX_NUMBERS);
    scanf("%d", &count);

    // Validate count
    if (count < 1 || count > MAX_NUMBERS || lower >= upper) {
        printf("Invalid input. Please ensure count is between 1 and %d and lower < upper.\n", MAX_NUMBERS);
        return -1;
    }

    // Generate random numbers
    generateRandomNumbers(numbers, count, lower, upper);

    // Calculate statistics
    calculateStatistics(numbers, count, &mean, &median, &mode);

    // Display results
    displayResults(numbers, count, mean, median, mode);

    return 0;
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size, int lower, int upper) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

// Function to calculate mean, median, and mode
void calculateStatistics(int arr[], int size, float *mean, float *median, int *mode) {
    int sum = 0;

    // Calculate mean
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    *mean = (float)sum / size;

    // Calculate median
    int temp;
    // Implementing a simple bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        *median = (arr[size/2 - 1] + arr[size/2]) / 2.0;
    } else {
        *median = arr[size/2];
    }

    // Calculate mode
    int maxCount = 0;
    *mode = arr[0];
    
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            *mode = arr[i];
        }
    }
}

// Function to display results
void displayResults(int arr[], int size, float mean, float median, int mode) {
    printf("\nGenerated Numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nStatistics:\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);
}