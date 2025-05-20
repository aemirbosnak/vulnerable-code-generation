//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10

// Structure to store file metadata
typedef struct {
    char *filename;
    time_t mtime;
    time_t ctime;
    off_t size;
    int nlink;
    uid_t uid;
    gid_t gid;
    mode_t mode;
} FileMetadata;

// Function to extract metadata from a file
FileMetadata *extract_metadata(const char *filename) {
    // Allocate memory for the metadata struct
    FileMetadata *metadata = malloc(sizeof(FileMetadata));
    if (!metadata) {
        perror("malloc");
        return NULL;
    }
    
    // Get the file size
    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        perror("stat");
        free(metadata);
        return NULL;
    }
    metadata->size = statbuf.st_size;
    
    // Get the file modification time
    metadata->mtime = statbuf.st_mtime;
    
    // Get the file creation time
    metadata->ctime = statbuf.st_ctime;
    
    // Get the number of links to the file
    metadata->nlink = statbuf.st_nlink;
    
    // Get the file owner's user ID
    metadata->uid = statbuf.st_uid;
    
    // Get the file owner's group ID
    metadata->gid = statbuf.st_gid;
    
    // Get the file permissions
    metadata->mode = statbuf.st_mode;
    
    // Store the filename
    metadata->filename = strdup(filename);
    if (!metadata->filename) {
        perror("strdup");
        free(metadata);
        return NULL;
    }
    
    // Return the metadata struct
    return metadata;
}

// Function to print metadata
void print_metadata(FileMetadata *metadata) {
    // Print the filename
    printf("Filename: %s\n", metadata->filename);
    
    // Print the file size
    printf("Size: %ld bytes\n", metadata->size);
    
    // Print the file modification time
    printf("Modification time: %s", ctime(&metadata->mtime));
    
    // Print the file creation time
    printf("Creation time: %s", ctime(&metadata->ctime));
    
    // Print the number of links to the file
    printf("Number of links: %d\n", metadata->nlink);
    
    // Print the file owner's user ID
    printf("Owner's user ID: %d\n", metadata->uid);
    
    // Print the file owner's group ID
    printf("Owner's group ID: %d\n", metadata->gid);
    
    // Print the file permissions
    printf("Permissions: %o\n", metadata->mode);
}

// Function to free metadata
void free_metadata(FileMetadata *metadata) {
    if (!metadata) {
        return;
    }
    
    // Free the filename
    free(metadata->filename);
    
    // Free the metadata struct
    free(metadata);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Extract metadata from the file
    FileMetadata *metadata = extract_metadata(argv[1]);
    if (!metadata) {
        perror("extract_metadata");
        return EXIT_FAILURE;
    }

    // Print metadata
    print_metadata(metadata);
    
    // Free metadata
    free_metadata(metadata);

    return EXIT_SUCCESS;
}