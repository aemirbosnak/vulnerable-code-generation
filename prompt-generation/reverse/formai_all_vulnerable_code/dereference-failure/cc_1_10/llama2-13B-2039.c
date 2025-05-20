//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUMBER_OF_TESTS 1000

// Structure to hold the test data
typedef struct {
    char name[MAX_STRING_LENGTH];
    int score;
} test_data_t;

// Function to generate random test data
void generate_test_data(test_data_t** tests, int* num_tests) {
    int i, j;

    // Generate random names
    for (i = 0; i < MAX_NUMBER_OF_TESTS; i++) {
        tests[i] = (test_data_t*) malloc(sizeof(test_data_t));
        for (j = 0; j < MAX_STRING_LENGTH; j++) {
            tests[i]->name[j] = 'A' + (rand() % 26);
        }
    }

    // Generate random scores
    for (i = 0; i < MAX_NUMBER_OF_TESTS; i++) {
        tests[i]->score = (rand() % 100) + 1;
    }

    *num_tests = MAX_NUMBER_OF_TESTS;
}

// Function to print the test data
void print_test_data(test_data_t* tests, int num_tests) {
    int i;

    for (i = 0; i < num_tests; i++) {
        printf("%s scored %d\n", tests[i].name, tests[i].score);
    }
}

int main() {
    // Generate test data
    test_data_t** tests = (test_data_t**) malloc(sizeof(test_data_t*) * MAX_NUMBER_OF_TESTS);
    int num_tests = 0;
    generate_test_data(tests, &num_tests);

    // Print test data
    print_test_data(tests, num_tests);

    // Free memory
    for (int i = 0; i < num_tests; i++) {
        free(tests[i]);
    }
    free(tests);

    return 0;
}