//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_banner() {
    printf("*****************************************\n");
    printf("*         Welcome to C File Encryptor   *\n");
    printf("*       A Creative Encryption Utility     *\n");
    printf("*****************************************\n");
}

void print_usage() {
    printf("Usage: encryptor <input_file> <output_file> <key>\n");
    printf("Example: encryptor myfile.txt output.txt mysecret\n");
}

void encrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *infile, *outfile;
    char ch;
    int key_length = strlen(key);
    int i = 0;

    infile = fopen(input_file, "rb");
    if (infile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outfile = fopen(output_file, "wb");
    if (outfile == NULL) {
        perror("Error opening output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(infile)) != EOF) {
        // Encrypting character by shifting using key
        ch ^= key[i % key_length];
        fputc(ch, outfile);
        i++;
    }

    fclose(infile);
    fclose(outfile);
    printf("Encryption complete! Encrypted file saved as %s\n", output_file);
}

void decrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *infile, *outfile;
    char ch;
    int key_length = strlen(key);
    int i = 0;

    infile = fopen(input_file, "rb");
    if (infile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outfile = fopen(output_file, "wb");
    if (outfile == NULL) {
        perror("Error opening output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(infile)) != EOF) {
        // Decrypting character by reversing the key shift
        ch ^= key[i % key_length];
        fputc(ch, outfile);
        i++;
    }

    fclose(infile);
    fclose(outfile);
    printf("Decryption complete! Decrypted file saved as %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        display_banner();
        print_usage();
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key = argv[3];

    display_banner();
    
    // Encrypting and then decrypting the file for demonstration
    encrypt_file(input_file, output_file, key);

    char decrypted_file[] = "decrypted_output.txt";
    decrypt_file(output_file, decrypted_file, key);

    printf("Original file: %s\n", input_file);
    printf("Encrypted file: %s\n", output_file);
    printf("Decrypted file: %s\n", decrypted_file);

    return EXIT_SUCCESS;
}