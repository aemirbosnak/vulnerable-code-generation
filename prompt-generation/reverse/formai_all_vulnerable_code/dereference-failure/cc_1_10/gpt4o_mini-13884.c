//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Structure to hold the metadata of a file
typedef struct FileMetadata {
    char name[256];
    char path[512];
    size_t size;
    time_t created;
    time_t modified;
} FileMetadata;

// Function to get the file size
size_t getFileSize(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return 0; // File not found or error
}

// Function to get the modification time
time_t getLastModified(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_mtime;
    }
    return -1; // Error
}

// Function to get the creation time
time_t getCreationTime(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_ctime;
    }
    return -1; // Error
}

// Function to extract metadata from a file
FileMetadata extractMetadata(const char *filepath) {
    FileMetadata metadata;
    
    strcpy(metadata.path, filepath);
    strcpy(metadata.name, strrchr(filepath, '/') ? strrchr(filepath, '/') + 1 : filepath);
    metadata.size = getFileSize(filepath);
    metadata.modified = getLastModified(filepath);
    metadata.created = getCreationTime(filepath);
    
    return metadata;
}

// Function to print FileMetadata
void printMetadata(const FileMetadata *metadata) {
    printf("File Name: %s\n", metadata->name);
    printf("File Path: %s\n", metadata->path);
    printf("File Size: %zu bytes\n", metadata->size);
    printf("Creation Time: %s", ctime(&metadata->created));
    printf("Modified Time: %s", ctime(&metadata->modified));
}

// Function to recursively scan a directory and extract metadata from files
void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    DIR *d = opendir(dirPath);
    
    if (!d) {
        fprintf(stderr, "Could not open directory: %s\n", dirPath);
        return;
    }
    
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[512];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            
            if (entry->d_type == DT_DIR) {
                scanDirectory(fullPath); // Recur into subdirectory
            } else {
                FileMetadata metadata = extractMetadata(fullPath);
                printMetadata(&metadata);
            }
        }
    }
    
    closedir(d);
}

// Main function to accept directory from user and initiate scanning
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scanDirectory(argv[1]);
    
    return EXIT_SUCCESS;
}