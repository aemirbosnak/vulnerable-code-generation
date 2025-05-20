//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: sophisticated
#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library
#include <string.h> // string library
#include <math.h> // math library

// define the maximum and minimum values for testing internet speeds
#define MAX_VALUE 100000000
#define MIN_VALUE 0

// function to generate random integer values within the defined range
int generate_random_int(int max, int min) {
    int range = max - min + 1;
    return (rand() % range) + min;
}

// function to calculate the average value of an array of integers
double calculate_average(int* values, int num_values) {
    double sum = 0;
    for (int i = 0; i < num_values; i++) {
        sum += values[i];
    }
    return sum / num_values;
}

// function to sort an array of integers in ascending order
void sort_values(int* values, int num_values) {
    for (int i = 0; i < num_values; i++) {
        for (int j = i+1; j < num_values; j++) {
            if (values[j] < values[i]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

// main function
int main() {
    // ask user for number of tests to perform
    int num_tests;
    printf("How many tests would you like to perform?\n");
    scanf("%d", &num_tests);
    
    // initialize array to store test results
    int test_results[num_tests];
    
    // perform tests and store results in array
    for (int i = 0; i < num_tests; i++) {
        int result = generate_random_int(MAX_VALUE, MIN_VALUE);
        test_results[i] = result;
        printf("Test %d: %d Mbps\n", i+1, result);
    }
    
    // calculate and print average speed
    double average = calculate_average(test_results, num_tests);
    printf("Average speed: %.2f Mbps\n", average);
    
    // sort test results in ascending order
    sort_values(test_results, num_tests);
    
    // calculate and print median speed
    double median;
    if (num_tests % 2 == 0) {
        int middle_index = num_tests/2;
        median = (test_results[middle_index] + test_results[middle_index-1]) / 2.0;
    } else {
        int middle_index = (num_tests-1)/2;
        median = test_results[middle_index];
    }
    printf("Median speed: %.2f Mbps\n", median);
    
    return 0;
}