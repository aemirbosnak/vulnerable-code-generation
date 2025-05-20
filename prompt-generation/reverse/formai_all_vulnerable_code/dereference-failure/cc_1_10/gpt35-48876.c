//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Irregular C Compression Algorithm
// This algorithm compresses a string of characters
// by converting each character to its ASCII value,
// then adding a random value between 1 and 10 to it.
// The resulting value is then converted back to a character.
char* compress(char* string) {
    int len = strlen(string);
    char* compressed = malloc(len * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        int ascii_val = (int)string[i];
        int compressed_val = ascii_val + rand() % 10 + 1;
        compressed[i] = (char)compressed_val;
    }
    return compressed;
}

// This function decompresses a compressed string
// by subtracting the random value that was added
// during compression, then converting the result
// back to a character.
char* decompress(char* compressed) {
    int len = strlen(compressed);
    char* decompressed = malloc(len * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        int compressed_val = (int)compressed[i];
        int decompressed_val = compressed_val - rand() % 10 - 1;
        decompressed[i] = (char)decompressed_val;
    }
    return decompressed;
}

int main() {
    char* message = "Hello, world!";
    printf("Original message: %s\n", message);

    char* compressed = compress(message);

    printf("Compressed message: %s\n", compressed);

    char* decompressed = decompress(compressed);

    printf("Decompressed message: %s\n", decompressed);

    return 0;
}