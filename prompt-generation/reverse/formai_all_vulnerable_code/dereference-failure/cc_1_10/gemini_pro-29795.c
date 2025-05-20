//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: decentralized
// Palindrome Checker: A Decentralized Approach

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Constants
#define MAX_THREADS 10
#define SEGMENT_SIZE 10

// Structs
typedef struct {
    char *string;
    int length;
    int start;
    int end;
} Segment;

// Function Declarations
void *check_segment(void *args);
int is_palindrome(char *string, int start, int end);

// Global Variables
int num_threads;
Segment segments[MAX_THREADS];
int palindrome_found = 0;

// Main Function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *string = argv[1];
    int length = strlen(string);

    // Determine the number of threads to use
    num_threads = (length + SEGMENT_SIZE - 1) / SEGMENT_SIZE;
    if (num_threads > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }

    // Divide the string into segments
    for (int i = 0; i < num_threads; i++) {
        segments[i].string = string;
        segments[i].length = length;
        segments[i].start = i * SEGMENT_SIZE;
        segments[i].end = (i + 1) * SEGMENT_SIZE;
        if (segments[i].end > length) {
            segments[i].end = length;
        }
    }

    // Create threads to check each segment
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, check_segment, &segments[i]);
    }

    // Join threads and check for palindrome
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        if (palindrome_found) {
            break;
        }
    }

    // Print result
    if (palindrome_found) {
        printf("The string '%s' is a palindrome.\n", string);
    } else {
        printf("The string '%s' is not a palindrome.\n", string);
    }

    return EXIT_SUCCESS;
}

// Thread Function: Check Segment
void *check_segment(void *args) {
    Segment *segment = (Segment *)args;

    // Check if the segment is a palindrome
    int result = is_palindrome(segment->string, segment->start, segment->end);

    // Update global variable
    if (!palindrome_found && result == 1) {
        palindrome_found = 1;
    }

    return NULL;
}

// Function: Check if a String is a Palindrome
int is_palindrome(char *string, int start, int end) {
    int is_palindrome = 1;

    for (int i = start, j = end - 1; i < end / 2; i++, j--) {
        if (string[i] != string[j]) {
            is_palindrome = 0;
            break;
        }
    }

    return is_palindrome;
}