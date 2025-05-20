//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: relaxed
// Our very own file encryption extravaganza!

// Libraries we'll be using
#include <stdio.h>
#include <stdlib.h>

// Constants and macros for our encryption algorithm
#define KEY 42 // Our secret key
#define ENCRYPT(x) ((x) ^ KEY) // Encryption function
#define DECRYPT(x) ENCRYPT(x) // Decryption function, because it's the same

// Function to encrypt a file
void encryptFile(const char* input, const char* output) {
    // Open the input and output files
    FILE* in = fopen(input, "rb");
    FILE* out = fopen(output, "wb");

    // Check if the files were opened successfully
    if (!in || !out) {
        printf("Error opening files!\n");
        return;
    }

    // Read a byte from the input file
    unsigned char byte;
    while (fread(&byte, sizeof(byte), 1, in)) {
        // Encrypt the byte
        byte = ENCRYPT(byte);

        // Write the encrypted byte to the output file
        fwrite(&byte, sizeof(byte), 1, out);
    }

    // Close the files
    fclose(in);
    fclose(out);

    printf("File encrypted successfully!\n");
}

// Function to decrypt a file
void decryptFile(const char* input, const char* output) {
    // Open the input and output files
    FILE* in = fopen(input, "rb");
    FILE* out = fopen(output, "wb");

    // Check if the files were opened successfully
    if (!in || !out) {
        printf("Error opening files!\n");
        return;
    }

    // Read a byte from the input file
    unsigned char byte;
    while (fread(&byte, sizeof(byte), 1, in)) {
        // Decrypt the byte
        byte = DECRYPT(byte);

        // Write the decrypted byte to the output file
        fwrite(&byte, sizeof(byte), 1, out);
    }

    // Close the files
    fclose(in);
    fclose(out);

    printf("File decrypted successfully!\n");
}

// Main function
int main() {
    // Get the input and output file names from the user
    char input[256], output[256];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", input);
    printf("Enter the name of the output file: ");
    scanf("%s", output);

    // Encrypt the file
    encryptFile(input, output);

    // Decrypt the file
    decryptFile(output, "decrypted.txt");

    return 0;
}