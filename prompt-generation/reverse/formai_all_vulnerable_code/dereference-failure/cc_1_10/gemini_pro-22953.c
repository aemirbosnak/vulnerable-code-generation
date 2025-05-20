//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file metadata
typedef struct file_metadata {
    char filename[256];
    unsigned int size;
    unsigned int offset;
} file_metadata;

// Structure to store the recovered files
typedef struct recovered_file {
    char filename[256];
    char *data;
    unsigned int size;
} recovered_file;

// Function to read the file system from the disk image
int read_file_system(const char *disk_image_path, file_metadata **file_metadata_array, unsigned int *num_files) {
    // Open the disk image file
    FILE *disk_image_file = fopen(disk_image_path, "rb");
    if (disk_image_file == NULL) {
        return -1;
    }

    // Read the file system metadata
    unsigned int num_entries;
    fread(&num_entries, sizeof(unsigned int), 1, disk_image_file);

    // Allocate memory for the file metadata array
    *file_metadata_array = (file_metadata *)malloc(num_entries * sizeof(file_metadata));

    // Read the file metadata entries
    for (unsigned int i = 0; i < num_entries; i++) {
        fread((*file_metadata_array)[i].filename, sizeof(char), 256, disk_image_file);
        fread(&(*file_metadata_array)[i].size, sizeof(unsigned int), 1, disk_image_file);
        fread(&(*file_metadata_array)[i].offset, sizeof(unsigned int), 1, disk_image_file);
    }

    // Close the disk image file
    fclose(disk_image_file);

    // Set the number of files
    *num_files = num_entries;

    return 0;
}

// Function to recover the files from the disk image
int recover_files(const char *disk_image_path, const char *output_directory_path, file_metadata *file_metadata_array, unsigned int num_files) {
    // Create the output directory
    if (mkdir(output_directory_path, 0755) != 0) {
        return -1;
    }

    // Open the disk image file
    FILE *disk_image_file = fopen(disk_image_path, "rb");
    if (disk_image_file == NULL) {
        return -1;
    }

    // Recover each file
    for (unsigned int i = 0; i < num_files; i++) {
        // Allocate memory for the recovered file data
        char *data = (char *)malloc(file_metadata_array[i].size);

        // Seek to the file offset in the disk image
        fseek(disk_image_file, file_metadata_array[i].offset, SEEK_SET);

        // Read the file data
        fread(data, sizeof(char), file_metadata_array[i].size, disk_image_file);

        // Create the output file
        char output_file_path[512];
        sprintf(output_file_path, "%s/%s", output_directory_path, file_metadata_array[i].filename);
        FILE *output_file = fopen(output_file_path, "wb");
        if (output_file == NULL) {
            return -1;
        }

        // Write the recovered file data to the output file
        fwrite(data, sizeof(char), file_metadata_array[i].size, output_file);

        // Close the output file
        fclose(output_file);

        // Free the recovered file data
        free(data);
    }

    // Close the disk image file
    fclose(disk_image_file);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check for the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <disk_image_path> <output_directory_path> <recovery_mode>\n", argv[0]);
        return -1;
    }

    // Read the file system from the disk image
    file_metadata *file_metadata_array;
    unsigned int num_files;
    if (read_file_system(argv[1], &file_metadata_array, &num_files) != 0) {
        printf("Error reading file system from disk image.\n");
        return -1;
    }

    // Recover the files from the disk image
    if (recover_files(argv[1], argv[2], file_metadata_array, num_files) != 0) {
        printf("Error recovering files from disk image.\n");
        return -1;
    }

    // Free the file metadata array
    free(file_metadata_array);

    return 0;
}