//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [mode: encrypt/decrypt] [input file] [output file]\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *input_filename = argv[2];
    char *output_filename = argv[3];

    EVP_CIPHER_CTX *context;
    unsigned char key[] = "mysecretpassword";
    unsigned char iv[] = "0123456789012345";

    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'\n", input_filename);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_data = calloc(input_file_size, sizeof(unsigned char));
    fread(input_data, sizeof(unsigned char), input_file_size, input_file);
    fclose(input_file);

    unsigned char *output_data = calloc(input_file_size + EVP_MAX_BLOCK_LENGTH, sizeof(unsigned char));
    int output_size;

    context = EVP_CIPHER_CTX_new();
    if (strcmp(mode, "encrypt") == 0) {
        EVP_EncryptInit_ex(context, EVP_aes_256_cbc(), NULL, key, iv);
        EVP_EncryptUpdate(context, output_data, &output_size, input_data, input_file_size);
        EVP_EncryptFinal_ex(context, output_data + output_size, &output_size);
    } else if (strcmp(mode, "decrypt") == 0) {
        EVP_DecryptInit_ex(context, EVP_aes_256_cbc(), NULL, key, iv);
        EVP_DecryptUpdate(context, output_data, &output_size, input_data, input_file_size);
        EVP_DecryptFinal_ex(context, output_data + output_size, &output_size);
    } else {
        printf("Error: invalid mode '%s', must be 'encrypt' or 'decrypt'\n", mode);
        return 1;
    }

    EVP_CIPHER_CTX_free(context);

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file '%s'\n", output_filename);
        return 1;
    }

    fwrite(output_data, sizeof(unsigned char), output_size, output_file);
    fclose(output_file);

    printf("%s %sd file '%s' to '%s'\n", strcmp(mode, "encrypt") == 0 ? "Encrypte" : "Decrypte", input_filename, output_filename);

    free(input_data);
    free(output_data);

    return 0;
}