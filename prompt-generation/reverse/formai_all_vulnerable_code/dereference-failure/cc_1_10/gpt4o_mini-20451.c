//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Maximum length for file paths and metadata
#define MAX_PATH 1024
#define MAX_TYPE 32
#define MAX_SIZE 32

// Structure to store file metadata
typedef struct {
    char path[MAX_PATH];
    char type[MAX_TYPE];
    char size[MAX_SIZE];
} FileMetadata;

// Function prototypes
void extract_metadata(const char *directory);
void print_metadata(const FileMetadata *metadata, size_t count);
void get_file_ext(const char *filename, char *ext);
void calculate_file_size(const char *filepath, char *size_buffer);

// Main entry point of the program
int main(int argc, char *argv[]) {
    // Handle no input directory
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract metadata from the specified directory
    extract_metadata(argv[1]);

    return EXIT_SUCCESS;
}

// Function to extract metadata from a directory
void extract_metadata(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    size_t metadata_count = 0;
    FileMetadata metadata_list[1024]; // Limit to 1024 files for simplicity

    // Open the specified directory
    if ((dir = opendir(directory)) == NULL) {
        fprintf(stderr, "Error: Unable to open directory: %s\n", directory);
        return;
    }

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full file path
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

        // Populate the FileMetadata structure
        strncpy(metadata_list[metadata_count].path, full_path, MAX_PATH - 1);
        get_file_ext(entry->d_name, metadata_list[metadata_count].type);
        calculate_file_size(full_path, metadata_list[metadata_count].size);
        
        // Increment the count of valid metadata
        metadata_count++;
        if (metadata_count >= sizeof(metadata_list) / sizeof(metadata_list[0])) {
            fprintf(stderr, "Warning: Reached metadata limit of 1024 files. Stopping...\n");
            break;
        }
    }

    // Close the directory
    closedir(dir);

    // Print the collected metadata
    print_metadata(metadata_list, metadata_count);
}

// Function to print the metadata
void print_metadata(const FileMetadata *metadata, size_t count) {
    printf("Extracted Metadata:\n");
    for (size_t i = 0; i < count; i++) {
        printf("File Path: %s\n", metadata[i].path);
        printf("File Type: %s\n", metadata[i].type);
        printf("File Size: %s\n", metadata[i].size);
        printf("--------------------------\n");
    }
}

// Function to retrieve the file extension
void get_file_ext(const char *filename, char *ext) {
    const char *dot = strrchr(filename, '.');
    if (dot && dot != filename) {
        strncpy(ext, dot + 1, MAX_TYPE - 1);
    } else {
        strcpy(ext, "unknown");
    }
}

// Function to calculate the file size
void calculate_file_size(const char *filepath, char *size_buffer) {
    FILE *file = fopen(filepath, "rb");
    if (file) {
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fclose(file);
        
        if (size < 1024) {
            snprintf(size_buffer, MAX_SIZE, "%ld bytes", size);
        } else if (size < 1024 * 1024) {
            snprintf(size_buffer, MAX_SIZE, "%.2f KB", size / 1024.0);
        } else {
            snprintf(size_buffer, MAX_SIZE, "%.2f MB", size / (1024.0 * 1024.0));
        }
    } else {
        strcpy(size_buffer, "Error retrieving size");
    }
}