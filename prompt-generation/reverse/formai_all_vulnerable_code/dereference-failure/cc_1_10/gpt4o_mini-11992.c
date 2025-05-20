//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 256
#define MAX_METADATA_LEN 512

// Structure representing the metadata of a file
typedef struct FileMetadata {
    char name[MAX_PATH_LEN];
    char type[MAX_PATH_LEN];
    long size; 
} FileMetadata;

// Function to gather metadata of a given file
void gather_metadata(const char *file_path, FileMetadata *metadata) {
    FILE *file = fopen(file_path, "rb");
    
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    metadata->size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Store the name and type (file extension)
    strncpy(metadata->name, file_path, MAX_PATH_LEN);
    char *ext = strrchr(file_path, '.');
    if (ext != NULL) {
        strncpy(metadata->type, ext + 1, MAX_PATH_LEN);
    } else {
        strncpy(metadata->type, "unknown", MAX_PATH_LEN);
    }

    fclose(file);
}

// Function to display file metadata
void display_metadata(FileMetadata metadata) {
    printf("Filename: %s\n", metadata.name);
    printf("File Type: %s\n", metadata.type);
    printf("File Size: %ld bytes\n", metadata.size);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char *path = "./";
    
    // Scavenge the current directory for files
    dir = opendir(path);
    if (dir == NULL) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    printf("=== Post-Apocalyptic File Metadata Extractor ===\n");
    printf("Scanning for survivors... err, files...\n\n");

    while ((entry = readdir(dir)) != NULL) {
        // Ignore directories and only handle files
        if (entry->d_type == DT_REG) {
            char full_path[MAX_PATH_LEN];
            snprintf(full_path, MAX_PATH_LEN, "%s%s", path, entry->d_name);
            
            printf("Found: %s\n", entry->d_name);
            FileMetadata metadata;
            gather_metadata(full_path, &metadata);
            display_metadata(metadata);
            printf("\n");
        }
    }

    closedir(dir);
    printf("=== Scan Complete ===\n");

    // Additional scavenging for metadata entries stored in a file
    FILE *meta_file = fopen("stored_metadata.txt", "a");
    if (meta_file == NULL) {
        perror("Failed to open metadata file");
        return EXIT_FAILURE;
    }

    fprintf(meta_file, "=== Scanned Metadata ===\n");
    rewind(dir);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char full_path[MAX_PATH_LEN];
            snprintf(full_path, MAX_PATH_LEN, "%s%s", path, entry->d_name);
            
            FileMetadata metadata;
            gather_metadata(full_path, &metadata);
            fprintf(meta_file, "Filename: %s, Type: %s, Size: %ld bytes\n", 
                    metadata.name, metadata.type, metadata.size);
        }
    }

    fclose(meta_file);
    closedir(dir);
    
    printf("Metadata stored in 'stored_metadata.txt'.\n");
    return EXIT_SUCCESS;
}