//FormAI DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>

int main(int argc, char* argv[]) {

    // Input parameters
    char* input_text = "Hello world!";
    char* key = "0123456789abcdef";
    unsigned char iv[] = { 0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef };
    int input_len = strlen(input_text);

    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

    // Initialize AES encryption and set key and IV
    const EVP_CIPHER* cipher_type = EVP_aes_128_cbc();
    EVP_EncryptInit_ex(ctx, cipher_type, NULL, (unsigned char*)key, iv);

    // Allocate memory for output buffer
    int max_output_len = input_len + EVP_CIPHER_block_size(cipher_type);
    unsigned char* output = (unsigned char*)malloc(max_output_len);
    if (!output) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    // Encrypt input text and store in output buffer
    int output_len = 0;
    if (!EVP_EncryptUpdate(ctx, output, &output_len, (unsigned char*)input_text, input_len)) {
        printf("Error: encryption failed.\n");
        return 1;
    }

    // Finalize encryption and add remaining padding
    int final_len = 0;
    if (!EVP_EncryptFinal_ex(ctx, output + output_len, &final_len)) {
        printf("Error: encryption finalization failed.\n");
        return 1;
    }
    output_len += final_len;

    // Print encrypted output
    printf("Plain text: %s\n", input_text);
    printf("Encrypted text (hex): ");
    for (int i = 0; i < output_len; i++) {
        printf("%02x", output[i]);
    }

    // Clean up resources
    free(output);
    EVP_CIPHER_CTX_free(ctx);
    EVP_cleanup();
    return 0;
}