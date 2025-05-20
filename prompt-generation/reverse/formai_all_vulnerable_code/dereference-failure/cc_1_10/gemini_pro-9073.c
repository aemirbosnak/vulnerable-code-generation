//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the number of elements in the array
#define N 10

// Define the maximum value of an element in the array
#define MAX_VALUE 100

// Function to generate a random array of integers
int* generate_random_array(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    return arr;
}

// Function to print an array of integers
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array of integers using the selection sort algorithm
void selection_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Function to find the median of an array of integers
int median(int* arr, int n) {
    // Sort the array in ascending order
    selection_sort(arr, n);

    // If the number of elements is odd, the median is the middle element
    if (n % 2 == 1) {
        return arr[n / 2];
    }
    // If the number of elements is even, the median is the average of the two middle elements
    else {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
}

// Function to find the mode of an array of integers
int mode(int* arr, int n) {
    // Create a histogram to count the occurrences of each element in the array
    int histogram[MAX_VALUE] = {0};
    for (int i = 0; i < n; i++) {
        histogram[arr[i]]++;
    }

    // Find the element with the maximum number of occurrences
    int max_count = 0;
    int mode_value = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        if (histogram[i] > max_count) {
            max_count = histogram[i];
            mode_value = i;
        }
    }

    return mode_value;
}

// Function to find the range of an array of integers
int range(int* arr, int n) {
    // Find the minimum and maximum values in the array
    int min_value = arr[0];
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Return the range of the array
    return max_value - min_value;
}

// Function to find the interquartile range of an array of integers
int interquartile_range(int* arr, int n) {
    // Sort the array in ascending order
    selection_sort(arr, n);

    // Find the median of the array
    int median_value = median(arr, n);

    // Find the median of the first half of the array
    int lower_median = median(arr, n / 2);

    // Find the median of the second half of the array
    int upper_median = median(arr, n - n / 2);

    // Return the interquartile range of the array
    return upper_median - lower_median;
}

// Function to find the standard deviation of an array of integers
double standard_deviation(int* arr, int n) {
    // Find the mean of the array
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += (double)arr[i] / n;
    }

    // Find the variance of the array
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (double)(arr[i] - mean) * (arr[i] - mean) / n;
    }

    // Return the standard deviation of the array
    return sqrt(variance);
}

// Function to find the covariance of two arrays of integers
double covariance(int* arr1, int* arr2, int n) {
    // Find the mean of the first array
    double mean1 = 0;
    for (int i = 0; i < n; i++) {
        mean1 += (double)arr1[i] / n;
    }

    // Find the mean of the second array
    double mean2 = 0;
    for (int i = 0; i < n; i++) {
        mean2 += (double)arr2[i] / n;
    }

    // Find the covariance of the two arrays
    double covariance = 0;
    for (int i = 0; i < n; i++) {
        covariance += (double)(arr1[i] - mean1) * (arr2[i] - mean2) / n;
    }

    return covariance;
}

// Function to find the correlation coefficient of two arrays of integers
double correlation_coefficient(int* arr1, int* arr2, int n) {
    // Find the covariance of the two arrays
    double covariance_value = covariance(arr1, arr2, n);

    // Find the standard deviation of the first array
    double standard_deviation1 = standard_deviation(arr1, n);

    // Find the standard deviation of the second array
    double standard_deviation2 = standard_deviation(arr2, n);

    // Return the correlation coefficient of the two arrays
    return covariance_value / (standard_deviation1 * standard_deviation2);
}

int main() {
    // Generate a random array of integers
    int* arr = generate_random_array(N);

    // Print the original array
    printf("Original array:\n");
    print_array(arr, N);

    // Sort the array in ascending order
    selection_sort(arr, N);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, N);

    // Find the median of the array
    int median_value = median(arr, N);
    printf("Median: %d\n", median_value);

    // Find the mode of the array
    int mode_value = mode(arr, N);
    printf("Mode: %d\n", mode_value);

    // Find the range of the array
    int range_value = range(arr, N);
    printf("Range: %d\n", range_value);

    // Find the interquartile range of the array
    int interquartile_range_value = interquartile_range(arr, N);
    printf("Interquartile range: %d\n", interquartile_range_value);

    // Find the standard deviation of the array
    double standard_deviation_value = standard_deviation(arr, N);
    printf("Standard deviation: %.2f\n", standard_deviation_value);

    // Generate a second random array of integers
    int* arr2 = generate_random_array(N);

    // Find the covariance of the two arrays
    double covariance_value = covariance(arr, arr2, N);
    printf("Covariance: %.2f\n", covariance_value);

    // Find the correlation coefficient of the two arrays
    double correlation_coefficient_value = correlation_coefficient(arr, arr2, N);
    printf("Correlation coefficient: %.2f\n", correlation_coefficient_value);

    // Free the memory allocated for the arrays
    free(arr);
    free(arr2);

    return 0;
}