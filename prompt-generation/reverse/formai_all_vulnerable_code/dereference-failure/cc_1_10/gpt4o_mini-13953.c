//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void synchronize(const char *src, const char *dst);
void copy_file(const char *src_file, const char *dst_file);
int is_newer(const char *src_file, const char *dst_file);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    synchronize(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void synchronize(const char *src, const char *dst) {
    DIR *source_dir;
    struct dirent *entry;
    char src_file[MAX_PATH_LENGTH];
    char dst_file[MAX_PATH_LENGTH];

    // Open the source directory
    source_dir = opendir(src);
    if (!source_dir) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(source_dir)) != NULL) {
        // Skip the . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Form the source and destination full paths
        snprintf(src_file, sizeof(src_file), "%s/%s", src, entry->d_name);
        snprintf(dst_file, sizeof(dst_file), "%s/%s", dst, entry->d_name);

        struct stat src_stat;
        if (stat(src_file, &src_stat) == -1) {
            perror("stat failed");
            continue;
        }

        // Check if the destination file exists
        if (access(dst_file, F_OK) != -1) {
            // Destination file exists, check if source is newer
            if (is_newer(src_file, dst_file)) {
                printf("Copying updated file: %s -> %s\n", src_file, dst_file);
                copy_file(src_file, dst_file);
            }
        } else {
            // Destination file doesn't exist, copy it
            printf("Copying new file: %s -> %s\n", src_file, dst_file);
            copy_file(src_file, dst_file);
        }
    }

    closedir(source_dir);
}

void copy_file(const char *src_file, const char *dst_file) {
    FILE *src = fopen(src_file, "rb");
    if (!src) {
        perror("Could not open source file");
        return;
    }

    FILE *dst = fopen(dst_file, "wb");
    if (!dst) {
        perror("Could not open destination file");
        fclose(src);
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) != 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
}

int is_newer(const char *src_file, const char *dst_file) {
    struct stat src_stat, dst_stat;

    if (stat(src_file, &src_stat) == -1 || stat(dst_file, &dst_stat) == -1) {
        return 0; // Assume not newer if stat fails
    }

    return (src_stat.st_mtime > dst_stat.st_mtime);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", program_name);
}