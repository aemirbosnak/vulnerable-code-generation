//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

void encrypt(FILE *fp_read, FILE *fp_write, char *passphrase);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [input_file] [output_file] [passphrase]\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *passphrase = argv[3];

    FILE *fp_read = fopen(input_file, "rb");
    if (fp_read == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *fp_write = fopen(output_file, "wb");
    if (fp_write == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(fp_read);
        return 1;
    }

    encrypt(fp_read, fp_write, passphrase);

    fclose(fp_read);
    fclose(fp_write);

    printf("Encryption complete.\n");
    return 0;
}

void encrypt(FILE *fp_read, FILE *fp_write, char *passphrase) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    // XOR each byte of the input file with each character of the passphrase
    unsigned char *pass_ptr = (unsigned char *) passphrase;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fp_read)) > 0) {
        unsigned char *buf_ptr = (unsigned char *) buffer;
        for (size_t i = 0; i < bytes_read; i++) {
            *buf_ptr = (*buf_ptr) ^ (*pass_ptr);
            buf_ptr++;
            pass_ptr++;
            if (*pass_ptr == '\0') {
                pass_ptr = (unsigned char *) passphrase;
            }
        }
        fwrite(buffer, sizeof(char), bytes_read, fp_write);
    }
}