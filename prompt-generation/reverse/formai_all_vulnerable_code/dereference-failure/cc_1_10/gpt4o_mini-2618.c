//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define SHIFT 3 // The shift for the Caesar Cipher

typedef struct {
    char* message;
    char* result;
    int shift;
} thread_data_t;

void* encrypt(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    for (int i = 0; data->message[i] != '\0'; i++) {
        char c = data->message[i];
        if (c >= 'a' && c <= 'z') {
            data->result[i] = (c - 'a' + data->shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            data->result[i] = (c - 'A' + data->shift) % 26 + 'A';
        } else {
            data->result[i] = c; // Non-alphabetic characters are unchanged
        }
    }
    data->result[strlen(data->message)] = '\0'; // Null-terminate the result
    return NULL;
}

void* decrypt(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    for (int i = 0; data->message[i] != '\0'; i++) {
        char c = data->message[i];
        if (c >= 'a' && c <= 'z') {
            data->result[i] = (c - 'a' - data->shift + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            data->result[i] = (c - 'A' - data->shift + 26) % 26 + 'A';
        } else {
            data->result[i] = c; // Non-alphabetic characters are unchanged
        }
    }
    data->result[strlen(data->message)] = '\0'; // Null-terminate the result
    return NULL;
}

int main() {
    pthread_t encrypt_thread, decrypt_thread;
    char message[BUFFER_SIZE];
    
    printf("Enter a message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    char* encrypted_message = (char*)malloc(strlen(message) + 1);
    char* decrypted_message = (char*)malloc(strlen(message) + 1);
    
    thread_data_t encrypt_data = { message, encrypted_message, SHIFT };
    thread_data_t decrypt_data = { encrypted_message, decrypted_message, SHIFT };

    // Create and start the encryption thread
    pthread_create(&encrypt_thread, NULL, encrypt, (void*)&encrypt_data);
    pthread_join(encrypt_thread, NULL); // Wait for the encryption to finish
    printf("Encrypted message: %s\n", encrypted_message);

    // Create and start the decryption thread
    pthread_create(&decrypt_thread, NULL, decrypt, (void*)&decrypt_data);
    pthread_join(decrypt_thread, NULL); // Wait for the decryption to finish
    printf("Decrypted message: %s\n", decrypted_message);

    // Clean up
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}