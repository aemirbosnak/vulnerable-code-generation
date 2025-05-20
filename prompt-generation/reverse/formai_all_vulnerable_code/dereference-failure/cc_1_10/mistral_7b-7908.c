//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xDEADBEEF
#define BUF_SIZE 100

void encrypt(unsigned char *plaintext, unsigned char *ciphertext, int length) {
    int i;
    for (i = 0; i < length; i++) {
        ciphertext[i] = plaintext[i] ^ KEY;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <inputfile> <outputfile>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    char buffer[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUF_SIZE, input)) > 0) {
        unsigned char *plaintext = buffer;
        unsigned char *ciphertext = malloc(bytes_read * sizeof(unsigned char));

        encrypt(plaintext, ciphertext, bytes_read);

        fwrite(ciphertext, sizeof(char), bytes_read, output);

        free(ciphertext);
    }

    fclose(input);
    fclose(output);

    return 0;
}