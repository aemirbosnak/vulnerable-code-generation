//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*1024) //1GB
#define BLOCK_SIZE 512

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    int bytes_read, bytes_written;

    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, output_file);
        if (bytes_written!= bytes_read) {
            printf("Error: could not write data to output file.\n");
            exit(1);
        }
    }

    if (ferror(input_file)) {
        printf("Error: could not read data from input file.\n");
        exit(1);
    }

    if (ferror(output_file)) {
        printf("Error: could not write data to output file.\n");
        exit(1);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}