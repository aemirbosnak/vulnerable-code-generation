//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

void encrypt_decrypt(char *input, char *output, const char *key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
    output[strlen(input)] = '\0'; // Null-terminate the output
}

void process_file(const char *input_file, const char *output_file, const char *key, int mode) {
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");
    if (infile == NULL || outfile == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, infile)) > 0) {
        if (mode == 1) { // Encryption mode
            encrypt_decrypt(buffer, output, key);
        } else { // Decryption mode
            encrypt_decrypt(buffer, output, key);
        }
        fwrite(output, 1, bytes_read, outfile);
    }

    fclose(infile);
    fclose(outfile);
}

void display_usage() {
    printf("Usage: file_encryptor <input-file> <output-file> <key> <mode>\n");
    printf("Modes: 1 for encrypt, 0 for decrypt\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *key = argv[3];
    int mode = atoi(argv[4]);

    if (mode != 0 && mode != 1) {
        fprintf(stderr, "Invalid mode. Use 1 for encrypt or 0 for decrypt.\n");
        return EXIT_FAILURE;
    }

    process_file(input_file, output_file, key, mode);
    printf("%s completed successfully.\n", mode == 1 ? "Encryption" : "Decryption");

    return EXIT_SUCCESS;
}