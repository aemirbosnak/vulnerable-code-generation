//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Constants for the recovery tool
#define BLOCK_SIZE 512  // Size of each block to read from the device
#define MAX_FILE_NAME 100  // Maximum length for recovered file name
#define MAX_PATH 1024  // Maximum path length

// Function prototypes
void recover_files(const char *device_path, const char *output_dir);
int write_to_file(const char *filename, unsigned char *buffer, size_t size);
int is_valid_file_signature(unsigned char *buffer);

// Main function
int main(int argc, char *argv[]) {
    // Validate input
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <device_path> <output_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Call the recovery function
    recover_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

// Function to recover files from the specified device
void recover_files(const char *device_path, const char *output_dir) {
    FILE *device = fopen(device_path, "rb");
    if (!device) {
        fprintf(stderr, "Error opening device: %s\n", strerror(errno));
        return;
    }

    unsigned char buffer[BLOCK_SIZE];
    size_t bytes_read;
    int file_count = 0;
    char output_filename[MAX_FILE_NAME];

    // Loop through the device blocks
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, device)) > 0) {
        // Check for valid file signatures, you can extend this method.
        if (is_valid_file_signature(buffer)) {
            snprintf(output_filename, sizeof(output_filename), "%s/recovered_file_%d.bin", output_dir, file_count);
            if (write_to_file(output_filename, buffer, bytes_read) == -1) {
                fprintf(stderr, "Error writing to file: %s\n", output_filename);
            }
            file_count++;
        }
    }

    fclose(device);
    fprintf(stdout, "Total recovered files: %d\n", file_count);
}

// Function to write data to a file
int write_to_file(const char *filename, unsigned char *buffer, size_t size) {
    FILE *output_file = fopen(filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Error creating file: %s\n", strerror(errno));
        return -1;
    }

    size_t written = fwrite(buffer, 1, size, output_file);
    fclose(output_file);

    return (written == size) ? 0 : -1;
}

// Check for certain valid file signatures (this example checks for JPEG and PNG headers)
int is_valid_file_signature(unsigned char *buffer) {
    // Check for JPEG header (0xFF D8 FF)
    if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF) {
        return 1; // Valid JPEG file
    }
    // Check for PNG header (89 50 4E 47 0D 0A 1A 0A)
    if (buffer[0] == 0x89 && buffer[1] == 0x50 && buffer[2] == 0x4E && buffer[3] == 0x47 &&
        buffer[4] == 0x0D && buffer[5] == 0x0A && buffer[6] == 0x1A && buffer[7] == 0x0A) {
        return 1; // Valid PNG file
    }
    return 0; // Not a valid file
}