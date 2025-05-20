//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[256], output_filename[256];
    char buffer[BUFFER_SIZE];
    int file_size = 0, bytes_read = 0, bytes_written = 0;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    file_size = filesize(input_file);
    if (file_size == -1) {
        printf("Error: Could not determine file size.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    printf("Recovering data from %s...\n", input_filename);
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, output_file)!= bytes_read) {
            printf("Error: Failed to write to output file.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
        bytes_written += bytes_read;
        printf("\rRecovered %d bytes...", bytes_written);
    }

    printf("\nData recovery complete.\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
}

int filesize(FILE *file) {
    int size = 0;
    if (fseek(file, 0, SEEK_END)!= 0) {
        return -1;
    }
    size = ftell(file);
    if (size == -1) {
        return -1;
    }
    rewind(file);
    return size;
}