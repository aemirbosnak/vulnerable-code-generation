//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_file, char *output_file, char *key) {
    // Open the input file for reading
    FILE *in_file = fopen(input_file, "rb");
    if (!in_file) {
        fprintf(stderr, "Error opening input file!\n");
        exit(1);
    }
    
    // Create the output file for writing
    FILE *out_file = fopen(output_file, "wb");
    if (!out_file) {
        fprintf(stderr, "Error creating output file!\n");
        exit(1);
    }
    
    // Loop through each byte of the input file
    int i = 0;
    char byte;
    while (fread(&byte, 1, 1, in_file) == 1) {
        // XOR the byte with the corresponding key byte
        byte ^= key[i];
        i = (i + 1) % strlen(key);
        
        // Write the encrypted byte to the output file
        fwrite(&byte, 1, 1, out_file);
    }
    
    // Close the input and output files
    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    // Ensure that all required arguments are provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        exit(1);
    }
    
    // Encrypt the input file and write the result to the output file
    encrypt(argv[1], argv[2], argv[3]);
    
    // Print a success message
    printf("Encryption successful!\n");
    
    return 0;
}