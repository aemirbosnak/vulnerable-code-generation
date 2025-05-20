//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>

#define DICT_SIZE 256

char dictionary[DICT_SIZE][100]; // dictionary to hold compressed strings
int dict_count = 0; // number of compressed strings in the dictionary

/*
 * Compresses the input string using the LZW compression algorithm
 * Returns the compressed string
 */
char *compress_lzw(char *input) {
    if (*input == '\0') {
        // reached end of input string, return compressed result
        return dictionary[dict_count - 1];
    }
    
    char *sub_str = malloc(100 * sizeof(char));
    int i = 0;
    int prefix_idx = -1;
    while(*input != '\0') {
        sub_str[i++] = *input++;
        sub_str[i] = '\0';
        // check if sub string is in dictionary
        int j;
        for (j = 0; j < dict_count; j++) {
            if (strcmp(sub_str, dictionary[j]) == 0) {
                prefix_idx = j;
                break;
            }
        }
        if (prefix_idx == -1) {
            // sub string not in dictionary, add it to dictionary
            strcpy(dictionary[dict_count++], sub_str);
            return compress_lzw(--input); // pass prefix to the next recursive call
        } else {
            // sub string in dictionary, continue building string
            prefix_idx = -1;
        }
    }

    free(sub_str);

    // reached end of input string, return compressed result
    return dictionary[dict_count - 1];
}

int main() {
    // sample input string
    char *input = "Hello World! Hello World! Hello World!";
    
    // compress string using LZW algorithm
    char *compressed = compress_lzw(input);
    
    // print compressed string
    printf("Compressed String: %s\n", compressed);
    
    return 0;
}