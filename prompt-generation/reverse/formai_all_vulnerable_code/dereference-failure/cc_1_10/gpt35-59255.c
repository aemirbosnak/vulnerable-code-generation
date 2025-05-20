//FormAI DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* input_file, char* output_file, char* key) {
    FILE *file_in, *file_out;
    int i, key_length;
    char c, *output_key;

    // Get length of key and allocate memory for output_key
    key_length = strlen(key);
    output_key = (char*) malloc(key_length + 1);

    // Copy key into output_key and append null terminator
    strcpy(output_key, key);
    output_key[key_length] = '\0';
    
    // Open input and output files in binary mode
    file_in = fopen(input_file, "rb");
    file_out = fopen(output_file, "wb");

    // Loop through input file character by character
    while((c = fgetc(file_in)) != EOF) {
        
        // XOR each character with corresponding character in key
        for(i = 0; i < key_length; i++) {
            c ^= output_key[i];
        }
        
        // Write encrypted character to output file
        fputc(c, file_out);
        
        // Shift key by one position to the left
        output_key[key_length - 1] = output_key[0];
        for(i = 0; i < key_length - 1; i++) {
            output_key[i] = output_key[i + 1];
        }
    }

    // Close files and free memory
    fclose(file_in);
    fclose(file_out);
    free(output_key); 
}

int main() {
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char key[] = "secretkey";
    
    // Encrypt input file and save to output file
    encrypt(input_file, output_file, key);
    
    printf("Encryption complete.\n");
    return 0;
}