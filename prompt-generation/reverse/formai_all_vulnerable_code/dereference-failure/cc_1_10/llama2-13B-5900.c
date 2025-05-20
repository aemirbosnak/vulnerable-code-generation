//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_ARRAY_SIZE 10

// Function to generate a random string
char *generate_random_string(int len) {
    char *str = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    return str;
}

// Function to print a pattern using a 2D array
void print_pattern(char arr[MAX_ARRAY_SIZE][MAX_STR_LEN]) {
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        for (int j = 0; j < MAX_STR_LEN; j++) {
            if (i % 2 == 0) {
                printf("{%c}", arr[i][j]);
            } else {
                printf("{%c%c}", arr[i][j], arr[i][j + 1]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Generate a random string for the pattern
    char *pattern = generate_random_string(MAX_STR_LEN);

    // Create a 2D array to store the pattern
    char arr[MAX_ARRAY_SIZE][MAX_STR_LEN];
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        for (int j = 0; j < MAX_STR_LEN; j++) {
            arr[i][j] = pattern[i * MAX_STR_LEN + j];
        }
    }

    // Print the pattern using the print_pattern function
    print_pattern(arr);

    // Free the memory allocated for the pattern
    free(pattern);

    return 0;
}