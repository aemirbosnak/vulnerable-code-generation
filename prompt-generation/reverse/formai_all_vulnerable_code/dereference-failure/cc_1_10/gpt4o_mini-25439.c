//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_FILES 1000
#define BUFFER_SIZE 1024

// Structure to hold the metadata of a file
typedef struct {
    char filename[256];
    long size;
    char type[64];
} FileMetadata;

// Function to determine file type from extension
const char* get_file_type(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) return "Unknown";

    // Basic file types based on extension
    if (strcmp(dot, ".txt") == 0) return "Text File";
    if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0) return "JPEG Image";
    if (strcmp(dot, ".png") == 0) return "PNG Image";
    if (strcmp(dot, ".mp3") == 0) return "MP3 Audio";
    if (strcmp(dot, ".mp4") == 0) return "MP4 Video";
    if (strcmp(dot, ".bin") == 0) return "Binary File";
    
    return "Other";
}

// Function to extract metadata from files in a directory
int extract_metadata(const char *directory, FileMetadata *files, int *count) {
    DIR *dir;
    struct dirent *ent;
    char filepath[BUFFER_SIZE];

    dir = opendir(directory);
    if (!dir) {
        fprintf(stderr, "Error: Unable to open directory '%s'\n", directory);
        return -1;
    }

    *count = 0;
    while ((ent = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(filepath, sizeof(filepath), "%s/%s", directory, ent->d_name);
        
        // Get file metadata
        FILE *file = fopen(filepath, "rb");
        if (file) {
            fseek(file, 0, SEEK_END);
            long filesize = ftell(file);
            fclose(file);

            // Store metadata
            strcpy(files[*count].filename, ent->d_name);
            files[*count].size = filesize;
            strcpy(files[*count].type, get_file_type(ent->d_name));
            (*count)++;
        }
        
        // Limit the number of files processed
        if (*count >= MAX_FILES) {
            break;
        }
    }

    closedir(dir);
    return 0;
}

// Function to print the extracted metadata
void print_metadata(FileMetadata *files, int count) {
    printf("%-30s %-15s %-20s\n", "Filename", "Size (bytes)", "File Type");
    printf("%-30s %-15s %-20s\n", "--------", "-------------", "--------");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-15ld %-20s\n", files[i].filename, files[i].size, files[i].type);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileMetadata files[MAX_FILES];
    int count = 0;

    // Extract metadata from the specified directory
    if (extract_metadata(argv[1], files, &count) != 0) {
        return EXIT_FAILURE;
    }

    // Display the extracted metadata
    print_metadata(files, count);
    
    // Post-apocalyptic twist to the output
    printf("\n--- End of the World Metadata Extraction Complete ---\n");
    printf("Survivors will thank you for knowing what piece of tech still works.\n");

    return EXIT_SUCCESS;
}