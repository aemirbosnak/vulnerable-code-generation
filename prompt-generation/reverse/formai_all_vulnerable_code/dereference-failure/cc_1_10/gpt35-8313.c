//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// Function to print the result of encryption/decryption
void print_result(const char *title, const unsigned char *data, const int len)
{
    printf("%s: ", title);
    for(int i = 0; i < len; i++)
    {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

// Function to perform AES CBC mode encryption
void aes_cbc_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
                     unsigned char *iv, unsigned char *ciphertext)
{
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

// Function to perform AES CBC mode decryption
void aes_cbc_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
                     unsigned char *iv, unsigned char *plaintext)
{
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv, AES_DECRYPT);
}

int main()
{
    // Initialize plaintext, key and iv
    unsigned char plaintext[] = "Hello, I am a grateful chatbot!";
    unsigned char key[] = "my_secret_key_1234";
    unsigned char iv[] = "initialization_vec";

    // Compute the lengths of plaintext, key and iv
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int iv_len = strlen(iv);

    // Compute the length of ciphertext
    int ciphertext_len = ((plaintext_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;

    // Initialize ciphertext and decrypted plaintext pointers
    unsigned char *ciphertext = malloc(ciphertext_len);
    unsigned char *decrypted_plaintext = malloc(plaintext_len);

    // Perform encryption and decryption
    aes_cbc_encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    aes_cbc_decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);

    // Print the results
    print_result("Plaintext", plaintext, plaintext_len);
    print_result("Ciphertext", ciphertext, ciphertext_len);
    print_result("Decrypted Plaintext", decrypted_plaintext, plaintext_len);

    // Free the memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}