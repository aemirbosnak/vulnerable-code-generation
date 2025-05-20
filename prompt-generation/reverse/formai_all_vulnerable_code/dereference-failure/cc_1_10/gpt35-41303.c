//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {

    // Set up input variables
    char *input_str = "Hello World!\n";
    int input_len = strlen(input_str);
    int i;

    // Set up variables to hold encrypted and decrypted data
    unsigned char *encrypted_data;
    int encrypted_len;
    unsigned char *decrypted_data;
    int decrypted_len;

    // Set up encryption and decryption contexts
    EVP_CIPHER_CTX *enc_ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX *dec_ctx = EVP_CIPHER_CTX_new();

    // Set up key and initialization vector
    unsigned char key[32] = {0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
                             0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4};
    unsigned char iv[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

    // Set up encryption and decryption algorithms
    const EVP_CIPHER *enc_algo = EVP_aes_256_cbc();
    const EVP_CIPHER *dec_algo = EVP_aes_256_cbc();

    // Initialize encryption context
    EVP_EncryptInit_ex(enc_ctx, enc_algo, NULL, key, iv);

    // Get block size and maximum output size
    int block_size = EVP_CIPHER_CTX_block_size(enc_ctx);
    int max_output_size = input_len + block_size;
    encrypted_data = malloc(max_output_size);

    // Encrypt data
    EVP_EncryptUpdate(enc_ctx, encrypted_data, &encrypted_len, input_str, input_len);
    EVP_EncryptFinal_ex(enc_ctx, encrypted_data + encrypted_len, &i);
    encrypted_len += i;

    printf("Encrypted data: ");
    for (i = 0; i < encrypted_len; i++) {
        printf("%02x", encrypted_data[i]);
    }
    printf("\n");

    // Initialize decryption context
    EVP_DecryptInit_ex(dec_ctx, dec_algo, NULL, key, iv);

    // Get maximum output size
    max_output_size = encrypted_len;
    decrypted_data = malloc(max_output_size);

    // Decrypt data
    EVP_DecryptUpdate(dec_ctx, decrypted_data, &decrypted_len, encrypted_data, encrypted_len);
    EVP_DecryptFinal_ex(dec_ctx, decrypted_data + decrypted_len, &i);
    decrypted_len += i;

    printf("Decrypted data: ");
    for (i = 0; i < decrypted_len; i++) {
        printf("%c", decrypted_data[i]);
    }
    printf("\n");

    // Free memory and clean up contexts
    free(encrypted_data);
    free(decrypted_data);
    EVP_CIPHER_CTX_free(enc_ctx);
    EVP_CIPHER_CTX_free(dec_ctx);

    return 0;
}