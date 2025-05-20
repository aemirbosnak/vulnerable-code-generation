//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple XOR cipher
unsigned char *xor_cipher(unsigned char *plaintext, size_t plaintext_len, unsigned char *key, size_t key_len) {
    unsigned char *ciphertext = malloc(plaintext_len);
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    return ciphertext;
}

// A simple substitution cipher
unsigned char *substitution_cipher(unsigned char *plaintext, size_t plaintext_len, unsigned char *key) {
    unsigned char *ciphertext = malloc(plaintext_len);
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = key[plaintext[i]];
    }
    return ciphertext;
}

// A simple Vigenere cipher
unsigned char *vigenere_cipher(unsigned char *plaintext, size_t plaintext_len, unsigned char *key) {
    unsigned char *ciphertext = malloc(plaintext_len);
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    return ciphertext;
}

// A simple Caesar cipher
unsigned char *caesar_cipher(unsigned char *plaintext, size_t plaintext_len, int shift) {
    unsigned char *ciphertext = malloc(plaintext_len);
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = (plaintext[i] + shift) % 256;
    }
    return ciphertext;
}

// A simple RC4 cipher
unsigned char *rc4_cipher(unsigned char *plaintext, size_t plaintext_len, unsigned char *key) {
    unsigned char *ciphertext = malloc(plaintext_len);
    unsigned char s[256];
    unsigned char k[256];
    unsigned char t = 0;
    unsigned char i = 0;
    unsigned char j = 0;

    for (i = 0; i < 256; i++) {
        s[i] = i;
        k[i] = key[i % strlen(key)];
    }

    for (i = 0; i < 256; i++) {
        j = (j + s[i] + k[i]) % 256;
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    for (i = 0, j = 0, t = 0; i < plaintext_len; i++) {
        t = (t + 1) % 256;
        j = (j + s[t]) % 256;
        t = s[t];
        s[t] = s[j];
        s[j] = t;
        ciphertext[i] = plaintext[i] ^ s[(s[t] + s[j]) % 256];
    }

    return ciphertext;
}

int main() {
    // Plaintext to be encrypted
    unsigned char plaintext[] = "Hello, world!";

    // Key for the cipher
    unsigned char key[] = "secret";

    // Encrypt the plaintext using the XOR cipher
    unsigned char *ciphertext1 = xor_cipher(plaintext, strlen(plaintext), key, strlen(key));

    // Encrypt the plaintext using the substitution cipher
    unsigned char *ciphertext2 = substitution_cipher(plaintext, strlen(plaintext), key);

    // Encrypt the plaintext using the Vigenere cipher
    unsigned char *ciphertext3 = vigenere_cipher(plaintext, strlen(plaintext), key);

    // Encrypt the plaintext using the Caesar cipher
    unsigned char *ciphertext4 = caesar_cipher(plaintext, strlen(plaintext), 3);

    // Encrypt the plaintext using the RC4 cipher
    unsigned char *ciphertext5 = rc4_cipher(plaintext, strlen(plaintext), key);

    // Print the ciphertext
    printf("XOR cipher: %s\n", ciphertext1);
    printf("Substitution cipher: %s\n", ciphertext2);
    printf("Vigenere cipher: %s\n", ciphertext3);
    printf("Caesar cipher: %s\n", ciphertext4);
    printf("RC4 cipher: %s\n", ciphertext5);

    return 0;
}