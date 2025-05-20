//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to compress a string using run-length encoding
void compress(char* input, char* output) {
    int length = strlen(input);
    int count = 0;
    char* output_buffer = (char*)malloc(length + 1);
    output_buffer[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (i == 0 || input[i]!= input[i - 1]) {
            output_buffer[count] = input[i];
            count++;
        } else {
            output_buffer[count] = input[i];
            count++;
        }
    }

    output_buffer[count] = '\0';
    strcpy(output, output_buffer);
}

// Function to decompress a compressed string using run-length encoding
void decompress(char* compressed, char* output) {
    int length = strlen(compressed);
    int count = 0;
    char* output_buffer = (char*)malloc(length + 1);
    output_buffer[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (compressed[i] == '\0') {
            break;
        } else if (compressed[i] == ',') {
            count++;
            output_buffer[count] = compressed[i + 1];
            output_buffer[count + 1] = compressed[i + 2];
            count += 2;
        }
    }

    output_buffer[count] = '\0';
    strcpy(output, output_buffer);
}

// Function to run-length encode a string
void encode(char* input, char* output) {
    int length = strlen(input);
    int count = 0;
    char* output_buffer = (char*)malloc(length + 1);
    output_buffer[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (i == 0 || input[i]!= input[i - 1]) {
            output_buffer[count] = input[i];
            count++;
        } else {
            output_buffer[count] = input[i];
            count++;
        }
    }

    output_buffer[count] = '\0';
    strcpy(output, output_buffer);
}

// Function to run-length decode a string
void decode(char* compressed, char* output) {
    int length = strlen(compressed);
    int count = 0;
    char* output_buffer = (char*)malloc(length + 1);
    output_buffer[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (compressed[i] == '\0') {
            break;
        } else if (compressed[i] == ',') {
            count++;
            output_buffer[count] = compressed[i + 1];
            output_buffer[count + 1] = compressed[i + 2];
            count += 2;
        }
    }

    output_buffer[count] = '\0';
    strcpy(output, output_buffer);
}

int main() {
    char input[100];
    char compressed[100];
    char output[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    compress(input, compressed);
    printf("Compressed string: %s\n", compressed);

    decompress(compressed, output);
    printf("Decompressed string: %s\n", output);

    encode(input, compressed);
    printf("Encoded string: %s\n", compressed);

    decode(compressed, output);
    printf("Decoded string: %s\n", output);

    return 0;
}