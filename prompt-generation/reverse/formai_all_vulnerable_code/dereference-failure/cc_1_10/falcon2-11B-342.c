//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Encryption function using XOR operation
void encrypt(char *plaintext, char *key) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = plaintext[i] ^ key[i % 3];
    }
}

// Decryption function using XOR operation
void decrypt(char *ciphertext, char *key) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = ciphertext[i] ^ key[i % 3];
    }
}

// Read a file and write the encrypted data to another file
void encrypt_file(const char *input_file, const char *output_file) {
    FILE *inptr, *outptr;
    char c;
    int count = 0;

    inptr = fopen(input_file, "r");
    outptr = fopen(output_file, "w");

    if (inptr == NULL || outptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((c = fgetc(inptr))!= EOF) {
        encrypt(&c, "abc");
        fputc(c, outptr);
        count++;
    }

    fclose(inptr);
    fclose(outptr);

    printf("Encrypted %d bytes from %s to %s\n", count, input_file, output_file);
}

int main() {
    const char *input_file = "input.txt";
    const char *output_file = "output.txt";

    encrypt_file(input_file, output_file);

    return 0;
}