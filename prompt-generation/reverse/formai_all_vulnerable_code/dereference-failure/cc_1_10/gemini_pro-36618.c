//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold file data
typedef struct {
    char *name;
    char *data;
    int size;
} File;

// Function to read a file
File *read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file data
    File *file = malloc(sizeof(File));
    file->name = malloc(strlen(filename) + 1);
    file->data = malloc(size);

    // Read file data
    strcpy(file->name, filename);
    fread(file->data, size, 1, fp);

    // Close file
    fclose(fp);

    return file;
}

// Function to write a file
int write_file(const File *file) {
    FILE *fp = fopen(file->name, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write file data
    fwrite(file->data, file->size, 1, fp);

    // Close file
    fclose(fp);

    return 0;
}

// Function to recover a file from a fragment
File *recover_file(const char *fragment, int fragment_size) {
    // Check if fragment size is valid
    if (fragment_size <= 0) {
        fprintf(stderr, "Invalid fragment size\n");
        return NULL;
    }

    // Allocate memory for file data
    File *file = malloc(sizeof(File));
    file->name = malloc(strlen(fragment) + 1);
    file->data = malloc(fragment_size);

    // Copy fragment data
    strcpy(file->name, fragment);
    memcpy(file->data, fragment, fragment_size);
    file->size = fragment_size;

    return file;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <fragment>\n", argv[0]);
        return -1;
    }

    // Read source file
    File *source_file = read_file(argv[1]);
    if (source_file == NULL) {
        return -1;
    }

    // Recover file from fragment
    File *recovered_file = recover_file(argv[2], source_file->size);
    if (recovered_file == NULL) {
        return -1;
    }

    // Write recovered file
    if (write_file(recovered_file) != 0) {
        return -1;
    }

    // Free memory
    free(source_file->name);
    free(source_file->data);
    free(source_file);
    free(recovered_file->name);
    free(recovered_file->data);
    free(recovered_file);

    return 0;
}