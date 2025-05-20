//FormAI DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define KEY 0x5 // Encryption key

void encrypt(char *input_file, char *output_file);
void decrypt(char *input_file, char *output_file);

int main(int argc, char *argv[]) {
    char *input_file, *output_file;
    int option;
    
    // Check user input
    if (argc != 4) {
        printf("Usage: ./encryptor <option> <input file> <output file>\n");
        printf("Options:\n");
        printf("\t1. Encrypt\n");
        printf("\t2. Decrypt\n");
        return 1;
    }
    
    // Set variables
    option = atoi(argv[1]);
    input_file = argv[2];
    output_file = argv[3];
    
    // Call encrypt/decrypt based on user input
    switch (option) {
        case 1:
            encrypt(input_file, output_file);
            break;
        case 2:
            decrypt(input_file, output_file);
            break;
        default:
            printf("Invalid option.\n");
            return 1;
    }
    
    return 0;
}

// Function to encrypt input file and write to output file
void encrypt(char *input_file, char *output_file) {
    FILE *in, *out;
    char ch;
    
    // Open files
    if ((in = fopen(input_file, "rb")) == NULL) {
        printf("Input file %s cannot be opened.\n", input_file);
        exit(1);
    }
    if ((out = fopen(output_file, "wb")) == NULL) {
        printf("Output file %s cannot be opened.\n", output_file);
        exit(1);
    }
    
    // Encrypt data
    while ((ch = fgetc(in)) != EOF) {
        ch = ch ^ KEY; // XOR each byte with encryption key
        fputc(ch, out);
    }
    
    // Close files
    fclose(in);
    fclose(out);
    
    printf("Encryption successful.\n");
}

// Function to decrypt input file and write to output file
void decrypt(char *input_file, char *output_file) {
    encrypt(input_file, output_file); // Decryption is just encryption with the same key
}