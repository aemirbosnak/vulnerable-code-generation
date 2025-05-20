//FormAI DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 8

unsigned char key[KEY_LEN] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};

void encrypt(unsigned char *input, unsigned char *output, int len)
{
    unsigned char x = 0;
    for(int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i % KEY_LEN] ^ x;
        x = output[i];
    }
}

void decrypt(unsigned char *input, unsigned char *output, int len)
{
    unsigned char x = 0;
    for(int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i % KEY_LEN] ^ x;
        x = input[i];
    }
}

int main()
{
    char data[] = "Hello, world!";
    int len = strlen(data);

    // Allocate memory for encrypted message
    unsigned char *enc = malloc(len);
    memset(enc, 0, len);

    // Encrypt message
    encrypt(data, enc, len);
    printf("Encrypted message: ");
    for(int i = 0; i < len; i++) {
        printf("%02X ", enc[i]);
    }
    printf("\n");

    // Allocate memory for decrypted message
    unsigned char *dec = malloc(len);
    memset(dec, 0, len);

    // Decrypt message
    decrypt(enc, dec, len);
    printf("Decrypted message: ");
    for(int i = 0; i < len; i++) {
        printf("%c", dec[i]);
    }
    printf("\n");

    free(enc);
    free(dec);

    return 0;
}