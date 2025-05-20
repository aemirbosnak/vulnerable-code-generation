//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void sync_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    
    if (src == NULL) {
        perror("Failed to open source file");
        return;
    }
    if (dest == NULL) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directories(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip '.' and '..'
        }

        char source_path[MAX_PATH];
        char dest_path[MAX_PATH];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
        
        if (is_directory(source_path)) {
            mkdir(dest_path, 0755); // Create destination directory
            sync_directories(source_path, dest_path); // Sync subdirectory
        } else {
            sync_file(source_path, dest_path); // Sync file
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    if (!is_directory(source_dir)) {
        fprintf(stderr, "Source directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    if (!is_directory(dest_dir)) {
        if (mkdir(dest_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
    }

    sync_directories(source_dir, dest_dir);
    printf("Synchronization completed from %s to %s\n", source_dir, dest_dir);

    return EXIT_SUCCESS;
}