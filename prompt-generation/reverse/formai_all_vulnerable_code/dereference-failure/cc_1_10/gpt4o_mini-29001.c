//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(const char *source, const char *dest) {
    FILE *src = fopen(source, "rb");
    FILE *dst = fopen(dest, "wb");
    
    if (src == NULL || dst == NULL) {
        perror("Error opening files for copying");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return;
    }

    char buffer[8192];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    fclose(src);
    fclose(dst);
}

void synchronize(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    struct stat src_stat, dest_stat;
    char src_path[512], dest_path[512];

    DIR *dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Cannot open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // Get file stats
        if (stat(src_path, &src_stat) == -1) {
            perror("Error getting source file stats");
            continue;
        }

        // Check if the destination file exists
        if (stat(dest_path, &dest_stat) == -1) {
            // If file does not exist in destination, copy it over
            printf("Copying new file: %s to %s\n", src_path, dest_path);
            copy_file(src_path, dest_path);
        } else {
            // If file exists, compare modification times
            if (difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
                printf("Updating file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    synchronize(argv[1], argv[2]);

    return EXIT_SUCCESS;
}