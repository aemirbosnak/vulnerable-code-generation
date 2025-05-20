//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

// Function to perform division and handle potential errors
double safe_divide(double numerator, double denominator) {
    if (denominator == 0) {
        errno = EDOM; // Set domain error
        return NAN; // Return Not-A-Number since division by zero is undefined
    }
    return numerator / denominator;
}

// Function to calculate the square root and check for negative input
double safe_sqrt(double value) {
    if (value < 0) {
        errno = EDOM; // Set domain error
        return NAN; // Return Not-A-Number for sqrt of negative number
    }
    return sqrt(value);
}

// Simple structure to hold scientific data
typedef struct {
    double temperature;
    double pressure;
} ScienceData;

// Function to allocate memory for ScienceData
ScienceData* allocate_science_data() {
    ScienceData* data = (ScienceData*)malloc(sizeof(ScienceData));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return data;
}

// Function to free memory allocated for ScienceData
void free_science_data(ScienceData* data) {
    free(data);
}

// Main function to execute calculations
int main() {
    // Initialize variables for scientific computations
    double numerator = 10.0;
    double denominator = 0.0; // Change value to see how the code handles errors
    double result;

    // Perform safe division
    result = safe_divide(numerator, denominator);
    if (errno == EDOM) {
        fprintf(stderr, "Error: Division by zero encountered!\n");
    } else {
        printf("Result of division: %f\n", result);
    }

    // Reset errno before next operation
    errno = 0; 

    // Calculate safe square root
    double value = -25.0; // Change value to see how the code handles errors
    result = safe_sqrt(value);
    if (errno == EDOM) {
        fprintf(stderr, "Error: Attempt to calculate square root of negative number!\n");
    } else {
        printf("Square root of %f: %f\n", value, result);
    }

    // Allocate memory for science data structure
    ScienceData* data = allocate_science_data();
    
    // Simulating filling the structure with some data
    data->temperature = 25.5; // in Celsius
    data->pressure = 1013.25; // in hPa

    // Displaying the data
    printf("Science Data:\n");
    printf("Temperature: %f °C\n", data->temperature);
    printf("Pressure: %f hPa\n", data->pressure);

    // Free allocated memory
    free_science_data(data);

    return 0;
}