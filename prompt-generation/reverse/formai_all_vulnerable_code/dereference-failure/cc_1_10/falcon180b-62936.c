//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_data(FILE *file, void *buffer, size_t size) {
    size_t bytes_read = fread(buffer, 1, size, file);
    if (bytes_read!= size) {
        fprintf(stderr, "Error: could not read data from file.\n");
        exit(1);
    }
}

void write_data(FILE *file, const void *buffer, size_t size) {
    size_t bytes_written = fwrite(buffer, 1, size, file);
    if (bytes_written!= size) {
        fprintf(stderr, "Error: could not write data to file.\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        write_data(output_file, buffer, bytes_read);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery completed successfully!\n");
    return 0;
}