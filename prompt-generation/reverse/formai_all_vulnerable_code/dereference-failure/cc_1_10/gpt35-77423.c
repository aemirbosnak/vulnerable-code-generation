//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>              // for standard input/output operations
#include <stdlib.h>             // for malloc() and free() functions
#include <string.h>             // for memcpy() function

#define MAX_FILE_SIZE 10485760  // maximum file size set to 10 MB

void read_file(char *input_file_name, char *data_buffer);

void write_file(char *output_file_name, char *data_buffer_to_write);

int main(int argc, char *argv[]) {
    char *data_buffer = NULL;
    char *output_file_name = NULL;

    if (argc == 3) {
        // allocate memory for data buffer
        data_buffer = (char *) malloc(MAX_FILE_SIZE * sizeof(char));

        // read input file
        read_file(argv[1], data_buffer);

        // write output file
        output_file_name = strdup(argv[2]);
        write_file(output_file_name, data_buffer);

        // free memory used by buffer
        free(data_buffer);
        data_buffer = NULL;

        printf("File recovery successful!\n");
    } else {
        printf("Error: Invalid input. Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
    }

    return 0;
}

void read_file(char *input_file_name, char *data_buffer) {
    FILE *input_file = NULL;
    size_t file_size = 0;

    // Open file for reading in binary mode
    input_file = fopen(input_file_name, "rb");

    // Check if file exists and can be opened
    if (input_file == NULL) {
        printf("Error: Cannot open file %s\n", input_file_name);
        exit(1);
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Check if file size is within limits
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: Input file size too large. Maximum size allowed is %d bytes\n", MAX_FILE_SIZE);
        fclose(input_file);
        exit(1);
    }

    // Read file content into data buffer
    fread(data_buffer, file_size, 1, input_file);

    // Close input file
    fclose(input_file);
}

void write_file(char *output_file_name, char *data_buffer_to_write) {
    FILE *output_file = NULL;

    // Open file for writing in binary mode
    output_file = fopen(output_file_name, "wb");

    // Check if file exists and can be opened
    if (output_file == NULL) {
        printf("Error: Cannot open file %s for writing\n", output_file_name);
        exit(1);
    }

    // Write data buffer to output file
    fwrite(data_buffer_to_write, strlen(data_buffer_to_write), 1, output_file);

    // Close output file
    fclose(output_file);
}