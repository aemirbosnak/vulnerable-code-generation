//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
unsigned char *encrypt(unsigned char *plaintext, unsigned char *key);
unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key);
void print_hex(unsigned char *data, int len);

int main()
{
    unsigned char plaintext[] = "Hello, world!";
    unsigned char key[] = "secretkey";
    unsigned char *ciphertext = encrypt(plaintext, key);
    
    printf("Encrypted ciphertext:\n");
    print_hex(ciphertext, strlen(plaintext));
    
    unsigned char *decrypted_text = decrypt(ciphertext, key);
    printf("Decrypted plaintext: %s\n", decrypted_text);
    
    free(ciphertext);
    free(decrypted_text);
    
    return 0;
}

// implementation of the encryption function
unsigned char *encrypt(unsigned char *plaintext, unsigned char *key)
{
    int len = strlen(plaintext);
    int keylen = strlen(key);
    
    unsigned char *ciphertext = (unsigned char *)malloc(len+1);
    memset(ciphertext, 0, len+1);
    
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % keylen];
    }
    
    return ciphertext;
}

// implementation of the decryption function
unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key)
{
    int len = strlen(ciphertext);
    int keylen = strlen(key);
    
    unsigned char *plaintext = (unsigned char *)malloc(len+1);
    memset(plaintext, 0, len+1);
    
    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % keylen];
    }
    
    return plaintext;
}

// helper function to print a byte array as hex
void print_hex(unsigned char *data, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}