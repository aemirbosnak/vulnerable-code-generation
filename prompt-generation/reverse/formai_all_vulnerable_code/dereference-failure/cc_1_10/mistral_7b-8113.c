//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#define KEY_LENGTH 16
#define BLOCK_SIZE AES_BLOCK_SIZE
#define BUF_SIZE (BLOCK_SIZE + 1)
void encrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }
    int len;
    unsigned char iv[BLOCK_SIZE];
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_LENGTH * 8, &aes_key);
    char buffer[BUF_SIZE];
    while ((len = fread(buffer, 1, BUF_SIZE, input)) > 0) {
        AES_cbc_encrypt(&len, buffer, buffer, &aes_key, iv, 1);
        fwrite(buffer, len, 1, output);
        if (len < BUF_SIZE) break;
    }
    fclose(input);
    fclose(output);
}
void decrypt_file(const char *input_file, const char *output_file, const unsigned char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }
    int len;
    unsigned char iv[BLOCK_SIZE];
    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_LENGTH * 8, &aes_key);
    char buffer[BUF_SIZE];
    while ((len = fread(buffer, 1, BUF_SIZE, input)) > 0) {
        AES_cbc_encrypt(&len, buffer, buffer, &aes_key, iv, 0);
        fwrite(buffer, len, 1, output);
        if (len < BUF_SIZE) break;
    }
    fclose(input);
    fclose(output);
}
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <key> <encrypt|decrypt>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    unsigned char key[KEY_LENGTH];
    int i;
    for (i = 0; i < KEY_LENGTH; ++i) {
        key[i] = atoi(argv[3] + i);
    }
    const char *mode = argv[4];
    if (strcmp(mode, "encrypt") != 0 && strcmp(mode, "decrypt") != 0) {
        printf("Invalid mode. Use 'encrypt' or 'decrypt'\n");
        return EXIT_FAILURE;
    }
    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else {
        decrypt_file(input_file, output_file, key);
    }
    return EXIT_SUCCESS;
}