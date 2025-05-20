//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compress the input string using a unique algorithm
void compress(char *input, char *output, int size) {
    // Initialize output array with zeros
    memset(output, 0, size);
    
    // Loop through input string
    for (int i = 0; i < size; i++) {
        // If current character is the same as the previous character,
        // increment the count and skip the current character
        if (input[i] == input[i - 1]) {
            int count = 1;
            while (i + count < size && input[i + count] == input[i - 1]) {
                count++;
            }
            output[i - 1] = input[i];
            for (int j = 1; j < count; j++) {
                output[i + j] = input[i + j];
            }
            i += count;
        } else {
            output[i] = input[i];
            i++;
        }
    }
    
    // Copy the remaining characters of the input string
    for (int i = i; i < size; i++) {
        output[i] = input[i];
    }
    
    // Print the compressed string
    printf("%s\n", output);
}

int main() {
    char input[100];
    char output[100];
    int size = 0;
    
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    size = strlen(input);
    
    compress(input, output, size);
    
    printf("Compressed string: %s\n", output);
    
    return 0;
}