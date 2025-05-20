//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = (char *)malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (char)(rand() % 26 + 97);
    }
    str[n] = '\0';
    return str;
}

// Function to benchmark string concatenation
void benchmark_string_concatenation(int n) {
    char *str1 = generate_random_string(n);
    char *str2 = generate_random_string(n);
    char *result = (char *)malloc(2 * n + 1);

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to concatenate two strings of length %d: %f seconds\n", n, time_taken);

    free(str1);
    free(str2);
    free(result);
}

// Function to benchmark string comparison
void benchmark_string_comparison(int n) {
    char *str1 = generate_random_string(n);
    char *str2 = generate_random_string(n);

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        strcmp(str1, str2);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to compare two strings of length %d: %f seconds\n", n, time_taken);

    free(str1);
    free(str2);
}

// Function to benchmark string sorting
void benchmark_string_sorting(int n) {
    char **strings = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strings[i] = generate_random_string(n);
    }

    clock_t start = clock();
    qsort(strings, n, sizeof(char *), (int (*)(const void *, const void *))strcmp);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort an array of %d strings of length %d: %f seconds\n", n, n, time_taken);

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
}

// Main function
int main() {
    // Generate random seed
    srand(time(NULL));

    // Benchmark string concatenation
    for (int n = 100; n <= 1000; n += 100) {
        benchmark_string_concatenation(n);
    }

    // Benchmark string comparison
    for (int n = 100; n <= 1000; n += 100) {
        benchmark_string_comparison(n);
    }

    // Benchmark string sorting
    for (int n = 100; n <= 1000; n += 100) {
        benchmark_string_sorting(n);
    }

    return 0;
}