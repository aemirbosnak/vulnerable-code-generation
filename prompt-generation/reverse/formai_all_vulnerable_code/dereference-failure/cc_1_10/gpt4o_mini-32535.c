//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 4096

typedef struct {
    char *source;
    char *destination;
} FilePaths;

void allocate_file_paths(FilePaths *filePaths) {
    filePaths->source = (char *)malloc(MAX_PATH_LENGTH * sizeof(char));
    filePaths->destination = (char *)malloc(MAX_PATH_LENGTH * sizeof(char));
    if (!filePaths->source || !filePaths->destination) {
        perror("Error allocating memory for file paths");
        exit(EXIT_FAILURE);
    }
}

void free_file_paths(FilePaths *filePaths) {
    free(filePaths->source);
    free(filePaths->destination);
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    if (!src || !dest) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

int are_files_identical(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    if (!f1 || !f2) {
        perror("Error opening files for comparison");
        exit(EXIT_FAILURE);
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t bytes1, bytes2;

    do {
        bytes1 = fread(buffer1, 1, BUFFER_SIZE, f1);
        bytes2 = fread(buffer2, 1, BUFFER_SIZE, f2);

        if (bytes1 != bytes2 || memcmp(buffer1, buffer2, bytes1) != 0) {
            fclose(f1);
            fclose(f2);
            return 0; // Files are not identical
        }
    } while (bytes1 > 0);

    fclose(f1);
    fclose(f2);
    return 1; // Files are identical
}

void synchronize_files(FilePaths *filePaths) {
    if (are_files_identical(filePaths->source, filePaths->destination)) {
        printf("Files are identical: %s and %s\n", filePaths->source, filePaths->destination);
    } else {
        printf("Files differ! Synchronizing: %s -> %s\n", filePaths->source, filePaths->destination);
        copy_file(filePaths->source, filePaths->destination);
        printf("Synchronization completed: %s -> %s\n", filePaths->source, filePaths->destination);
    }
}

void synchronize_directory(const char *source_dir, const char *destination_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    FilePaths filePaths;
    allocate_file_paths(&filePaths);
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(filePaths.source, MAX_PATH_LENGTH, "%s/%s", source_dir, entry->d_name);
            snprintf(filePaths.destination, MAX_PATH_LENGTH, "%s/%s", destination_dir, entry->d_name);
            synchronize_files(&filePaths);
        }
    }

    closedir(dir);
    free_file_paths(&filePaths);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];

    synchronize_directory(source_dir, destination_dir);

    return EXIT_SUCCESS;
}