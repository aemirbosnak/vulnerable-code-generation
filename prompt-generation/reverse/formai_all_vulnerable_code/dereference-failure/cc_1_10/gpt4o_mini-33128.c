//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 128  // AES key size (128, 192, or 256 bits)
#define AES_BLOCK_SIZE 16  // AES block size for padding
#define IV_SIZE 16         // Size of Initialization Vector

// Function to handle errors
void handleErrors() {
    fprintf(stderr, "An error occurred.\n");
    exit(EXIT_FAILURE);
}

// Function to pad the plaintext to be a multiple of AES_BLOCK_SIZE
void pad(const char *input, unsigned char *output, int *out_len) {
    int input_len = strlen(input);
    int padding_len = AES_BLOCK_SIZE - (input_len % AES_BLOCK_SIZE);
    *out_len = input_len + padding_len;

    strncpy((char *)output, input, input_len);
    for (int i = 0; i < padding_len; i++) {
        output[input_len + i] = (unsigned char)padding_len;
    }
}

// Function to unpad the plaintext
void unpad(unsigned char *input, int *out_len) {
    int padding_len = input[*out_len - 1];
    *out_len -= padding_len;
}

// Function to encrypt the input text
void encrypt(const unsigned char *key, const char *input, unsigned char *output) {
    AES_KEY enc_key;
    unsigned char iv[IV_SIZE];

    // Generate IV
    if (!RAND_bytes(iv, sizeof(iv))) {
        handleErrors();
    }

    // Set AES encryption key
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &enc_key) < 0) {
        handleErrors();
    }

    // Perform encryption
    unsigned char padded_input[AES_BLOCK_SIZE * ((strlen(input) / AES_BLOCK_SIZE) + 1)];
    int padded_len;
    pad(input, padded_input, &padded_len);
    
    AES_cbc_encrypt(padded_input, output, padded_len, &enc_key, iv, AES_ENCRYPT);
}

// Function to decrypt the output text
void decrypt(const unsigned char *key, const unsigned char *input, unsigned char *output) {
    AES_KEY dec_key;
    unsigned char iv[IV_SIZE];

    // Initialization Vector needs to be known for decryption
    memcpy(iv, input, IV_SIZE);
    input += IV_SIZE;

    // Set AES decryption key
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &dec_key) < 0) {
        handleErrors();
    }

    // Perform decryption
    AES_cbc_encrypt(input, output, strlen((char *)input), &dec_key, iv, AES_DECRYPT);
    
    int output_len = strlen((char *)output);
    unpad(output, &output_len);
    output[output_len] = '\0'; // Null-terminate the decrypted output
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <key> <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *key_str = argv[2];
    const char *data = argv[3];

    unsigned char key[AES_KEY_SIZE / 8];
    strncpy((char *)key, key_str, sizeof(key)); // Use the first bytes of the key_str
    key[sizeof(key) - 1] = '\0'; // Ensure null-termination

    unsigned char output[1024]; // Buffer for encrypted/decrypted output

    if (strcmp(action, "encrypt") == 0) {
        encrypt(key, data, output);
        printf("Encrypted data: ");
        for (size_t i = 0; i < strlen(data) + AES_BLOCK_SIZE; i++) {
            printf("%02x", output[i]);
        }
        printf("\n");
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt(key, output, output);
        printf("Decrypted data: %s\n", output);
    } else {
        fprintf(stderr, "Invalid action. Please use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}