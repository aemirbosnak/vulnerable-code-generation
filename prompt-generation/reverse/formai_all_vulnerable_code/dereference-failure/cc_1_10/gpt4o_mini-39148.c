//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define PI 3.14159265358979323846

// Function to compute the sine of an array in parallel
void compute_sine(float *input, float *output, size_t size) {
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
        output[i] = sinf(input[i]);
    }
}

// Function to compute the cosine of an array in parallel
void compute_cosine(float *input, float *output, size_t size) {
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
        output[i] = cosf(input[i]);
    }
}

// Function to compute the tangent of an array in parallel
void compute_tangent(float *input, float *output, size_t size) {
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
        output[i] = tanf(input[i]);
    }
}

// Function to initialize the input array
void initialize_array(float *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = (float)(i * PI / (float)size); // Initialize with values in range [0, π]
    }
}

// Function to print the results (for verification purposes)
void print_results(float *sine, float *cosine, float *tangent, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Input: %.4f, Sine: %.4f, Cosine: %.4f, Tangent: %.4f\n",
               i * PI / (float)size, sine[i], cosine[i], tangent[i]);
    }
}

int main() {
    float *input_array = (float *)malloc(ARRAY_SIZE * sizeof(float));
    float *sine_array = (float *)malloc(ARRAY_SIZE * sizeof(float));
    float *cosine_array = (float *)malloc(ARRAY_SIZE * sizeof(float));
    float *tangent_array = (float *)malloc(ARRAY_SIZE * sizeof(float));
    
    if (input_array == NULL || sine_array == NULL || cosine_array == NULL || tangent_array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Initialize input array
    initialize_array(input_array, ARRAY_SIZE);

    // Timing the sine computation
    clock_t start_time = clock();
    compute_sine(input_array, sine_array, ARRAY_SIZE);
    clock_t end_time = clock();
    printf("Time taken for sine computation: %.5f seconds\n",
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Timing the cosine computation
    start_time = clock();
    compute_cosine(input_array, cosine_array, ARRAY_SIZE);
    end_time = clock();
    printf("Time taken for cosine computation: %.5f seconds\n",
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Timing the tangent computation
    start_time = clock();
    compute_tangent(input_array, tangent_array, ARRAY_SIZE);
    end_time = clock();
    printf("Time taken for tangent computation: %.5f seconds\n",
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Uncomment the line below to print the results
    // print_results(sine_array, cosine_array, tangent_array, 10); // Print first 10 results

    // Free allocated memory
    free(input_array);
    free(sine_array);
    free(cosine_array);
    free(tangent_array);

    return EXIT_SUCCESS;
}