//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR encryption/decryption function
void xor_crypt(char *plaintext, char *key, char *ciphertext) {
    int i, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    ciphertext[len] = '\0';
}

// Base64 encoding/decoding functions
char base64_table[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

char *base64_encode(const char *input) {
    int len = strlen(input);
    int output_len = ((len + 2) / 3) * 4;
    char *output = malloc(output_len + 1);
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < len; i += 3, j += 4) {
        int n1 = input[i] >> 2;
        int n2 = ((input[i] & 3) << 4) | (input[i + 1] >> 4);
        int n3 = ((input[i + 1] & 15) << 2) | (input[i + 2] >> 6);
        int n4 = input[i + 2] & 63;
        output[j] = base64_table[n1];
        output[j + 1] = base64_table[n2];
        output[j + 2] = (i + 1 < len) ? base64_table[n3] : '=';
        output[j + 3] = (i + 2 < len) ? base64_table[n4] : '=';
    }
    output[output_len] = '\0';
    return output;
}

char *base64_decode(const char *input) {
    int len = strlen(input);
    int output_len = (len * 3) / 4;
    char *output = malloc(output_len + 1);
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < len; i += 4, j += 3) {
        int n1 = base64_table[input[i]] << 2;
        int n2 = (base64_table[input[i + 1]] & 0x30) >> 4;
        int n3 = (base64_table[input[i + 1]] & 0x0F) << 4;
        int n4 = (base64_table[input[i + 2]] & 0x3C) >> 2;
        int n5 = (base64_table[input[i + 2]] & 0x03) << 6;
        int n6 = base64_table[input[i + 3]] & 0x3F;
        output[j] = n1 | n2 | n3;
        output[j + 1] = (i + 2 < len) ? (n4 | n5) : 0;
        output[j + 2] = (i + 3 < len) ? n6 : 0;
    }
    output[output_len] = '\0';
    return output;
}

int main() {
    // Define the plaintext, key, and ciphertext variables
    char plaintext[] = "Hello, world!";
    char key[] = "secret";
    char ciphertext[100];

    // Encrypt the plaintext using XOR encryption
    xor_crypt(plaintext, key, ciphertext);

    // Encode the ciphertext using Base64 encoding
    char *encoded_ciphertext = base64_encode(ciphertext);

    // Print the encoded ciphertext
    printf("Encoded ciphertext: %s\n", encoded_ciphertext);

    // Decode the encoded ciphertext using Base64 decoding
    char *decoded_ciphertext = base64_decode(encoded_ciphertext);

    // Decrypt the decoded ciphertext using XOR decryption
    xor_crypt(decoded_ciphertext, key, plaintext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", plaintext);

    // Free the allocated memory
    free(encoded_ciphertext);
    free(decoded_ciphertext);

    return 0;
}