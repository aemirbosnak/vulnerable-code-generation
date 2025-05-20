//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void encrypt_file(const char *input_file, const char *output_file, int key);
void decrypt_file(const char *input_file, const char *output_file, int key);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    int key = atoi(argv[4]);

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void encrypt_file(const char *input_file, const char *output_file, int key) {
    FILE *ifp = fopen(input_file, "rb");
    if (!ifp) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *ofp = fopen(output_file, "wb");
    if (!ofp) {
        perror("Error opening output file");
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(ifp)) != EOF) {
        fputc(ch ^ key, ofp);  // XOR encryption
    }

    fclose(ifp);
    fclose(ofp);
    printf("File encrypted successfully and saved as '%s'.\n", output_file);
}

void decrypt_file(const char *input_file, const char *output_file, int key) {
    FILE *ifp = fopen(input_file, "rb");
    if (!ifp) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *ofp = fopen(output_file, "wb");
    if (!ofp) {
        perror("Error opening output file");
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(ifp)) != EOF) {
        fputc(ch ^ key, ofp);  // XOR decryption
    }

    fclose(ifp);
    fclose(ofp);
    printf("File decrypted successfully and saved as '%s'.\n", output_file);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <mode> <input_file> <output_file> <key>\n", program_name);
    printf("Modes:\n");
    printf("    encrypt  : Encrypt the file.\n");
    printf("    decrypt  : Decrypt the file.\n");
    printf("Key: An integer value used for the XOR operation.\n");
}