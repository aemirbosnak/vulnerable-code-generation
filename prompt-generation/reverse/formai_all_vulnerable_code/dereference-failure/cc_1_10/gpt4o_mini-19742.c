//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 256

// Structure to hold thread data
typedef struct {
    char *text;
    char *key;
    char *result;
} CryptoData;

// Function to perform a simple Caesar Cipher encryption
void *caesar_cipher(void *data) {
    CryptoData *cryptoData = (CryptoData *)data;
    int key = atoi(cryptoData->key) % 26; // Only use modulo 26 for the key
    char *text = cryptoData->text;
    char *result = cryptoData->result;

    for (int i = 0; text[i] != '\0'; i++) {
        char current_char = text[i];
        // Check if character is uppercase
        if (current_char >= 'A' && current_char <= 'Z') {
            result[i] = ((current_char - 'A' + key) % 26) + 'A';
        }
        // Check if character is lowercase
        else if (current_char >= 'a' && current_char <= 'z') {
            result[i] = ((current_char - 'a' + key) % 26) + 'a';
        }
        // Non-alphabet characters remain unchanged
        else {
            result[i] = current_char;
        }
    }
    result[strlen(text)] = '\0'; // Null-terminate the result
    return NULL;
}

// Function to create threads and perform encryption
void encrypt_with_threads(char *text, char *key) {
    pthread_t threads[MAX_THREADS];
    CryptoData cryptoData[MAX_THREADS];
    char *results[MAX_THREADS];
    int length = strlen(text);
    int chunk_size = length / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        cryptoData[i].text = &text[i * chunk_size];
        cryptoData[i].key = key;
        results[i] = malloc((chunk_size + 1) * sizeof(char));
        cryptoData[i].result = results[i];

        if (i == MAX_THREADS - 1) { // last thread may take the remainder
            cryptoData[i].text = &text[i * chunk_size];
            chunk_size += length % MAX_THREADS;
        }

        pthread_create(&threads[i], NULL, caesar_cipher, (void *)&cryptoData[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine results
    char final_result[BUFFER_SIZE] = "";
    for (int i = 0; i < MAX_THREADS; i++) {
        strcat(final_result, results[i]);
    }

    printf("Encrypted text: %s\n", final_result);

    // Free allocated memory
    for (int i = 0; i < MAX_THREADS; i++) {
        free(results[i]);
    }
}

int main() {
    char text[BUFFER_SIZE];
    char key[10];

    // Example usage
    printf("Enter text to encrypt: ");
    fgets(text, BUFFER_SIZE, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter key for encryption (integer): ");
    fgets(key, 10, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    // Run encryption in a multi-threaded way
    encrypt_with_threads(text, key);
   
    return 0;
}