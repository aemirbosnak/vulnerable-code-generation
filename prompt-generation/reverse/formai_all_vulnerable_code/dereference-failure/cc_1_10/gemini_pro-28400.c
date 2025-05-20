//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Data recovery tool to recover lost files from a corrupted disk.

// Structure to store file information.
typedef struct {
    char *name;
    uint64_t size;
    uint64_t offset;
} file_info;

// Function to read a file from a disk.
file_info *read_file(FILE *disk, uint64_t offset) {
    // Allocate memory for file information.
    file_info *file = malloc(sizeof(file_info));

    // Read file name.
    char name[256];
    fread(name, 1, 256, disk);

    // Read file size.
    uint64_t size;
    fread(&size, sizeof(uint64_t), 1, disk);

    // Set file information.
    file->name = strdup(name);
    file->size = size;
    file->offset = offset;

    return file;
}

// Function to recover files from a disk.
void recover_files(FILE *disk) {
    // Read the first file.
    file_info *file = read_file(disk, 0);

    // While there are more files to read.
    while (file != NULL) {
        // Open a file for writing.
        FILE *output = fopen(file->name, "wb");

        // Seek to the offset of the file.
        fseek(disk, file->offset, SEEK_SET);

        // Read the file contents.
        char buffer[4096];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, 4096, disk)) > 0) {
            // Write the file contents to the output file.
            fwrite(buffer, 1, bytes_read, output);
        }

        // Close the output file.
        fclose(output);

        // Read the next file.
        file = read_file(disk, file->offset + file->size);
    }
}

// Main function.
int main(int argc, char **argv) {
    // Check if the disk file is specified.
    if (argc != 2) {
        printf("Usage: %s <disk file>\n", argv[0]);
        return 1;
    }

    // Open the disk file.
    FILE *disk = fopen(argv[1], "rb");

    // If the disk file cannot be opened.
    if (disk == NULL) {
        printf("Error: Could not open disk file.\n");
        return 1;
    }

    // Recover files from the disk.
    recover_files(disk);

    // Close the disk file.
    fclose(disk);

    return 0;
}