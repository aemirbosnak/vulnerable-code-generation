//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void show_usage() {
    printf("Usage: file_backup <source_directory> <backup_directory>\n");
}

int copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dst = fopen(destination, "wb");
    if (dst == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead, bytesWritten;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        bytesWritten = fwrite(buffer, 1, bytesRead, dst);
        if (bytesWritten < bytesRead) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dst);
            return -1;
        }
    }

    fclose(src);
    fclose(dst);
    return 0;
}

void create_backup(const char *source_dir, const char *backup_dir) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    
    if ((dir = opendir(source_dir)) == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip special directories "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_FILENAME_LENGTH];
        char backup_path[MAX_FILENAME_LENGTH];
        
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);
        
        if (stat(source_path, &file_info) == -1) {
            perror("Error getting file info");
            continue;
        }

        if (S_ISDIR(file_info.st_mode)) {
            // Recursively create the backup for directories
            mkdir(backup_path, 0755);
            create_backup(source_path, backup_path);
        } else {
            // Copy the file to the backup directory
            printf("Backing up: %s to %s\n", source_path, backup_path);
            if (copy_file(source_path, backup_path) != 0) {
                fprintf(stderr, "Failed to backup %s\n", source_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        show_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    // Create the backup directory if it does not exist
    struct stat st;
    if (stat(backup_directory, &st) == -1) {
        if (mkdir(backup_directory, 0755) != 0) {
            perror("Failed to create backup directory");
            return EXIT_FAILURE;
        }
    }

    create_backup(source_directory, backup_directory);
    printf("Backup completed from %s to %s\n", source_directory, backup_directory);

    return EXIT_SUCCESS;
}