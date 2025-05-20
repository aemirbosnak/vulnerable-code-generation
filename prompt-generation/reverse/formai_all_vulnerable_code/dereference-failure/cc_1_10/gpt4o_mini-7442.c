//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_COMPRESSED_SIZE 512

typedef struct {
    unsigned char value;
    int count;
} CharFrequency;

void compress(const char *input, char *output) {
    CharFrequency freq[256] = { 0 };
    int i, j = 0;
    int len = strlen(input);
    
    // Count frequency of each character
    for (i = 0; i < len; i++) {
        freq[(unsigned char)input[i]].value = input[i];
        freq[(unsigned char)input[i]].count++;
    }

    // Create compressed string
    for (i = 0; i < 256; i++) {
        if (freq[i].count > 0) {
            j += snprintf(output + j, MAX_COMPRESSED_SIZE - j, "%c%d", freq[i].value, freq[i].count);
        }
    }
    output[j] = '\0'; // null-terminate the output string
}

void decompress(const char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        unsigned char value = input[i++];
        int count = 0;

        // Read the count of occurrences (can be more than one digit)
        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        for (int k = 0; k < count; k++) {
            output[j++] = value;
        }
    }
    output[j] = '\0'; // null-terminate the decompressed string
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <compress|decompress> <input_string>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    char *input_string = argv[2];

    if (strlen(input_string) > MAX_INPUT_SIZE) {
        printf("Input string exceeds maximum size of %d characters\n", MAX_INPUT_SIZE);
        return EXIT_FAILURE;
    }
    
    char compressed_string[MAX_COMPRESSED_SIZE];
    
    if (strcmp(action, "compress") == 0) {
        compress(input_string, compressed_string);
        printf("Compressed Output: %s\n", compressed_string);
    } else if (strcmp(action, "decompress") == 0) {
        char decompressed_string[MAX_INPUT_SIZE];
        decompress(input_string, decompressed_string);
        printf("Decompressed Output: %s\n", decompressed_string);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}