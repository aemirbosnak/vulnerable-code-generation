//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
/* This C program encrypts a text file using a Cipher Block Chaining (CBC) mode of operation.
 * Our implementation of the CBC mode uses the advanced encryption standard (AES).
 * The program reads the contents of a file, encrypts them, and writes the encrypted data to a new file.
 * The encryption key, initialization vector, and the filenames are input by the user.
 * This program is named after Ada Lovelace, the first computer programmer in history.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_LEN 256
#define BLOCK_LEN 16


/* This function generates a random initialization vector 
 * using the OpenSSL library's RAND_bytes() function.
 */
void generate_iv(unsigned char *iv) {
    if (RAND_bytes(iv, BLOCK_LEN) == 0) {
        fprintf(stderr, "Error generating random bytes.\n");
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char* argv[]) {
    /* Argument Check */
    if (argc != 4) {
        printf("Usage: ./ada_file_encryption filename key iv\n");
        exit(EXIT_FAILURE);
    }

    /* Argument Parsing */
    char *filename = argv[1];
    char *key_str = argv[2];
    char *iv_str = argv[3];

    if (strlen(key_str) != KEY_LEN/8) {
        printf("Invalid key length. Required length is %d bytes.\n", KEY_LEN/8);
        exit(EXIT_FAILURE);
    }

    if (strlen(iv_str) != BLOCK_LEN) {
        printf("Invalid IV length. Required length is %d bytes.\n", BLOCK_LEN);
        exit(EXIT_FAILURE);
    }

    /* Key and IV Initialization */
    AES_KEY key;
    unsigned char iv[BLOCK_LEN];
    unsigned char key_uchar[KEY_LEN/8];
    memcpy(key_uchar, key_str, KEY_LEN/8);
    memcpy(iv, iv_str, BLOCK_LEN);

    if (AES_set_encrypt_key(key_uchar, KEY_LEN, &key) < 0) {
        fprintf(stderr, "Error setting encryption key.\n");
        exit(EXIT_FAILURE);
    }

    /* File Initialization and Reading */
    FILE *in_file = fopen(filename, "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(in_file, 0L, SEEK_END);
    long file_size = ftell(in_file);
    rewind(in_file);

    unsigned char *input_data = (unsigned char*)malloc(file_size + BLOCK_LEN);
    unsigned char *encrypted_data = (unsigned char*)malloc(file_size + BLOCK_LEN);
    int bytes_read = fread(input_data, sizeof(unsigned char), file_size, in_file);
    fclose(in_file);

    /* Padding */
    int remainder = (file_size + BLOCK_LEN) % BLOCK_LEN;
    int padding = BLOCK_LEN - remainder;
    memset((input_data + file_size), padding, padding);

    /* Encryption */
    generate_iv(iv);
    AES_cbc_encrypt(input_data, encrypted_data, (file_size + BLOCK_LEN), &key, iv, AES_ENCRYPT);

    /* Output File Writing */
    char *output_filename = (char*)malloc(strlen(filename) + 8);
    sprintf(output_filename, "%s.encrypted", filename);
    FILE *out_file = fopen(output_filename, "wb+");
    if (out_file == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(encrypted_data, sizeof(unsigned char), (file_size + BLOCK_LEN), out_file);
    fclose(out_file);

    /* Success Message */
    printf("Encryption successful. Encrypted file: %s\n", output_filename);

    free(input_data);
    free(encrypted_data);
    free(output_filename);

    return 0;
}