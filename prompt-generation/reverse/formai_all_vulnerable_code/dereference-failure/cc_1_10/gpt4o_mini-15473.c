//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressRLE(const char *input, char *output) {
    int count;
    int i, j = 0;
    int len = strlen(input);
    
    for (i = 0; i < len; i++) {
        // Count occurrences of the character
        count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Append to output
        j += sprintf(output + j, "%c%d", input[i], count);
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char input[1024];
    char *output;
    
    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Allocate memory for output
    output = (char *)malloc(2 * length * sizeof(char)); // Worst case scenario
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Compress the input string
    compressRLE(input, output);
    
    // Print the result
    printf("Compressed string: %s\n", output);
    
    // Free allocated memory
    free(output);
    return EXIT_SUCCESS;
}