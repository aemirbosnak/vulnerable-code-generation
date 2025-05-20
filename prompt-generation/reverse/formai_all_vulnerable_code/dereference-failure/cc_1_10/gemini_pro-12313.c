//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Structure to hold the pattern and its parameters
typedef struct {
    int rows;
    int columns;
    char pattern;
} Pattern;

// Function to print the pattern
void *print_pattern(void *arg) {
    Pattern *pattern = (Pattern *)arg;

    // Loop through the rows and columns to print the pattern
    for (int i = 0; i < pattern->rows; i++) {
        for (int j = 0; j < pattern->columns; j++) {
            printf("%c", pattern->pattern);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(pattern);

    return NULL;
}

int main() {
    // Get the input from the user
    int rows, columns;
    char pattern;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    printf("Enter the pattern character: ");
    scanf(" %c", &pattern);

    // Create a thread to print the pattern
    pthread_t thread;
    Pattern *pattern_struct = malloc(sizeof(Pattern));
    pattern_struct->rows = rows;
    pattern_struct->columns = columns;
    pattern_struct->pattern = pattern;
    pthread_create(&thread, NULL, print_pattern, (void *)pattern_struct);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}