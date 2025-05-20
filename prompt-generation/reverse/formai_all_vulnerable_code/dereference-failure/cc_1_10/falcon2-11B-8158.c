//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a file
void encryptFile(char* filename, char* key) {
    // Open the file in read mode
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return;
    }
    
    // Open the output file in write mode
    char* output_filename = malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");
    FILE* fp_enc = fopen(output_filename, "w");
    if (fp_enc == NULL) {
        printf("Error: Failed to open output file.\n");
        free(output_filename);
        return;
    }
    
    // Read the file byte by byte
    char byte;
    while (fread(&byte, 1, 1, fp) == 1) {
        // XOR the byte with the key
        byte ^= key[byte % strlen(key)];
        
        // Write the encrypted byte to the output file
        fwrite(&byte, 1, 1, fp_enc);
    }
    
    // Close the files
    fclose(fp);
    fclose(fp_enc);
    free(output_filename);
}

// Function to decrypt a file
void decryptFile(char* filename, char* key) {
    // Open the file in read mode
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return;
    }
    
    // Open the output file in write mode
    char* output_filename = malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".dec");
    FILE* fp_dec = fopen(output_filename, "w");
    if (fp_dec == NULL) {
        printf("Error: Failed to open output file.\n");
        free(output_filename);
        return;
    }
    
    // Read the file byte by byte
    char byte;
    while (fread(&byte, 1, 1, fp) == 1) {
        // XOR the byte with the key
        byte ^= key[byte % strlen(key)];
        
        // Write the decrypted byte to the output file
        fwrite(&byte, 1, 1, fp_dec);
    }
    
    // Close the files
    fclose(fp);
    fclose(fp_dec);
    free(output_filename);
}

// Main function
int main() {
    char* filename = "input.txt";
    char* key = "secret";
    
    // Encrypt the file
    encryptFile(filename, key);
    
    // Decrypt the file
    decryptFile(filename, key);
    
    return 0;
}