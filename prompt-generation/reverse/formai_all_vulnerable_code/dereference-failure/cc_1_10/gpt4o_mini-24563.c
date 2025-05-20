//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void display_help() {
    printf("Usage: filebackup [source_directory] [backup_directory]\n");
    printf("Example: filebackup /path/to/source /path/to/backup\n");
}

int copy_file(const char *source, const char *destination) {
    FILE *src, *dest;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    dest = fopen(destination, "wb");
    if (dest == NULL) {
        fclose(src);
        perror("Error opening destination file");
        return -1;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

void backup_files(const char *source_dir, const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);
    
    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the special directories '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_PATH];
        char backup_path[MAX_PATH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);

        // Check whether it's a directory or a file
        struct stat statbuf;
        if (stat(source_path, &statbuf) != 0) {
            perror("Error getting file status");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Create a directory in the backup location
            mkdir(backup_path, 0755);
            // Recursively backup the directory
            backup_files(source_path, backup_path);
        } else {
            // Copy the file to the backup directory
            if (copy_file(source_path, backup_path) == 0) {
                printf("Copied: %s to %s\n", source_path, backup_path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *backup_dir = argv[2];

    // Create backup directory if it doesn't exist
    struct stat st;
    if (stat(backup_dir, &st) != 0) {
        if (mkdir(backup_dir, 0755) != 0) {
            perror("Error creating backup directory");
            return EXIT_FAILURE;
        }
    }

    printf("Starting backup from %s to %s...\n", source_dir, backup_dir);
    backup_files(source_dir, backup_dir);
    printf("Backup completed successfully.\n");

    return EXIT_SUCCESS;
}