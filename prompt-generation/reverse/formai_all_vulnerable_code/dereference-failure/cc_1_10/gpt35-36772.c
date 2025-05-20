//FormAI DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size that can be compressed
#define MAX_SIZE 100

// Function to compress a string
char* compress(char* input) {
    
    int length = strlen(input);
    
    // Allocate memory for output string
    char* output = (char*) malloc(MAX_SIZE * sizeof(char));
    int output_index = 0;
    
    // Traverse input string
    for(int i = 0; i < length; i++) {
        
        // Find frequency of each character
        int count = 1;
        while(i < length - 1 && input[i] == input[i+1]) {
            count++;
            i++;
        }
        
        // Store character and its frequency in output string
        output[output_index++] = input[i];
        output[output_index++] = '0' + count;
        
    }
    
    // Add null terminator to output string
    output[output_index] = '\0';
    
    // Check if compressed string is shorter than original string
    if(output_index < length) {
        return output;
    }
    else {
        return input;
    }
    
}

int main() {
    
    // Input string
    char input[MAX_SIZE];
    printf("Enter input string: ");
    scanf("%s", input);
    
    // Compress input string
    char* output = compress(input);
    printf("Compressed string: %s\n", output);
    
    return 0;
    
}