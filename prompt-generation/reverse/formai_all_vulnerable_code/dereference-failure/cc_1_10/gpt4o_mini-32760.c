//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LEN 256

void display_usage() {
    printf("Usage: ./backup_system <source_directory> <backup_directory>\n");
}

// Function to copy a single file from source to destination
int copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    if (src == NULL) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        perror("Failed to open destination file");
        fclose(src);
        return -1;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

// Function to backup files from source directory to backup directory
void backup_files(const char *source_dir, const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);
    if (dp == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip the special directories "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_FILENAME_LEN];
        char dest_path[MAX_FILENAME_LEN];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_dir, entry->d_name);

        struct stat file_stats;
        if (stat(source_path, &file_stats) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        // If it's a regular file, copy it
        if (S_ISREG(file_stats.st_mode)) {
            if (copy_file(source_path, dest_path) == 0) {
                printf("Backed up: %s to %s\n", source_path, dest_path);
            }
        }
        // If it's a directory, create it in the backup and backup recursively
        else if (S_ISDIR(file_stats.st_mode)) {
            if (mkdir(dest_path, 0777) == -1) {
                perror("Failed to create directory");
                continue;
            }
            printf("Created directory: %s\n", dest_path);
            // Recursive call to backup_files
            backup_files(source_path, dest_path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *backup_dir = argv[2];

    // Check if source directory exists
    struct stat dir_stats;
    if (stat(source_dir, &dir_stats) == -1 || !S_ISDIR(dir_stats.st_mode)) {
        perror("Source directory does not exist or is not a directory");
        return EXIT_FAILURE;
    }

    // Create backup directory if it does not exist
    if (stat(backup_dir, &dir_stats) == -1 || !S_ISDIR(dir_stats.st_mode)) {
        if (mkdir(backup_dir, 0777) == -1) {
            perror("Failed to create backup directory");
            return EXIT_FAILURE;
        }
    }

    // Start the backup process
    printf("Starting backup from %s to %s\n", source_dir, backup_dir);
    backup_files(source_dir, backup_dir);
    printf("Backup completed successfully!\n");

    return EXIT_SUCCESS;
}