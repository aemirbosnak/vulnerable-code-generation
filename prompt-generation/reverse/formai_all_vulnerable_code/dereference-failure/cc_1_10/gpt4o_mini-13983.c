//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define KEY_SIZE 2048
#define PUB_EXP 3
#define BUFFER_SIZE 256

typedef struct {
    RSA *rsa;
    unsigned char *plaintext;
    unsigned char *encrypted;
} thread_data;

void *encrypt_message(void *arg) {
    thread_data *data = (thread_data *)arg;
    int encrypted_length = RSA_public_encrypt(strlen((char *)data->plaintext), data->plaintext,
                                               data->encrypted, data->rsa, RSA_PKCS1_PADDING);
    if (encrypted_length == -1) {
        fprintf(stderr, "Error encrypting data: %s\n", ERR_error_string(ERR_get_error(), NULL));
        pthread_exit(NULL);
    }
    return NULL;
}

void *decrypt_message(void *arg) {
    thread_data *data = (thread_data *)arg;
    unsigned char *decrypted = malloc(BUFFER_SIZE);
    int decrypted_length = RSA_private_decrypt(RSA_size(data->rsa), data->encrypted,
                                                decrypted, data->rsa, RSA_PKCS1_PADDING);
    if (decrypted_length == -1) {
        fprintf(stderr, "Error decrypting data: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(decrypted);
        pthread_exit(NULL);
    }
    decrypted[decrypted_length] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted message: %s\n", decrypted);
    free(decrypted);
    return NULL;
}

void generate_keys(RSA **rsa) {
    *rsa = RSA_generate_key(KEY_SIZE, PUB_EXP, NULL, NULL);
    if (*rsa == NULL) {
        fprintf(stderr, "Error generating RSA keys: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(EXIT_FAILURE);
    }
}

int main() {
    pthread_t thread1, thread2;
    RSA *rsa = NULL;
    unsigned char *plaintext = (unsigned char *)"Hello, this is a test message!";
    unsigned char *encrypted = malloc(RSA_size(rsa));
    
    // Generate RSA keys
    generate_keys(&rsa);
    
    thread_data data;
    data.rsa = rsa;
    data.plaintext = plaintext;
    data.encrypted = encrypted;

    // Create a thread for encryption
    if (pthread_create(&thread1, NULL, encrypt_message, (void *)&data)) {
        fprintf(stderr, "Error creating encryption thread\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the encryption thread to finish
    if (pthread_join(thread1, NULL)) {
        fprintf(stderr, "Error joining encryption thread\n");
        exit(EXIT_FAILURE);
    }

    printf("Encrypted message: ");
    for (int i = 0; i < RSA_size(rsa); i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    // Create a thread for decryption
    if (pthread_create(&thread2, NULL, decrypt_message, (void *)&data)) {
        fprintf(stderr, "Error creating decryption thread\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the decryption thread to finish
    if (pthread_join(thread2, NULL)) {
        fprintf(stderr, "Error joining decryption thread\n");
        exit(EXIT_FAILURE);
    }

    // Clean up
    RSA_free(rsa);
    free(encrypted);

    return 0;
}