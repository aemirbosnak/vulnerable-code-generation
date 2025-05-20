//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 260
#define MAX_DESCRIPTION_LENGTH 512

typedef struct Metadata {
    char filename[MAX_PATH_LENGTH];
    char filetype[MAX_PATH_LENGTH];
    long filesize;
    char description[MAX_DESCRIPTION_LENGTH];
} Metadata;

// Function to get file type from the file extension
const char* get_file_type(const char* filename) {
    const char* dot = strrchr(filename, '.');
    if (!dot || dot == filename) return "Unknown";
    
    if (strcmp(dot, ".c") == 0) return "C Source File";
    if (strcmp(dot, ".h") == 0) return "C Header File";
    if (strcmp(dot, ".txt") == 0) return "Text File";
    if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0) return "JPEG Image";
    if (strcmp(dot, ".png") == 0) return "PNG Image";
    if (strcmp(dot, ".mp3") == 0) return "MP3 Audio";
    
    return "Other File Type";
}

// Function to get file size
long get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1; // indicates error
}

// Function to create a metadata entry
Metadata create_metadata_entry(const char* filename) {
    Metadata metadata;

    strcpy(metadata.filename, filename);
    strcpy(metadata.filetype, get_file_type(filename));
    metadata.filesize = get_file_size(filename);
    snprintf(metadata.description, MAX_DESCRIPTION_LENGTH, "This is a %s with size %ld bytes.", 
             metadata.filetype, metadata.filesize);

    return metadata;
}

// Function to print metadata entry
void print_metadata(const Metadata* metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File Type: %s\n", metadata->filetype);
    printf("File Size: %ld bytes\n", metadata->filesize);
    printf("Description: %s\n", metadata->description);
    printf("-----------------------------\n");
}

// Function to extract metadata from all files in a directory
void extract_metadata_from_directory(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char full_path[MAX_PATH_LENGTH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            Metadata metadata = create_metadata_entry(full_path);
            print_metadata(&metadata);
        }
    }
    
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* directory_path = argv[1];
    extract_metadata_from_directory(directory_path);

    return EXIT_SUCCESS;
}