//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant values of buffer size and compression ratio
#define BUFFER_SIZE 1024
#define COMPRESSION_RATIO 2

// Function to compress a given string using run-length encoding
char* compress_string(char* str) {
    const int length = strlen(str);
    char* buffer = malloc(BUFFER_SIZE * sizeof(char));
    int count = 1, index = 0, i;

    // Iterate through the input string
    for (i = 1; i < length; ++i) {
        // If the previous and current characters are the same, increment the count
        if (str[i] == str[i - 1]) {
            ++count;
        }
        // Otherwise, output the previous character and its count
        else {
            buffer[index] = str[i - 1];
            buffer[index + 1] = count + '0';  // Convert count to char
            index += 2;
            count = 1;
        }

        // If the buffer is almost full, output its contents and reset the index
        if (index + 2 > BUFFER_SIZE) {
            printf("%s", buffer);
            memset(buffer, 0, BUFFER_SIZE * sizeof(char));
            index = 0;
        }
    }

    // Output the last character and its count
    buffer[index] = str[i - 1];
    buffer[index + 1] = count + '0';
    index += 2;

    // Add a null terminator at the end of the output buffer
    buffer[index] = '\0';

    // Reallocate the output buffer to its actual size
    buffer = realloc(buffer, (index + 1) * sizeof(char));

    return buffer;
}

int main() {
    // Initialize the input and output strings
    char input[] = "aaabbccaaddeee";
    char* output = compress_string(input);

    // Print the compressed string
    printf("%s\n", output);

    // Free the allocated memory
    free(output);

    return 0;
}