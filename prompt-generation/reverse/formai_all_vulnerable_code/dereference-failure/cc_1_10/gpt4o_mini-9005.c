//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY 0xAA // Example encryption key (simple XOR)

// Function to encrypt or decrypt the data
void process_file(const char *input_file, const char *output_file) {
    FILE *infile, *outfile;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }

    outfile = fopen(output_file, "wb");
    if (!outfile) {
        perror("Unable to open output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Read the file in chunks and process it
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, infile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY; // Simple XOR encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, outfile);
    }

    fclose(infile);
    fclose(outfile);
}

// Function to display usage instructions
void display_usage() {
    printf("Usage: file_encryptor <encrypt|decrypt> <input_file> <output_file>\n");
    printf("Example: file_encryptor encrypt myfile.txt myfile.enc\n");
    printf("         file_encryptor decrypt myfile.enc myfile_dec.txt\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        display_usage();
        exit(EXIT_FAILURE);
    }

    const char *action = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    if (strcmp(action, "encrypt") == 0) {
        printf("Encrypting file '%s' and saving as '%s'...\n", input_file, output_file);
        process_file(input_file, output_file);
        printf("Encryption complete.\n");
    } else if (strcmp(action, "decrypt") == 0) {
        printf("Decrypting file '%s' and saving as '%s'...\n", input_file, output_file);
        process_file(input_file, output_file);
        printf("Decryption complete.\n");
    } else {
        display_usage();
        exit(EXIT_FAILURE);
    }

    return 0;
}