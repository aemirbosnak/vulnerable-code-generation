//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char* brave_compress(char* str) {
    char* compressed = calloc(BUFFER_SIZE, sizeof(char));
    char prev = '\0';
    char ch;
    int freq = 0;
    int index = 0;
    int i = 0;
  
    while ((ch = str[i++]) != '\0') {
        if (prev == '\0') {
            prev = ch;
            freq = 1;
        } else if (prev == ch) {
            freq++;
        } else {
            // compress the previous character
            compressed[index++] = prev;
            if (freq > 1) {
                compressed[index++] = freq + '0';
            }
            freq = 1;
            prev = ch;
        }
    }
  
    // compress the last character
    compressed[index++] = prev;
    if (freq > 1) {
        compressed[index++] = freq + '0';
    }
    
    return compressed;
}

char* brave_decompress(char* compressed) {
    char* decompressed = calloc(BUFFER_SIZE, sizeof(char));
    int index = 0;
    int i = 0;
  
    while (compressed[i] != '\0') {
        char ch = compressed[i++];
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            int freq = compressed[i++] - '0';
            for (int j = 0; j < freq; j++) {
                decompressed[index++] = ch;
            }
        } else {
            decompressed[index++] = ch;
        }
    }
    
    return decompressed;
}

int main() {
    char str[] = "aaabbcccdddd";
    printf("Original string: %s\n", str);
    
    char* compressed = brave_compress(str);
    printf("Compressed string: %s\n", compressed);
    
    char* decompressed = brave_decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    
    free(compressed);
    free(decompressed);
    
    return 0;
}