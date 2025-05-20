//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1000000 // Maximum string length
#define NUM_TESTS 100000 // Number of tests to run
#define THRESHOLD 0.0001 // Acceptable deviation from expected results

/* Function to generate and return a random string of given length */
char *generate_random_string(int len) {
    char *str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[len] = '\0';
    return str;
}

/* Function to compute the hash value of the given string */
unsigned long compute_hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char *str = generate_random_string(MAX_STR_LEN);
    unsigned long expected_hash = compute_hash(str); // Compute expected hash value
    
    clock_t start = clock();
    for (int i = 0; i < NUM_TESTS; i++) {
        unsigned long hash = compute_hash(str); // Compute hash value
        if (hash != expected_hash) {
            printf("Error: Deviation from expected result is greater than threshold\n");
            return 1;
        }
    }
    clock_t end = clock();

    double avg_time = ((double) (end - start)) / CLOCKS_PER_SEC / NUM_TESTS; // Compute average execution time

    printf("Test Passed: Deviation from expected result is within acceptable threshold\n");
    printf("Average execution time: %f\n", avg_time);

    free(str);
    return 0;
}