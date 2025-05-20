//FormAI DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOW_SIZE 256
#define MAX_STR_LEN 1024

// Compression structure for a single character
typedef struct {
    int offset;
    int length;
    char next_char;
} CompressionInfo;

// Compression structure for the entire string
typedef struct {
    CompressionInfo *info;
    int num_compressions;
} CompressedStringInfo;

// Compress a given string using the Lempel-Ziv-Welch Compression Algorithm
CompressedStringInfo* compress_string(char *str) {
    
    // Create a window to keep track of previously seen characters
    int *window = malloc(WINDOW_SIZE * sizeof(int));
    memset(window, -1, WINDOW_SIZE * sizeof(int));
    
    int next_index = 0; // The next index where a new character can be inserted
    int str_len = strlen(str); // The length of the string
    
    CompressionInfo *info = malloc(str_len * sizeof(CompressionInfo));
    int num_compressions = 0;
    
    int current_index = 0;
    while (current_index < str_len) {
        
        int match_length = 0;
        int match_offset = 0;
        char next_char = str[current_index];
        
        // Look for the longest match in the window
        for (int i = 0; i < WINDOW_SIZE; i++) {
            int window_index = next_index - i + WINDOW_SIZE;
            if (window[window_index % WINDOW_SIZE] == -1) {
                continue;
            }
            int match_start = window[window_index % WINDOW_SIZE];
            int length = 0;
            while (match_start + length < current_index && str[match_start + length] == str[current_index + length]) {
                length++;
            }
            if (length > match_length) {
                match_length = length;
                match_offset = i - length;
                next_char = str[current_index + match_length];
            }
        }
        
        // Add the compression to the array of compressions
        CompressionInfo new_info = {
            .offset = match_offset,
            .length = match_length,
            .next_char = next_char
        };
        
        info[num_compressions++] = new_info;
        
        // Add the newly seen character to the sliding window and update the index
        window[next_index++ % WINDOW_SIZE] = current_index;
        
        // Advance the character index by the length of the match
        current_index += match_length + 1;
        
    }
    
    // Create a new CompressedStringInfo struct to store the compression information
    CompressedStringInfo *compressed_info = malloc(sizeof(CompressedStringInfo));
    compressed_info->info = info;
    compressed_info->num_compressions = num_compressions;
    
    // Free the memory used by the sliding window
    free(window);
    
    return compressed_info;
}

// A helper function to print the compressed string information
void print_compressed_string_info(CompressedStringInfo *compressed_info) {
    
    printf("Number of Compressions: %d\n", compressed_info->num_compressions);
    printf("Compressions:\n");
    
    for (int i = 0; i < compressed_info->num_compressions; i++) {
        CompressionInfo c = compressed_info->info[i];
        printf("(%d, %d, %c)\n", c.offset, c.length, c.next_char);
    }
    
}

int main() {
    
    // Read in a string from the user
    char str[MAX_STR_LEN];
    printf("Enter a string to compress: \n");
    fgets(str, MAX_STR_LEN, stdin);
    str[strcspn(str, "\n")] = 0;
    
    // Compress the string and print the compression information
    CompressedStringInfo *compressed_info = compress_string(str);
    printf("\nCompression Information:\n");
    print_compressed_string_info(compressed_info);
    
    // Free the memory used by the compressed string information
    free(compressed_info->info);
    free(compressed_info);
    
    return 0;
}