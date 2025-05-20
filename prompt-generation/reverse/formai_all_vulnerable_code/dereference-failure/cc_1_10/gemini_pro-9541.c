//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

// Define the struct for storing file metadata
typedef struct FileMetadata {
    char *filename;
    char *filepath;
    uint64_t filesize;
    time_t last_modified;
    char *file_type;
    char *file_author;
    char *file_description;
} FileMetadata;

// Define the function to print the file metadata
void print_file_metadata(FileMetadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Filepath: %s\n", metadata->filepath);
    printf("Filesize: %llu bytes\n", metadata->filesize);
    printf("Last modified: %s", ctime(&metadata->last_modified));
    printf("File type: %s\n", metadata->file_type);
    if (metadata->file_author != NULL) {
        printf("File author: %s\n", metadata->file_author);
    }
    if (metadata->file_description != NULL) {
        printf("File description: %s\n", metadata->file_description);
    }
    printf("\n");
}

// Define the function to extract metadata from a file
FileMetadata *extract_file_metadata(char *filepath) {
    // Allocate memory for the metadata struct
    FileMetadata *metadata = malloc(sizeof(FileMetadata));

    // Get the filename and filepath
    metadata->filename = strrchr(filepath, '/') + 1;
    metadata->filepath = strdup(filepath);

    // Get the filesize
    struct stat statbuf;
    if (stat(filepath, &statbuf) == -1) {
        perror("stat");
        return NULL;
    }
    metadata->filesize = statbuf.st_size;

    // Get the last modified time
    metadata->last_modified = statbuf.st_mtime;

    // Get the file type
    if (S_ISREG(statbuf.st_mode)) {
        metadata->file_type = "Regular file";
    } else if (S_ISDIR(statbuf.st_mode)) {
        metadata->file_type = "Directory";
    } else if (S_ISLNK(statbuf.st_mode)) {
        metadata->file_type = "Symbolic link";
    } else if (S_ISFIFO(statbuf.st_mode)) {
        metadata->file_type = "FIFO";
    } else if (S_ISSOCK(statbuf.st_mode)) {
        metadata->file_type = "Socket";
    } else {
        metadata->file_type = "Unknown";
    }


    // Get the file author and description from the file comments.
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "/*", 2) == 0) {
            // This is the start of a comment block.
            char *author = strstr(line, "@author");
            if (author != NULL) {
                // Extract the author name.
                metadata->file_author = strdup(author + 8);
            }

            char *description = strstr(line, "@description");
            if (description != NULL) {
                // Extract the description.
                metadata->file_description = strdup(description + 13);
            }

            break;
        }
    }

    fclose(fp);

    // Return the metadata struct
    return metadata;
}

// Define the main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filepath>\n", argv[0]);
        return 1;
    }

    // Extract the file metadata
    FileMetadata *metadata = extract_file_metadata(argv[1]);
    if (metadata == NULL) {
        perror("extract_file_metadata");
        return 1;
    }

    // Print the file metadata
    print_file_metadata(metadata);

    // Free the memory allocated for the metadata struct
    free(metadata->filename);
    free(metadata->filepath);
    free(metadata->file_type);
    free(metadata->file_author);
    free(metadata->file_description);
    free(metadata);

    return 0;
}