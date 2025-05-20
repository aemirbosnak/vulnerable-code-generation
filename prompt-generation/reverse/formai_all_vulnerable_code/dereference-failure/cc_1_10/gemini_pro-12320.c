//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

// Determine if the file is a regular file
int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// Copy the file from the source to the destination
int copy_file(const char *source, const char *destination) {
    int source_fd, destination_fd;
    char buffer[4096];
    ssize_t bytes_read, bytes_written;

    // Open the source file for reading
    source_fd = open(source, O_RDONLY);
    if (source_fd == -1) {
        perror("open");
        return -1;
    }

    // Open the destination file for writing
    destination_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (destination_fd == -1) {
        perror("open");
        close(source_fd);
        return -1;
    }

    // Copy the file data from the source to the destination
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write");
            close(source_fd);
            close(destination_fd);
            return -1;
        }
    }

    // Close the files
    close(source_fd);
    close(destination_fd);

    return 0;
}

// Create a backup of the file
int create_backup(const char *path) {
    char *backup_path;
    int backup_fd;

    // Create the backup path
    backup_path = malloc(strlen(path) + 5);
    if (backup_path == NULL) {
        fprintf(stderr, "malloc failed\n");
        return -1;
    }
    strcpy(backup_path, path);
    strcat(backup_path, ".bak");

    // Create the backup file
    backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (backup_fd == -1) {
        perror("open");
        free(backup_path);
        return -1;
    }

    // Copy the file data from the source to the backup
    if (copy_file(path, backup_path) == -1) {
        close(backup_fd);
        free(backup_path);
        return -1;
    }

    // Close the backup file
    close(backup_fd);

    // Free the backup path
    free(backup_path);

    return 0;
}

// Recursively backup the files in the directory
int backup_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    char *full_path;
    int error;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Read the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create the full path to the entry
        full_path = malloc(strlen(path) + strlen(entry->d_name) + 1);
        if (full_path == NULL) {
            fprintf(stderr, "malloc failed\n");
            closedir(dir);
            return -1;
        }
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);

        // If the entry is a regular file, create a backup
        if (is_regular_file(full_path)) {
            error = create_backup(full_path);
            if (error == -1) {
                free(full_path);
                closedir(dir);
                return -1;
            }
        }

        // If the entry is a directory, recursively backup the files in it
        else if (entry->d_type == DT_DIR) {
            error = backup_directory(full_path);
            if (error == -1) {
                free(full_path);
                closedir(dir);
                return -1;
            }
        }

        // Free the full path
        free(full_path);
    }

    // Close the directory
    closedir(dir);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return -1;
    }

    // Backup the files in the specified directory
    if (backup_directory(argv[1]) == -1) {
        fprintf(stderr, "Error backing up files\n");
        return -1;
    }

    printf("Files backed up successfully\n");

    return 0;
}