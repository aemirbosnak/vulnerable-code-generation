//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define IV_LENGTH 16

typedef struct {
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];
} encryption_context;

void generate_key(unsigned char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

void generate_iv(unsigned char* iv) {
    srand(time(NULL));
    for (int i = 0; i < IV_LENGTH; i++) {
        iv[i] = rand() % 256;
    }
}

void encrypt(unsigned char* input, int input_length, unsigned char* key, unsigned char* iv, unsigned char* output) {
    unsigned char buffer[16] = {0};
    int num = 0;
    int j = 0;

    for (int i = 0; i < input_length; i += 16) {
        for (int k = 0; k < 16 && i + k < input_length; k++) {
            buffer[k] = input[i + k];
        }

        for (int k = 0; k < 16; k++) {
            output[j++] = buffer[k] ^ key[k];
        }
    }
}

void decrypt(unsigned char* input, int input_length, unsigned char* key, unsigned char* iv, unsigned char* output) {
    unsigned char buffer[16] = {0};
    int num = 0;
    int j = 0;

    for (int i = 0; i < input_length; i += 16) {
        for (int k = 0; k < 16 && i + k < input_length; k++) {
            buffer[k] = input[i + k];
        }

        for (int k = 0; k < 16; k++) {
            output[j++] = buffer[k] ^ key[k];
        }
    }
}

int main() {
    encryption_context context;

    generate_key(context.key);
    generate_iv(context.iv);

    unsigned char input[] = "Hello, world!";
    int input_length = strlen((char*)input);

    unsigned char output[input_length + 16];

    encrypt(input, input_length, context.key, context.iv, output);

    printf("Encrypted message: %s\n", output);

    decrypt(output, input_length + 16, context.key, context.iv, output);

    printf("Decrypted message: %s\n", output);

    return 0;
}