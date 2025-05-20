//FormAI DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 0x1F // Encryption key

// Function to encrypt the file
void encrypt(FILE *input_file, FILE *output_file) {
    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        // XOR operation with encryption key
        ch = ch ^ KEY;
        fputc(ch, output_file);
    }
    printf("File encrypted successfully!\n");
}

// Function to decrypt the file
void decrypt(FILE *input_file, FILE *output_file) {
    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        // XOR operation with encryption key
        ch = ch ^ KEY;
        fputc(ch, output_file);
    }
    printf("File decrypted successfully!\n");
}

int main(int argc, char *argv[]) {
    // Check for valid number of arguments
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <e/d>\n", argv[0]);
        return 1;
    }
    FILE *input_file, *output_file;
    input_file = fopen(argv[1], "rb");
    output_file = fopen(argv[2], "wb");
    // Check if input file exists
    if (input_file == NULL) {
        printf("Error: %s does not exist.\n", argv[1]);
        return 1;
    }   
    // Encrypt or decrypt file based on user input
    if (strcmp(argv[3], "e") == 0) {
       encrypt(input_file, output_file);
    } else if (strcmp(argv[3], "d") == 0) {
       decrypt(input_file, output_file);
    } else {
        printf("Invalid option: %s\n", argv[3]);
        return 1;
    }
    // Close both the files
    fclose(input_file);
    fclose(output_file);
    return 0;
}