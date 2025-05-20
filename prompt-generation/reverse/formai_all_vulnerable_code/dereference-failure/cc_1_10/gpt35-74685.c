//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LEN 16    // Length of the encryption key
#define BUF_SIZE 1024 // Size of the buffer for input and output

// Function to generate a random encryption key
void generate_key(char *key) {
    int i;
    char rand_char;
    srand((unsigned) time(NULL)); // Seed the random number generator
    for(i = 0; i < KEY_LEN; i++) {
        rand_char = (char) (rand() % 256); // Generate a random ASCII character
        key[i] = rand_char;
    }
}

// Function to encrypt a file using the generated key
void encrypt(char *infile, char *outfile, char *key) {
    FILE *inptr, *outptr;
    char buf[BUF_SIZE];
    int i, j, len;

    inptr = fopen(infile, "rb");
    if(inptr == NULL) {
        printf("Error opening input file!\n");
        return;
    }

    outptr = fopen(outfile, "wb");
    if(outptr == NULL) {
        printf("Error opening output file!\n");
        return;
    }

    while((len = fread(buf, 1, BUF_SIZE, inptr)) > 0) {
        for(i = 0; i < len; i++) {
            j = i % KEY_LEN; // Use modulo operator to cycle through the key
            buf[i] ^= key[j]; // Perform XOR operation between the byte in the buffer and the corresponding key byte
        }
        fwrite(buf, 1, len, outptr);
    }

    fclose(inptr);
    fclose(outptr);
}

int main(int argc, char *argv[]) {
    char key[KEY_LEN];
    char infile[100], outfile[100];
    int i;

    if(argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    strcpy(infile, argv[1]);
    strcpy(outfile, argv[2]);

    generate_key(key);

    printf("Encryption key: ");
    for(i = 0; i < KEY_LEN; i++) {
        printf("%02X", (unsigned char) key[i]); // Print the key in hexadecimal format
    }
    printf("\n");

    printf("Encrypting file...\n");

    encrypt(infile, outfile, key);

    printf("Encryption complete!\n");

    return 0;
}