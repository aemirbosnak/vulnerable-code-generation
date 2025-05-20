//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define KEY_LENGTH 2048
#define EXPONENT 3
#define MESSAGE_SIZE 256

typedef struct {
    RSA *keypair;
} ThreadData;

void *encrypt_message(void *args) {
    ThreadData *data = (ThreadData *)args;
    char *message = "Hello, This is a Secret Message!";
    unsigned char encrypted[MESSAGE_SIZE];
    
    int encrypted_length = RSA_public_encrypt(strlen(message), 
                                               (unsigned char *)message, 
                                               encrypted, 
                                               data->keypair, 
                                               RSA_PKCS1_OAEP_PADDING);
    
    if (encrypted_length == -1) {
        ERR_print_errors_fp(stderr);
        pthread_exit(NULL);
    }

    printf("Encrypted Message: ");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");
    
    pthread_exit(NULL);
}

void *decrypt_message(void *args) {
    ThreadData *data = (ThreadData *)args;
    unsigned char encrypted[MESSAGE_SIZE] = { /* input encrypted message here in hex */ };
    unsigned char decrypted[MESSAGE_SIZE];
    
    // Example hex conversion to a byte array should match actual encryption bytes
    int decrypted_length = RSA_private_decrypt(MESSAGE_SIZE, 
                                                 encrypted, 
                                                 decrypted, 
                                                 data->keypair, 
                                                 RSA_PKCS1_OAEP_PADDING);
    
    if (decrypted_length == -1) {
        ERR_print_errors_fp(stderr);
        pthread_exit(NULL);
    }

    decrypted[decrypted_length] = '\0'; // Null-terminate the decrypted message
    printf("Decrypted Message: %s\n", decrypted);
    
    pthread_exit(NULL);
}

int main() {
    RSA *keypair = RSA_generate_key(KEY_LENGTH, EXPONENT, NULL, NULL);
    if (keypair == NULL) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    pthread_t encrypt_thread, decrypt_thread;
    ThreadData data;
    data.keypair = keypair;

    pthread_create(&encrypt_thread, NULL, encrypt_message, &data);
    pthread_join(encrypt_thread, NULL);

    // You would typically pass the correct previously encrypted bytes
    // Here just an example with zero-filled byte array for demonstration
    unsigned char encrypted_example[MESSAGE_SIZE] = { 0 };
    memcpy(encrypted_example, (unsigned char[]) { /* Fill with a valid encrypted message */ }, MESSAGE_SIZE);
    
    pthread_create(&decrypt_thread, NULL, decrypt_message, &data);
    pthread_join(decrypt_thread, NULL);
    
    RSA_free(keypair);
    return EXIT_SUCCESS;
}