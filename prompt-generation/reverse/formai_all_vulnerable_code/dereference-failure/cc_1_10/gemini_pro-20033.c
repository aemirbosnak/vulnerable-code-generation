//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file
void encrypt_file(FILE *input, FILE *output, int shift) {
    // Read the file character by character
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // Encrypt the character
        ch += shift;
        
        // Handle wrap-around
        if (ch > 126) {
            ch -= 94;
        }
        
        // Write the encrypted character to the output file
        fputc(ch, output);
    }
}

// Function to decrypt a file
void decrypt_file(FILE *input, FILE *output, int shift) {
    // Read the file character by character
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // Decrypt the character
        ch -= shift;
        
        // Handle wrap-around
        if (ch < 32) {
            ch += 94;
        }
        
        // Write the decrypted character to the output file
        fputc(ch, output);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <shift>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Open the input and output files
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }
    
    // Get the shift value
    int shift = atoi(argv[3]);
    
    // Encrypt or decrypt the file
    if (shift > 0) {
        encrypt_file(input, output, shift);
    } else {
        decrypt_file(input, output, -shift);
    } 
    
    // Close the files
    fclose(input);
    fclose(output);
    
    return EXIT_SUCCESS;
}