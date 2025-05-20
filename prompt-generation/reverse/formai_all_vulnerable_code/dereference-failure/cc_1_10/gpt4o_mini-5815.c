//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    FILE *destination = fopen(dest, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (source == NULL || destination == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int compare_files(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) != 0 || stat(file2, &stat2) != 0) {
        return 0; // If either file does not exist
    }

    return stat1.st_mtime == stat2.st_mtime && stat1.st_size == stat2.st_size;
}

void synchronize(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dir = opendir(src_dir);

    if (dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
        
        // If the entry is a directory, recurse into it
        if (entry->d_type == DT_DIR) {
            mkdir(dest_path, 0755); // Create the directory in the destination
            synchronize(src_path, dest_path);
        } else {
            // If the file does not exist in the destination, or if it has changed, copy it
            if (access(dest_path, F_OK) == -1 || !compare_files(src_path, dest_path)) {
                printf("Synchronizing %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    struct stat st;
    if (stat(src_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Source directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    // Ensure destination directory exists
    if (stat(dest_dir, &st) != 0) {
        mkdir(dest_dir, 0755);
    }

    synchronize(src_dir, dest_dir);
    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}