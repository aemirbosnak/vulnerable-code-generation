//FormAI DATASET v1.0 Category: Image compression ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 // 1MB

int main() {
    char input_file[256], output_file[256];

    printf("Enter input file name (including extension): ");
    scanf("%s", input_file);

    printf("Enter output file name (including extension): ");
    scanf("%s", output_file);

    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");

    if (in_file == NULL) {
        printf("Could not open input file.\n");
        exit(1);
    }

    if (out_file == NULL) {
        printf("Could not open output file.\n");
        exit(1);
    }

    // Read the entire file into a buffer
    char *buffer = (char *)malloc(MAX_FILE_SIZE);
    size_t length = fread(buffer, 1, MAX_FILE_SIZE, in_file);

    // Compress the buffer
    char *compressed_buffer = (char *)malloc(length / 2);
    int i, j = 0;
    for (i = 0; i < length; i += 2, j++) {
        compressed_buffer[j] = (buffer[i] << 4) | buffer[i+1]; // Combine two bytes into one
    }

    // Write the compressed buffer to the output file
    fwrite(compressed_buffer, 1, j, out_file);

    printf("Compression complete.\n");

    fclose(in_file);
    fclose(out_file);
    free(buffer);
    free(compressed_buffer);

    return 0;
}