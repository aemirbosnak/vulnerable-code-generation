//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024
#define HASH_SIZE SHA256_DIGEST_LENGTH

// Structure to hold data for the encryption threads
typedef struct {
    char *input;
    char *output;
} encrypt_data;

// Function to perform SHA256 hashing
void* hash_function(void* args) {
    encrypt_data *data = (encrypt_data *)args;
    unsigned char hash[HASH_SIZE];
    
    // Compute SHA256 hash
    SHA256((unsigned char*)data->input, strlen(data->input), hash);
    
    // Convert hash to a string
    for (int i = 0; i < HASH_SIZE; i++) {
        sprintf(data->output + (i * 2), "%02x", hash[i]);
    }
    
    printf("Hashed input: %s\n", data->input);
    printf("SHA256 Output: %s\n", data->output);
    
    return NULL;
}

// Function to handle asynchronous encryption
void async_encrypt(const char *input) {
    pthread_t thread;
    char *output = (char *)malloc(HASH_SIZE * 2 + 1);
    output[0] = '\0';  // Initialize string

    encrypt_data data;
    data.input = (char *)input;
    data.output = output;
    
    // Create a new thread for the hashing function
    if (pthread_create(&thread, NULL, hash_function, (void *)&data) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return;
    }
    
    // Detach the thread to allow it to run independently
    pthread_detach(thread);
    free(output);  // Allow output to be freed without waiting for the thread
}

// Main function
int main() {
    char input[BUFFER_SIZE];

    printf("Enter a string to hash using SHA256: ");
    fgets(input, BUFFER_SIZE, stdin);
    
    // Remove newline character read by fgets
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    
    // Perform asynchronous encryption
    async_encrypt(input);

    // Keep the main thread alive for a while to let the thread finish
    printf("Waiting for the hash operation to complete...\n");
    sleep(2);  // Wait time adjusted based on expected computation, not ideal for production

    printf("Main thread completed.\n");
    return 0;
}