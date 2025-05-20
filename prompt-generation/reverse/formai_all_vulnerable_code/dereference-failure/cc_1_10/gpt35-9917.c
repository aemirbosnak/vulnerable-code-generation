//FormAI DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Function to compress a string
char* compress(char* str) {
    int len = strlen(str);
    
    // Create a buffer to hold the compressed string
    char *buffer = malloc(MAX_BUFFER_SIZE * sizeof(char));
    memset(buffer, 0, MAX_BUFFER_SIZE);
    
    int count, pos = 0;
    for (int i = 0; i < len; i += count) {
        count = 1;
        while ((i + count) < len && str[i + count] == str[i])
            count++;
        
        // Append the character and its count to the buffer
        sprintf(buffer + pos, "%c%d", str[i], count);
        
        // Update the position to append the next character and its count
        pos = strlen(buffer);
        
        // Check if the buffer size has exceeded the max buffer size
        if (pos >= MAX_BUFFER_SIZE) {
            fprintf(stderr, "ERROR: Max buffer size exceeded. Unable to compress.\n");
            return NULL;
        }
    }
    
    // Return the compressed string
    return buffer;
}

int main() {
    char *str = "aaabbbbcccccdddddeeeeffffff";
    char *compressed_str = compress(str);
    
    if (compressed_str == NULL)
        return 1;
    
    printf("Original String: %s\n", str);
    printf("Compressed String: %s\n", compressed_str);
    
    free(compressed_str);
    
    return 0;
}