//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 256 // AES Key size in bits
#define BLOCK_SIZE 16     // Block size in bytes

void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(EXIT_FAILURE);
}

void generate_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_SIZE / 8)) {
        handleErrors();
    }
}

void encrypt_file(const char *input_file, const char *output_file, unsigned char *key) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");
    AES_KEY enc_key;
    unsigned char buffer[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];
    int num_bytes_read;
    
    if (!infile || !outfile) {
        handleErrors();
    }

    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &enc_key) < 0) {
        handleErrors();
    }

    fprintf(outfile, "Encrypted with AES %d\n", AES_KEY_SIZE);
    
    while ((num_bytes_read = fread(buffer, 1, BLOCK_SIZE, infile)) > 0) {
        if (num_bytes_read < BLOCK_SIZE) {
            memset(buffer + num_bytes_read, BLOCK_SIZE - num_bytes_read, BLOCK_SIZE - num_bytes_read);
        }
        AES_encrypt(buffer, output, &enc_key);
        fwrite(output, 1, BLOCK_SIZE, outfile);
    }

    fclose(infile);
    fclose(outfile);
}

void decrypt_file(const char *input_file, const char *output_file, unsigned char *key) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");
    AES_KEY dec_key;
    unsigned char buffer[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];
    int num_bytes_read;
    
    if (!infile || !outfile) {
        handleErrors();
    }

    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &dec_key) < 0) {
        handleErrors();
    }

    fgets(buffer, BLOCK_SIZE, infile); // Skip the header line

    while ((num_bytes_read = fread(buffer, 1, BLOCK_SIZE, infile)) > 0) {
        AES_decrypt(buffer, output, &dec_key);
        if (num_bytes_read < BLOCK_SIZE) {
            fwrite(output, 1, num_bytes_read, outfile);
            break;
        }
        fwrite(output, 1, BLOCK_SIZE, outfile);
    }

    fclose(infile);
    fclose(outfile);
}

int main(int argc, char *argv[]) {
    unsigned char key[AES_KEY_SIZE / 8];

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        generate_key(key);
        encrypt_file(argv[2], argv[3], key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        printf("Enter the AES key in hex format (64 characters):\n");
        char hex_key[AES_KEY_SIZE / 4 + 1];
        scanf("%s", hex_key);
        for (int i = 0; i < AES_KEY_SIZE / 8; i++) {
            sscanf(hex_key + 2*i, "%2hhx", &key[i]);
        }
        decrypt_file(argv[2], argv[3], key);
        printf("File decrypted successfully.\n");
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}