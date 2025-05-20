//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file information
typedef struct file_info {
    char* name;
    long size;
    char* data;
} file_info;

// Function to read a file into a file_info struct
file_info* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file data
    char* data = malloc(size);
    if (!data) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    // Read the file data into memory
    size_t bytes_read = fread(data, 1, size, file);
    if (bytes_read != size) {
        perror("fread");
        free(data);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Create a file_info struct and return it
    file_info* info = malloc(sizeof(file_info));
    if (!info) {
        perror("malloc");
        free(data);
        return NULL;
    }

    info->name = strdup(filename);
    info->size = size;
    info->data = data;

    return info;
}

// Function to write a file from a file_info struct
int write_file(const file_info* info) {
    FILE* file = fopen(info->name, "wb");
    if (!file) {
        perror("fopen");
        return -1;
    }

    // Write the file data to the file
    size_t bytes_written = fwrite(info->data, 1, info->size, file);
    if (bytes_written != info->size) {
        perror("fwrite");
        fclose(file);
        return -1;
    }

    // Close the file
    fclose(file);

    return 0;
}

// Function to free the memory allocated for a file_info struct
void free_file_info(file_info* info) {
    free(info->name);
    free(info->data);
    free(info);
}

int main() {
    // Read the input file
    file_info* input_file = read_file("input.txt");
    if (!input_file) {
        return EXIT_FAILURE;
    }

    // Create a new file to store the recovered data
    file_info* recovered_file = malloc(sizeof(file_info));
    if (!recovered_file) {
        perror("malloc");
        free_file_info(input_file);
        return EXIT_FAILURE;
    }

    // Copy the file data to the recovered file
    recovered_file->name = strdup("recovered.txt");
    recovered_file->size = input_file->size;
    recovered_file->data = malloc(input_file->size);
    memcpy(recovered_file->data, input_file->data, input_file->size);

    // Write the recovered file to disk
    if (write_file(recovered_file) != 0) {
        perror("write_file");
        free_file_info(input_file);
        free_file_info(recovered_file);
        return EXIT_FAILURE;
    }

    // Free the memory allocated for the input and recovered files
    free_file_info(input_file);
    free_file_info(recovered_file);

    return EXIT_SUCCESS;
}