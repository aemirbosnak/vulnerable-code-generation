//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define NUM_THREADS 3

typedef struct {
    char *input_string;
    char *result_string;
} thread_data_t;

// Function to reverse a string
void *reverse_string(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int len = strlen(data->input_string);
    data->result_string = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        data->result_string[i] = data->input_string[len - 1 - i];
    }
    data->result_string[len] = '\0';
    return NULL;
}

// Function to convert a string to uppercase
void *uppercase_string(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int len = strlen(data->input_string);
    data->result_string = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        data->result_string[i] = toupper(data->input_string[i]);
    }
    data->result_string[len] = '\0';
    return NULL;
}

// Function to count vowels in a string
void *count_vowels(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int count = 0;
    for (int i = 0; data->input_string[i] != '\0'; i++) {
        char c = tolower(data->input_string[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    // Store the count as a string in result_string
    data->result_string = (char *)malloc(20);
    sprintf(data->result_string, "Vowels: %d", count);
    return NULL;
}

int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
    fgets(input, MAX_STRING_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    data[0].input_string = input;  // For reversing
    data[1].input_string = input;  // For uppercase conversion
    data[2].input_string = input;  // For counting vowels

    // Create threads for each operation
    pthread_create(&threads[0], NULL, reverse_string, (void *)&data[0]);
    pthread_create(&threads[1], NULL, uppercase_string, (void *)&data[1]);
    pthread_create(&threads[2], NULL, count_vowels, (void *)&data[2]);

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display results
    printf("Original String: %s\n", input);
    printf("Reversed String: %s\n", data[0].result_string);
    printf("Uppercase String: %s\n", data[1].result_string);
    printf("%s\n", data[2].result_string);

    // Free allocated memory
    free(data[0].result_string);
    free(data[1].result_string);
    free(data[2].result_string);

    return 0;
}