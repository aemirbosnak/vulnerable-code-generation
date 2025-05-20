//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void print_usage() {
    printf("Usage: file_backup src_directory dest_directory\n");
}

int create_backup(const char *src, const char *dest) {
    struct stat st;
    if (stat(src, &st) == -1) {
        perror("Error getting source file stats");
        return -1;
    }

    // Check if source is a directory
    if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(src);
        if (dir == NULL) {
            perror("Error opening source directory");
            return -1;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Skip the "." and ".." entries
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char src_path[MAX_PATH];
                char dest_path[MAX_PATH];

                snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
                snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

                // Recursively copy the contents
                if (create_backup(src_path, dest_path) == -1) {
                    closedir(dir);
                    return -1;
                }
            }
        }
        closedir(dir);
    } else {
        // If source is a file, copy it
        FILE *src_file = fopen(src, "rb");
        if (src_file == NULL) {
            perror("Error opening source file");
            return -1;
        }

        FILE *dest_file = fopen(dest, "wb");
        if (dest_file == NULL) {
            perror("Error opening destination file");
            fclose(src_file);
            return -1;
        }

        char buffer[BUFFER_SIZE];
        size_t bytes;
        while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
            fwrite(buffer, 1, bytes, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_directory = argv[1];
    const char *dest_directory = argv[2];

    // Create destination directory if it doesn't exist
    if (mkdir(dest_directory, 0755) == -1 && errno != EEXIST) {
        perror("Error creating destination directory");
        return EXIT_FAILURE;
    }

    if (create_backup(src_directory, dest_directory) == -1) {
        fprintf(stderr, "Backup failed\n");
        return EXIT_FAILURE;
    }

    printf("Backup completed successfully from '%s' to '%s'\n", src_directory, dest_directory);
    return EXIT_SUCCESS;
}