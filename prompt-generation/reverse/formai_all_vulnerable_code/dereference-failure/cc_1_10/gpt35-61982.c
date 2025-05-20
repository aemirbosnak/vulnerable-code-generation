//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define compression factor
#define COMPRESSION_FACTOR 2

// Function to compress input string
void compressString(char* input) {
    int len = strlen(input);
    int i, j;

    // Allocate memory for the compressed string
    char* output = (char*)malloc(sizeof(char) * (len/COMPRESSION_FACTOR + 1));
    if(output == NULL) {
        printf("Error: Unable to allocate memory for output string.\n");
        exit(1);
    }

    // Compress the string:
    // Copy the first character
    output[0] = input[0];
    j = 1;

    // Iterate over the string
    for(i = 1; i < len; i++) {
        // If the current character matches the previous character, increment count
        if(input[i] == input[i-1]) {
            j++;
        }
        else {
            // Otherwise, if count is greater than compression factor, add the count to the output string
            if(j > COMPRESSION_FACTOR) {
                output[strlen(output)] = (char) (j + '0');
            }
            // Add the current character to the output string
            output[strlen(output)] = input[i];
            j = 1;
        }
    }
    
    // Add any remaining count to the output string
    if(j > COMPRESSION_FACTOR) {
        output[strlen(output)] = (char) (j + '0');
    }

    // Print compressed string
    printf("Compressed string: %s\n", output);
}

int main() {
    // Get input string from user
    printf("Enter string to compress: ");
    char input[100];
    scanf("%s", input);

    // Compress the string
    compressString(input);

    return 0;
}