//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file metadata
typedef struct {
    char filename[256];
    unsigned long long size;
    unsigned char checksum;
} FileMetadata;

// Structure to store the recovered file data
typedef struct {
    unsigned char *data;
    unsigned long long size;
} RecoveredFile;

// Function to read the file metadata from the disk
FileMetadata *read_file_metadata(const char *disk_image_path, unsigned long long offset) {
    // Allocate memory for the file metadata
    FileMetadata *metadata = malloc(sizeof(FileMetadata));

    // Open the disk image file
    FILE *disk_image_file = fopen(disk_image_path, "rb");
    if (disk_image_file == NULL) {
        perror("Error opening disk image file");
        free(metadata);
        return NULL;
    }

    // Seek to the file metadata offset
    if (fseek(disk_image_file, offset, SEEK_SET) != 0) {
        perror("Error seeking to file metadata offset");
        fclose(disk_image_file);
        free(metadata);
        return NULL;
    }

    // Read the file metadata
    if (fread(metadata, sizeof(FileMetadata), 1, disk_image_file) != 1) {
        perror("Error reading file metadata");
        fclose(disk_image_file);
        free(metadata);
        return NULL;
    }

    // Close the disk image file
    fclose(disk_image_file);

    return metadata;
}

// Function to read the file data from the disk
RecoveredFile *read_file_data(const char *disk_image_path, unsigned long long offset, unsigned long long size) {
    // Allocate memory for the recovered file
    RecoveredFile *recovered_file = malloc(sizeof(RecoveredFile));

    // Open the disk image file
    FILE *disk_image_file = fopen(disk_image_path, "rb");
    if (disk_image_file == NULL) {
        perror("Error opening disk image file");
        free(recovered_file);
        return NULL;
    }

    // Seek to the file data offset
    if (fseek(disk_image_file, offset, SEEK_SET) != 0) {
        perror("Error seeking to file data offset");
        fclose(disk_image_file);
        free(recovered_file);
        return NULL;
    }

    // Read the file data
    recovered_file->data = malloc(size);
    if (fread(recovered_file->data, size, 1, disk_image_file) != 1) {
        perror("Error reading file data");
        fclose(disk_image_file);
        free(recovered_file->data);
        free(recovered_file);
        return NULL;
    }

    // Set the size of the recovered file
    recovered_file->size = size;

    // Close the disk image file
    fclose(disk_image_file);

    return recovered_file;
}

// Function to write the recovered file to disk
int write_recovered_file(const char *output_file_path, RecoveredFile *recovered_file) {
    // Open the output file
    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return -1;
    }

    // Write the recovered file data to disk
    if (fwrite(recovered_file->data, recovered_file->size, 1, output_file) != 1) {
        perror("Error writing recovered file data to disk");
        fclose(output_file);
        return -1;
    }

    // Close the output file
    fclose(output_file);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <disk_image_path> <file_offset> <output_file_path>\n", argv[0]);
        return -1;
    }

    // Get the disk image path
    const char *disk_image_path = argv[1];

    // Get the file offset
    unsigned long long file_offset = strtoull(argv[2], NULL, 10);

    // Get the output file path
    const char *output_file_path = argv[3];

    // Read the file metadata
    FileMetadata *metadata = read_file_metadata(disk_image_path, file_offset);
    if (metadata == NULL) {
        return -1;
    }

    // Read the file data
    RecoveredFile *recovered_file = read_file_data(disk_image_path, file_offset + sizeof(FileMetadata), metadata->size);
    if (recovered_file == NULL) {
        free(metadata);
        return -1;
    }

    // Write the recovered file to disk
    if (write_recovered_file(output_file_path, recovered_file) != 0) {
        free(metadata);
        free(recovered_file->data);
        free(recovered_file);
        return -1;
    }

    // Free the allocated memory
    free(metadata);
    free(recovered_file->data);
    free(recovered_file);

    return 0;
}