//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    char source[256];
    char destination[256];
} SyncPaths;

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", program_name);
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void sync_file(const char *source_file, const char *dest_file) {
    FILE *source = fopen(source_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    
    if (!source) {
        perror("Error opening source file");
        return;
    }
    if (!dest) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
}

void sync_directory(const SyncPaths *paths) {
    DIR *dir = opendir(paths->source);
    struct dirent *entry;
    
    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char source_path[512];
        char dest_path[512];
        snprintf(source_path, sizeof(source_path), "%s/%s", paths->source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", paths->destination, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Create destination directory if it doesn't exist
            if (mkdir(dest_path, 0755) == -1 && errno != EEXIST) {
                perror("Error creating destination directory");
                continue;
            }
            SyncPaths new_paths = { .source = "", .destination = "" };
            strcpy(new_paths.source, source_path);
            strcpy(new_paths.destination, dest_path);
            sync_directory(&new_paths); // Recursively sync subdirectory
        } else if (entry->d_type == DT_REG) {
            struct stat source_stat, dest_stat;
            stat(source_path, &source_stat);
            if (stat(dest_path, &dest_stat) == -1 || source_stat.st_mtime > dest_stat.st_mtime) {
                printf("Syncing file: %s to %s\n", source_path, dest_path);
                sync_file(source_path, dest_path);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    SyncPaths paths;
    if (!is_directory(argv[1])) {
        fprintf(stderr, "Error: Source path is not a directory\n");
        return EXIT_FAILURE;
    }
    if (!is_directory(argv[2])) {
        fprintf(stderr, "Destination path is not a directory, creating it.\n");
        if (mkdir(argv[2], 0755) == -1 && errno != EEXIST) {
            perror("Error creating destination directory");
            return EXIT_FAILURE;
        }
    }

    strcpy(paths.source, argv[1]);
    strcpy(paths.destination, argv[2]);

    printf("Starting synchronization from %s to %s\n", paths.source, paths.destination);
    sync_directory(&paths);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}