//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char* compress(const char* input);
char* decompress(const char* input);
void print_usage();

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char* action = argv[1];
    char* input = argv[2];

    if (strcmp(action, "compress") == 0) {
        char* compressed = compress(input);
        if(compressed) {
            printf("Compressed: %s\n", compressed);
            free(compressed);
        }
    } 
    else if (strcmp(action, "decompress") == 0) {
        char* decompressed = decompress(input);
        if(decompressed) {
            printf("Decompressed: %s\n", decompressed);
            free(decompressed);
        }
    } 
    else {
        print_usage();
        return 1;
    }

    return 0;
}

// Compress function using Run-Length Encoding
char* compress(const char* input) {
    size_t len = strlen(input);
    if (len == 0) return strdup("");

    char* compressed = malloc(len * 2); // Worst-case scenario allocation
    if (!compressed) return NULL;

    int count = 1;
    int j = 0;

    for (size_t i = 1; i <= len; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            j += sprintf(&compressed[j], "%c%d", input[i - 1], count);
            count = 1;
        }
    }

    return realloc(compressed, j + 1); // Resize to actual size
}

// Decompress function
char* decompress(const char* input) {
    char* decompressed = malloc(strlen(input) * 10); // Oversized allocation
    if (!decompressed) return NULL;

    int j = 0;
    for (size_t i = 0; input[i] != '\0'; i += 2) {
        char character = input[i];
        int count = input[i + 1] - '0'; // Assuming single digit counts only
        for (int k = 0; k < count; k++) {
            decompressed[j++] = character;
        }
    }
    decompressed[j] = '\0'; // Null-terminate string
    return realloc(decompressed, j + 1); // Resize to actual size
}

// Print usage information
void print_usage() {
    printf("Usage: ./compressor [compress|decompress] [string]\n");
    printf("Example: ./compressor compress aaabbc\n");
    printf("         ./compressor decompress a3b2c1\n");
}