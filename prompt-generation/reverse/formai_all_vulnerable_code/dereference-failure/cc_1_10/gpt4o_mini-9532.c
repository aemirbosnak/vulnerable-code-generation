//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_RECOVER_FILES 100
#define OUTPUT_DIR "recovered"

void create_output_dir() {
    struct stat st = {0};
    if (stat(OUTPUT_DIR, &st) == -1) {
        mkdir(OUTPUT_DIR, 0700);
    }
}

void recover_file(const char *filename, const char *source_dir) {
    char source_path[BUFFER_SIZE], dest_path[BUFFER_SIZE];
    snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, filename);
    snprintf(dest_path, sizeof(dest_path), "%s/%s", OUTPUT_DIR, filename);

    FILE *src_file = fopen(source_path, "rb");
    if (src_file) {
        FILE *dest_file = fopen(dest_path, "wb");
        if (dest_file) {
            char buffer[BUFFER_SIZE];
            size_t bytes;
            while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes, dest_file);
            }
            fclose(dest_file);
            printf("Recovered: %s\n", dest_path);
        } else {
            perror("Failed to open destination file for writing");
        }
        fclose(src_file);
    } else {
        perror("Failed to open source file for reading");
    }
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        // Check if it is a regular file and not a directory
        if (entry->d_type == DT_REG) {
            // You can customize the logic to identify deleted files (by extension, for example)
            // For simplicity, we will "recover" all files in this example
            recover_file(entry->d_name, dir_path);
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory to scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_to_scan = argv[1];

    // Create output directory for recovered files
    create_output_dir();

    // Scanning specified directory
    printf("Scanning directory: %s\n", dir_to_scan);
    scan_directory(dir_to_scan);

    printf("Scanning completed.\n");
    return EXIT_SUCCESS;
}