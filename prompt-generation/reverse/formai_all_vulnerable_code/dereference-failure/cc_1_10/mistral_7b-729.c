//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 32
#define IV_SIZE 16

void encrypt_file(const char *input_file, const char *output_file, const unsigned char *key, const unsigned char *iv) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input || !output) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE, &aes_key);

    unsigned char iv_buffer[IV_SIZE];
    memcpy(iv_buffer, iv, IV_SIZE);

    int len;
    char buffer[1024];

    do {
        len = fread(buffer, sizeof(char), sizeof(buffer), input);

        if (len > 0) {
            AES_cbc_encrypt(buffer, buffer, len, &aes_key, iv_buffer, AES_ENCRYPT);
            fwrite(buffer, sizeof(char), len, output);
        }
    } while (len > 0);

    fclose(input);
    fclose(output);
}

void generate_key(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] = rand() & 0xff;
    }
}

void generate_iv(unsigned char *iv) {
    for (int i = 0; i < IV_SIZE; ++i) {
        iv[i] = rand() & 0xff;
    }
}

int main() {
    srand(time(NULL));

    const char *input_file = "input.txt";
    const char *output_file = "output.enc";

    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];

    generate_key(key);
    generate_iv(iv);

    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        printf("%.2x ", key[i]);
    }
    printf("\n");

    printf("IV: ");
    for (int i = 0; i < IV_SIZE; ++i) {
        printf("%.2x ", iv[i]);
    }
    printf("\n");

    encrypt_file(input_file, output_file, key, iv);

    printf("File encrypted successfully.\n");

    return 0;
}