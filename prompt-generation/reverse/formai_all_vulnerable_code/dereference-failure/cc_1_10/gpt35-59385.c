//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to represent a file
typedef struct File {
    char* name;
    int size;
    char* content;
} File;

// Function to read a file into memory
void readFile(const char* filename, char** content, int* size) {
    // Open the file for reading
    FILE* file = fopen(filename, "rb");

    // If the file could not be opened, exit with an error
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get the size of the file
    fseek(file, 0L, SEEK_END);
    *size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Allocate memory for the file content
    *content = (char*)malloc(*size * sizeof(char));

    // If memory allocation failed, exit with an error
    if (!*content) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Read the file into memory
    fread(*content, sizeof(char), *size, file);

    // Close the file
    fclose(file);
}

// Function to recover a file from memory
File* recoverFile(char* data, int size) {
    // Allocate memory for the file struct
    File* file = (File*)malloc(sizeof(File));

    // If memory allocation failed, exit with an error
    if (!file) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Find the position of the file name in the data
    int name_pos = -1;
    for (int i = 0; i < size - 1; i++) {
        if (data[i] == '/' && data[i + 1] != '/') {
            name_pos = i + 1;
            break;
        }
    }

    // If the file name was not found, exit with an error
    if (name_pos == -1) {
        fprintf(stderr, "Error: File name not found in data\n");
        exit(EXIT_FAILURE);
    }

    // Find the position of the file size in the data
    int size_pos = -1;
    for (int i = name_pos; i < size - 1; i++) {
        if (data[i] == '/' && data[i + 1] != '/') {
            size_pos = i + 1;
            break;
        }
    }

    // If the file size was not found, exit with an error
    if (size_pos == -1) {
        fprintf(stderr, "Error: File size not found in data\n");
        exit(EXIT_FAILURE);
    }

    // Read the file name from the data
    int name_len = size_pos - name_pos - 1;
    file->name = (char*)malloc(name_len * sizeof(char));
    memcpy(file->name, data + name_pos, name_len);
    file->name[name_len] = '\0';

    // Read the file size from the data
    int size_len = size - size_pos - 1;
    char* size_str = (char*)malloc(size_len * sizeof(char));
    memcpy(size_str, data + size_pos, size_len);
    size_str[size_len] = '\0';
    file->size = atoi(size_str);
    free(size_str);

    // Allocate memory for the file content
    file->content = (char*)malloc(file->size * sizeof(char));

    // If memory allocation failed, exit with an error
    if (!file->content) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Read the file content from the data
    memcpy(file->content, data + size, file->size);

    return file;
}

int main(int argc, char** argv) {
    // Check the command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read the data file into memory
    char* data;
    int size;
    readFile(argv[1], &data, &size);

    // Recover the file from the data
    File* file = recoverFile(data, size);

    // Write the recovered file to the output file
    FILE* output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    fwrite(file->content, sizeof(char), file->size, output_file);

    // Close the output file
    fclose(output_file);

    // Free the memory
    free(data);
    free(file->name);
    free(file->content);
    free(file);

    return 0;
}