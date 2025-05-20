//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Thread data structure
typedef struct {
    char *str;
    int start;
    int end;
    int result;
} ThreadData;

// Thread function to check if a substring is a palindrome
void *checkPalindrome(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int i, j;

    // Check if the substring is a palindrome
    for (i = data->start, j = data->end; i < j; i++, j--) {
        if (data->str[i] != data->str[j]) {
            data->result = 0;
            return NULL;
        }
    }

    // If the substring is a palindrome, set the result to 1
    data->result = 1;

    return NULL;
}

int main() {
    char str[100];
    int numThreads, i, start, end, result;
    pthread_t *threads;
    ThreadData *data;

    // Get the input string
    printf("Enter a string: ");
    scanf("%s", str);

    // Get the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads);

    // Allocate memory for the threads and thread data
    threads = (pthread_t *)malloc(sizeof(pthread_t) * numThreads);
    data = (ThreadData *)malloc(sizeof(ThreadData) * numThreads);

    // Divide the string into substrings and create threads to check each substring
    start = 0;
    end = strlen(str) - 1;
    for (i = 0; i < numThreads; i++) {
        data[i].str = str;
        data[i].start = start;
        data[i].end = end;
        pthread_create(&threads[i], NULL, checkPalindrome, &data[i]);

        // Update the start and end indices for the next substring
        start = end + 1;
        end = start + (strlen(str) - 1 - start) / (numThreads - i - 1);
    }

    // Join all threads
    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check the results of all threads
    result = 1;
    for (i = 0; i < numThreads; i++) {
        result &= data[i].result;
    }

    // Print the result
    if (result) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Free the allocated memory
    free(threads);
    free(data);

    return 0;
}