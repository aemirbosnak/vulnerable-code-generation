//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // check if file name argument was provided
    if (argc < 2) {
        printf("Usage: %s <file_name> [output_file_name]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file_name = argv[1];
    char *output_file_name = (argc > 2) ? argv[2] : "recovered_data.txt";
    FILE *file, *output_file;

    // open the file for reading
    file = fopen(file_name, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", file_name);
        return EXIT_FAILURE;
    }

    // get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // allocate a buffer for file data
    char *data_buffer = (char*) malloc(file_size * sizeof(char));
    if (!data_buffer) {
        printf("Error: Could not allocate memory for file data\n");
        return EXIT_FAILURE;
    }

    // read file contents into buffer
    fread(data_buffer, sizeof(char), file_size, file);

    // check for corrupted data
    int num_corrupted_bytes = 0;
    for (int i = 0; i < file_size; i++) {
        if (data_buffer[i] == '\0' || data_buffer[i] == '\r') {
            num_corrupted_bytes++;
            data_buffer[i] = ' ';
        }
    }
    if (num_corrupted_bytes > 0) {
        printf("Warning: %d corrupted bytes were found and replaced with spaces\n", num_corrupted_bytes);
    }

    // create output file and write recovered data to it
    output_file = fopen(output_file_name, "w");
    fwrite(data_buffer, sizeof(char), file_size, output_file);

    // close files and free memory
    fclose(file);
    fclose(output_file);
    free(data_buffer);

    printf("Data recovery successful! Recovered data saved to %s\n", output_file_name);

    return EXIT_SUCCESS;
}