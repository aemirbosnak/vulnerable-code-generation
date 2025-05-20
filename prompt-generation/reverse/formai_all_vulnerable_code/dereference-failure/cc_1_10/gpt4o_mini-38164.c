//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#define BUFFER_SIZE 8192  // Buffer size for file copying
#define MAX_PATH_LENGTH 1024  // Maximum path length

void display_help() {
    printf("Usage: ./file_backup <source_dir> <backup_dir>\n");
    printf("This program copies files from the source directory to the backup directory.\n");
    printf("It preserves the directory structure and skips existing files.\n");
}

void copy_file(const char *src_file, const char *dest_file) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (dest_fd == -1) {
        perror("Destination file already exists or error opening");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    close(src_fd);
    close(dest_fd);
}

void backup_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    struct stat info;
    char src_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];
    DIR *dp;

    dp = opendir(src_dir);
    if (dp == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

            if (stat(src_path, &info) == -1) {
                perror("Error getting file info");
                continue;
            }

            if (S_ISDIR(info.st_mode)) {
                // Create the directory in the backup location
                mkdir(dest_path, 0755);
                // Recursive backup for the directory
                backup_directory(src_path, dest_path);
            } else if (S_ISREG(info.st_mode)) {
                // Copy the file if it doesn't exist in the destination path
                if (access(dest_path, F_OK) == -1) {
                    copy_file(src_path, dest_path);
                } else {
                    printf("Skipping existing file: %s\n", dest_path);
                }
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

    const char *source = argv[1];
    const char *backup = argv[2];

    struct stat sb;
    
    // Check if source directory exists
    if (stat(source, &sb) == -1 || !S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Error: Source directory '%s' is not valid.\n", source);
        return EXIT_FAILURE;
    }

    // Create backup directory if it doesn't exist
    if (stat(backup, &sb) == -1) {
        if (mkdir(backup, 0755) == -1) {
            perror("Error creating backup directory");
            return EXIT_FAILURE;
        }
    } else if (!S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Error: Backup location '%s' is not a directory.\n", backup);
        return EXIT_FAILURE;
    }

    // Start the backup process
    backup_directory(source, backup);
    printf("Backup completed successfully from '%s' to '%s'.\n", source, backup);

    return EXIT_SUCCESS;
}