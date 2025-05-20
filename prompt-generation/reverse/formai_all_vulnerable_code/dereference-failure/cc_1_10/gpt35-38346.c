//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
/* 
 * Linus Torvalds-style Modern Encryption example program 
 * 
 * This program demonstrates a simple XOR-based encryption technique using a randomly generated key.
 * It takes in a text file as input and encrypts it using the key. The encrypted data is then written to a new file.
 * To decrypt the data, run the same program again with the 'decrypt' flag.
 * 
 * Author: Linuxize (inspired by Linus Torvalds)
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 50
#define BUFFER_SIZE 1024

int encrypt(char file_in[], char file_out[], char key[]) {
    FILE *in, *out;
    int key_len = strlen(key), i = 0, j = 0, k = 0, bytes_read, bytes_written;
    unsigned char buffer[BUFFER_SIZE];

    // open input file
    if ((in  = fopen(file_in, "rb")) == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // open output file
    if ((out = fopen(file_out, "wb")) == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    srand(time(NULL)); // seed random number generator

    // generate a random key if one isn't provided
    if (key_len == 0) {
        char c;
        for (i = 0; i < MAX_KEY_LENGTH; i++) {
            c = rand() % 256;
            key[i] = c;
        }
        key_len = MAX_KEY_LENGTH;
    }

    // encrypt data
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[j];
            j = (j + 1) % key_len;
        }
        bytes_written = fwrite(buffer, 1, bytes_read, out);
        if (bytes_written < bytes_read) {
            perror("Error writing to output file");
            return EXIT_FAILURE;
        }
    }

    // close files
    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}

int decrypt(char file_in[], char file_out[], char key[]) {
    // to decrypt, just run the encrypt function with the same key
    return encrypt(file_in, file_out, key);
}

int main(int argc, char *argv[]) {
    char *file_in, *file_out, *key = "";
    int i;

    // argument parsing
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) { 
            file_in = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0) {
            file_out = argv[++i];
        } else if (strcmp(argv[i], "-k") == 0) {
            key = argv[++i];
        } else if (strcmp(argv[i], "-d") == 0) {
            decrypt(file_in, file_out, key);
            return EXIT_SUCCESS;
        }
    }

    // validate arguments
    if (file_in == NULL) {
        perror("Input file required (-i)");
        return EXIT_FAILURE;
    }
    if (file_out == NULL) {
        perror("Output file required (-o)");
        return EXIT_FAILURE;
    }

    // encrypt file
    if (encrypt(file_in, file_out, key) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}