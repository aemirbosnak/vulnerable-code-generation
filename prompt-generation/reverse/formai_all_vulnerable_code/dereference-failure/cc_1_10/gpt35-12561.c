//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 32  // Length of the encryption key
#define BUF_SIZE 1024  // Buffer size for reading from input file

int main(int argc, char *argv[]) {
    char *in_file, *out_file;  // File names for input and output
    char *key = malloc(sizeof(char) * (KEY_LENGTH + 1));  // Allocate memory for key
    memset(key, 0, sizeof(char) * (KEY_LENGTH + 1));  // Set memory to 0
    srand(time(NULL));  // Seed random number generator with current time
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = (char) (rand() % 256);  // Generate random characters for key
    }
    if (argc == 3) {
        in_file = argv[1];
        out_file = argv[2];
    } else {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        free(key);  // Free allocated memory for key
        return 1;
    }
    FILE *in = fopen(in_file, "rb");  // Open input file in binary mode
    if (!in) {
        printf("Error: could not open input file %s\n", in_file);
        free(key);
        return 1;
    }
    FILE *out = fopen(out_file, "wb");  // Open output file in binary mode
    if (!out) {
        printf("Error: could not open output file %s\n", out_file);
        fclose(in);  // Close input file
        free(key);
        return 1;
    }
    fwrite(key, sizeof(char), KEY_LENGTH, out);  // Write key to output file
    char *buf = malloc(sizeof(char) * BUF_SIZE);  // Allocate memory for buffer
    memset(buf, 0, sizeof(char) * BUF_SIZE);  // Set memory to 0
    int n;
    while ((n = fread(buf, sizeof(char), BUF_SIZE, in)) != 0) {
        for (int i = 0; i < n; i++) {
            buf[i] ^= key[i % KEY_LENGTH];  // XOR buffer with key
        }
        fwrite(buf, sizeof(char), n, out);  // Write encrypted buffer to output file
        memset(buf, 0, sizeof(char) * BUF_SIZE);  // Set memory to 0
    }
    fclose(in);  // Close input file
    fclose(out);  // Close output file
    free(buf);  // Free allocated memory for buffer
    free(key);  // Free allocated memory for key
    printf("Encryption complete.\n");
    return 0;
}