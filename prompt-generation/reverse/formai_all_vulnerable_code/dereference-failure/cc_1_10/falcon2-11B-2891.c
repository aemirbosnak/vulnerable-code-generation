//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the string using RLE (Run-Length Encoding)
void compressString(char* input, char* output) {
    char* buffer = (char*)malloc(sizeof(char) * (strlen(input) + 1));
    int count = 0;

    // Count the occurrence of each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        if (buffer[count] == input[i]) {
            count++;
        } else {
            buffer[count] = input[i];
            count++;
            buffer[count] = '\0';
            sprintf(output, "%s%d", output, count);
            count = 1;
        }
    }

    // Append the remaining characters
    sprintf(output, "%s%d", output, count);
    sprintf(output, "%s", output);
}

// Function to decompress the compressed string using RLE
char* decompressString(char* compressed, char* output) {
    char* buffer = (char*)malloc(sizeof(char) * (strlen(compressed) + 1));
    int count = 0;

    // Decode the compressed string
    for (int i = 0; i < strlen(compressed); i++) {
        if (compressed[i] == '1') {
            count++;
        } else {
            sprintf(buffer, "%c", count);
            count = 0;
        }
    }

    // Append the remaining characters
    sprintf(buffer, "%c", count);
    sprintf(buffer, "%s", buffer);

    // Copy the decoded string to the output buffer
    strcpy(output, buffer);
}

int main() {
    char input[100];
    char output[100];

    // Get the input string
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compressString(input, output);

    // Decompress the compressed string
    decompressString(output, input);

    // Print the input and output strings
    printf("Original Input: %s\n", input);
    printf("Compressed Output: %s\n", output);

    return 0;
}