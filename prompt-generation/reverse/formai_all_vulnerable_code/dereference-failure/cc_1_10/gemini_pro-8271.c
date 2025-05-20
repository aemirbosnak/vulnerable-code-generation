//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our happy little compression function!
// It'll squish your data like a squishy toy!
char* compress(char* data) {
    // We'll keep track of our compressed data here.
    char* compressed = malloc(strlen(data) + 1);
    
    // Let's start our compression journey!
    int i = 0;
    int j = 0;
    char current = data[0];
    int count = 1;
    while (i < strlen(data)) {
        // Is our current character the same as the next one?
        // If so, let's count how many times it appears in a row.
        if (data[i] == current) {
            count++;
        } 
        // Oh no, it's different! Time to store our count and move on.
        else {
            compressed[j++] = current;
            compressed[j++] = count + '0';
            current = data[i];
            count = 1;
        }
        i++;
    }
    // Don't forget about the last character!
    compressed[j++] = current;
    compressed[j++] = count + '0';
    
    // We're done! Return our compressed data.
    return compressed;
}

// Let's try out our compression magic!
int main() {
    // Grab the data we want to compress.
    char* data = "AAABBBCCCDDDDDDEEEEEEFF";
    
    // Let's see the magic happen!
    char* compressed = compress(data);
    
    // Let's see what our compressed data looks like.
    printf("Compressed data: %s\n", compressed);
    
    // Free up our memory.
    free(compressed);
    return 0;
}