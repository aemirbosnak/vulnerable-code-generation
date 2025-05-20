//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void encrypt(char *input_file, char *output_file, char *key) {
    FILE *fin, *fout;
    char buffer[MAX_BUFFER_SIZE];
    int i, j, len_key, len_buffer;
    
    // Open input and output file
    fin = fopen(input_file, "rb");
    fout = fopen(output_file, "wb");
    
    if (fin == NULL) {
        printf("Error: Could not open input file!\n");
        exit(1);
    }
    
    if (fout == NULL) {
        printf("Error: Could not open output file!\n");
        exit(1);
    }
    
    // Get length of key
    len_key = strlen(key);
    
    // Read input file and encrypt each character
    while (!feof(fin)) {
        len_buffer = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, fin);
        
        for (i = 0; i < len_buffer; i++) {
            buffer[i] ^= key[i % len_key];
        }
        
        fwrite(buffer, sizeof(char), len_buffer, fout);
    }
    
    // Close input and output file
    fclose(fin);
    fclose(fout);
}

int main() {
    char input_file[] = "example.txt";
    char output_file[] = "example.enc";
    char key[] = "encryption_key123";
    
    encrypt(input_file, output_file, key);
    
    printf("Encryption complete!\n");
    
    return 0;
}