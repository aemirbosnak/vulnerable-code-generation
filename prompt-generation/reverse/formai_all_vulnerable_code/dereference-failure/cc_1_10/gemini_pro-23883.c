//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Mutex to protect shared data
pthread_mutex_t mutex;

// Thread function to convert a hexadecimal string to an integer
void *hex_to_int(void *arg) {
    char *hex_str = (char *)arg;
    int len = strlen(hex_str);
    int base = 1;
    int num = 0;

    // Lock the mutex to protect shared data
    pthread_mutex_lock(&mutex);

    // Convert each character of the hexadecimal string to an integer
    for (int i = len - 1; i >= 0; i--) {
        char c = hex_str[i];
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            // Invalid character in hexadecimal string
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        // Multiply the digit by the appropriate power of 16
        num += digit * base;
        base *= 16;
    }

    // Unlock the mutex to release the lock
    pthread_mutex_unlock(&mutex);

    // Return the converted integer
    return (void *)num;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create a thread to convert the hexadecimal string to an integer
    pthread_t thread;
    int status = pthread_create(&thread, NULL, hex_to_int, argv[1]);
    if (status != 0) {
        fprintf(stderr, "Error creating thread: %s\n", strerror(status));
        pthread_mutex_destroy(&mutex);
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish
    void *result;
    status = pthread_join(thread, &result);
    if (status != 0) {
        fprintf(stderr, "Error joining thread: %s\n", strerror(status));
        pthread_mutex_destroy(&mutex);
        return EXIT_FAILURE;
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the converted integer
    if (result == NULL) {
        fprintf(stderr, "Invalid hexadecimal string: %s\n", argv[1]);
        return EXIT_FAILURE;
    } else {
        printf("Hexadecimal string: %s\n", argv[1]);
        printf("Converted integer: %d\n", (int)result);
        return EXIT_SUCCESS;
    }
}