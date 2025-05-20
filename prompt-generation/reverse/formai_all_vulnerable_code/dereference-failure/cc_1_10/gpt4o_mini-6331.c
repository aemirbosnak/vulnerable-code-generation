//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <backup_directory>\n", program_name);
}

int create_backup(const char *source, const char *backup) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char src_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];

    if ((dir = opendir(source)) == NULL) {
        perror("Failed to open source directory");
        return -1;
    }

    // Create backup directory if it doesn't exist
    if (stat(backup, &info) == -1) {
        if (mkdir(backup, 0755) != 0) {
            perror("Failed to create backup directory");
            closedir(dir);
            return -1;
        }
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", backup, entry->d_name);

        if (stat(src_path, &info) != 0) {
            perror("Failed to get file status");
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(info.st_mode)) {
            if (create_backup(src_path, dest_path) < 0) {
                closedir(dir);
                return -1;
            }
        } else {
            FILE *src_file = fopen(src_path, "rb");
            FILE *dest_file = fopen(dest_path, "wb");

            if (src_file == NULL || dest_file == NULL) {
                perror("Failed to open file for backup");
                if (src_file) fclose(src_file);
                if (dest_file) fclose(dest_file);
                continue;
            }

            char buffer[4096];
            size_t bytes;
            while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
            printf("Backed up: %s to %s\n", src_path, dest_path);
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    if (create_backup(source_directory, backup_directory) < 0) {
        fprintf(stderr, "Backup failed!\n");
        return EXIT_FAILURE;
    }

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}