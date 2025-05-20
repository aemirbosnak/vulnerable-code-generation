//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_SIZE 256

int encrypt_text(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv,
                 unsigned char *ciphertext) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, KEY_SIZE, &enc_key) < 0) {
        return -1;
    }
    int len = 0;
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
    return plaintext_len;
}

int decrypt_text(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv,
                 unsigned char *plaintext) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, KEY_SIZE, &dec_key) < 0) {
        return -1;
    }
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &dec_key, iv, AES_DECRYPT);
    return ciphertext_len;
}


int main(int argc, char *argv[]) {

    //Generate a random key and IV 
    unsigned char key[KEY_SIZE / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    if (!RAND_bytes(key, sizeof(key))) {
        fprintf(stderr, "Could not generate random key\n");
        return -1;
    }

    if (!RAND_bytes(iv, sizeof(iv))) {
        fprintf(stderr, "Could not generate random IV\n");
        return -1;
    }

    //Read in the plaintext from a file
    char *filename = "plaintext.txt";
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Could not open input file: %s\n", filename);
        return -1;
    }

    fseek(input_file, 0, SEEK_END);
    int plaintext_size = ftell(input_file);
    rewind(input_file);

    unsigned char *plaintext = (unsigned char *) malloc(plaintext_size);
    if (fread(plaintext, 1, plaintext_size, input_file) != plaintext_size) {
        fclose(input_file);
        fprintf(stderr, "Could not read input file: %s\n", filename);
        return -1;
    }

    fclose(input_file);

    //Encrypt the plaintext
    int ciphertext_size = plaintext_size + AES_BLOCK_SIZE;
    unsigned char *ciphertext = (unsigned char *) malloc(ciphertext_size);

    int encrypted_len = encrypt_text(plaintext, plaintext_size, key, iv, ciphertext);
    if (encrypted_len < 0) {
        fprintf(stderr, "Encryption failed\n");
        return -1;
    }

    //Write the encrypted data to a file
    char *output_filename = "encrypted_text.bin";
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Could not open output file: %s\n", output_filename);
        return -1;
    }

    fwrite(ciphertext, 1, encrypted_len, output_file);

    fclose(output_file);

    //Read in the encrypted data
    input_file = fopen(output_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Could not open input file: %s\n", output_filename);
        return -1;
    }

    fseek(input_file, 0, SEEK_END);
    int encrypted_size = ftell(input_file);
    rewind(input_file);

    unsigned char *encrypted_text = (unsigned char *) malloc(encrypted_size);
    if (fread(encrypted_text, 1, encrypted_size, input_file) != encrypted_size) {
        fclose(input_file);
        fprintf(stderr, "Could not read input file: %s\n", output_filename);
        return -1;
    }

    fclose(input_file);

    //Decrypt the data
    unsigned char *decrypted_text = (unsigned char *) malloc(encrypted_size);
    int decrypted_len = decrypt_text(encrypted_text, encrypted_size, key, iv, decrypted_text);
    if (decrypted_len < 0) {
        fprintf(stderr, "Decryption failed\n");
        return -1;
    }

    //Write the decrypted data to a file
    char *decrypted_output_filename = "decrypted_text.txt";
    output_file = fopen(decrypted_output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Could not open output file: %s\n", decrypted_output_filename);
        return -1;
    }

    fwrite(decrypted_text, 1, decrypted_len, output_file);

    fclose(output_file);

    //Clean up
    free(plaintext);
    free(ciphertext);
    free(encrypted_text);
    free(decrypted_text);

    return 0;
}