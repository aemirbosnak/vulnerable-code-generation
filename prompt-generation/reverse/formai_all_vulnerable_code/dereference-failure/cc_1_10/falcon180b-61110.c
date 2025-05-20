//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <openssl/aes.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define BLOCK_SIZE 16
#define MAX_INPUT_SIZE 1024

int main() {
    char input_file[MAX_INPUT_SIZE];
    char output_file[MAX_INPUT_SIZE];
    char *key = malloc(KEY_SIZE + 1);
    char *iv = malloc(IV_SIZE + 1);
    char *input_buffer = malloc(MAX_INPUT_SIZE);
    char *output_buffer = malloc(MAX_INPUT_SIZE);
    FILE *in_file, *out_file;
    int in_size, out_size, i, j;
    AES_KEY aes_key;

    printf("Enter the input file path: ");
    scanf("%s", input_file);
    printf("Enter the output file path: ");
    scanf("%s", output_file);

    // Generate a random key and IV
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
    for (i = 0; i < IV_SIZE; i++) {
        iv[i] = rand() % 26 + 'a';
    }
    iv[IV_SIZE] = '\0';

    // Encrypt the input file
    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    fseek(in_file, 0, SEEK_END);
    in_size = ftell(in_file);
    rewind(in_file);
    fread(input_buffer, in_size, 1, in_file);
    fclose(in_file);
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    AES_cbc_encrypt(input_buffer, output_buffer, in_size, &aes_key, iv, AES_ENCRYPT);

    // Write the encrypted data to the output file
    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    fwrite(output_buffer, in_size, 1, out_file);
    fclose(out_file);
    printf("File encrypted successfully.\n");

    return 0;
}