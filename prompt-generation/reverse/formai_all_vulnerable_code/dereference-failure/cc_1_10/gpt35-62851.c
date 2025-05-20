//FormAI DATASET v1.0 Category: Compression algorithms ; Style: excited
//Wooohooo! It's compression time! Get ready to save some space!
#include <stdio.h>
#include <stdlib.h>

//Defining some constants
#define MAXLENGTH 100000
#define MAXVALUE 255

// Function to perform run-length encoding compression
void rle_compress(char *input_string, char *compressed_string) {
    int length = strlen(input_string);
    int count = 1;

    // Loop through each character of the input string
    for (int i=1; i<length; i++) {
        if (input_string[i] == input_string[i-1] && count < MAXVALUE) {
            // Increment count if the current char is the same as the previous one
            count++;
        } else {
            // Write the count and the character to the compressed string
            compressed_string[strlen(compressed_string)] = (char) count;
            compressed_string[strlen(compressed_string)] = input_string[i-1];
            count = 1;
        }
    }
    // Write the last count and character to the compressed string
    compressed_string[strlen(compressed_string)] = (char) count;
    compressed_string[strlen(compressed_string)] = input_string[length-1];
}

// Function to perform run-length decoding compression
void rle_decompress(char *compressed_string, char *decompressed_string) {
    int length = strlen(compressed_string);
    int count;

    // Loop through each character of the compressed string
    for (int i=0; i<length; i+=2) {
        count = compressed_string[i];
        for (int j=0; j<count; j++) {
            // Write the character count times to the decompressed string
            decompressed_string[strlen(decompressed_string)] = compressed_string[i+1];
        }
    }
}

int main() {
    char input_string[MAXLENGTH];
    char compressed_string[MAXLENGTH];
    char decompressed_string[MAXLENGTH];
    
    // Get user input
    printf("Enter string to compress: ");
    fgets(input_string, MAXLENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // Remove newline character from input
    
    // Perform compression and decompression
    rle_compress(input_string, compressed_string);
    rle_decompress(compressed_string, decompressed_string);
    
    // Print output
    printf("Original string: %s\n", input_string);
    printf("Compressed string: %s\n", compressed_string);
    printf("Decompressed string: %s\n", decompressed_string);

    return 0;
}