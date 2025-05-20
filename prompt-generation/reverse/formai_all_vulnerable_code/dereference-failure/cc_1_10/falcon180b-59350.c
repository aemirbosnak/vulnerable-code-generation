//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

// Function to convert binary to decimal
void *binary_to_decimal(void *arg) {
    char binary[100];
    int decimal = 0, i = 0;

    // Get binary number from shared memory
    strcpy(binary, (char *) arg);

    // Convert binary to decimal
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }

    // Print result
    printf("Thread %d: Binary number %s is equal to decimal %d.\n", pthread_self(), binary, decimal);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    char input[100];

    // Initialize shared memory
    char *shared_memory = malloc(100 * NUM_THREADS);

    // Read binary numbers from user
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Enter binary number %d: ", i + 1);
        scanf("%s", input);
        strcpy(shared_memory + i * 100, input);
    }

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, binary_to_decimal, (void *) (shared_memory + i * 100));
        if (rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(shared_memory);

    return 0;
}