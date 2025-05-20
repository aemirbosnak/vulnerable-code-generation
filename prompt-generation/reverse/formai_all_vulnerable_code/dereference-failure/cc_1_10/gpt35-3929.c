//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    FILE* input = fopen(input_file, "rb");
    if (!input) {
        printf("Unable to open input file: %s\n", input_file);
        return 1;
    }

    FILE* output = fopen(output_file, "wb");
    if (!output) {
        printf("Unable to open output file: %s\n", output_file);
        return 1;
    }

    // calculate the size of the input file
    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    // allocate a buffer to read the file into
    char* buffer = (char*) malloc(file_size);
    if (!buffer) {
        printf("Unable to allocate memory for input buffer\n");
        return 1;
    }

    // read the input file into the buffer
    fread(buffer, file_size, 1, input);

    // encrypt the buffer (simple XOR encryption)
    char encryption_key = 0x5A;
    for (int i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ encryption_key;
    }

    // write the encrypted buffer to the output file
    fwrite(buffer, file_size, 1, output);

    // clean up
    free(buffer);
    fclose(input);
    fclose(output);

    return 0;
}