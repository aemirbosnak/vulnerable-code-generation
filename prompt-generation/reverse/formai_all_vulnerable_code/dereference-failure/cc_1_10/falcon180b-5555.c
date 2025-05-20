//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of input file

// Function to read input file and store it in a buffer
void read_input_file(char* filename, char** buffer) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    *buffer = malloc(filesize + 1);
    if (*buffer == NULL) {
        printf("Error: Could not allocate memory for buffer\n");
        exit(1);
    }

    fread(*buffer, filesize, 1, fp);
    fclose(fp);

    (*buffer)[filesize] = '\0'; // Add null terminator to end of buffer
}

// Function to write output file
void write_output_file(char* filename, char* buffer) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(buffer, strlen(buffer), 1, fp);
    fclose(fp);
}

// Function to compress input file using run-length encoding
void compress_file(char* input_filename, char* output_filename) {
    char* input_buffer = NULL;
    read_input_file(input_filename, &input_buffer);

    char* output_buffer = malloc(MAX_SIZE);
    char* output_ptr = output_buffer;

    int count = 1;
    char current_char = input_buffer[0];

    for (int i = 1; i < strlen(input_buffer); i++) {
        if (input_buffer[i] == current_char) {
            count++;
        } else {
            sprintf(output_ptr, "%d%c", count, current_char);
            output_ptr += strlen(output_ptr);
            count = 1;
            current_char = input_buffer[i];
        }
    }

    sprintf(output_ptr, "%d%c", count, current_char);
    output_ptr += strlen(output_ptr);

    write_output_file(output_filename, output_buffer);

    free(input_buffer);
    free(output_buffer);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    compress_file(argv[1], argv[2]);

    return 0;
}