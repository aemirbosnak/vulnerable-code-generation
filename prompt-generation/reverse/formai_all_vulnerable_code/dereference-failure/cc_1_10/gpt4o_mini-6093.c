//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192
#define LOG_FILE "sync_log.txt"

void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

void copy_file(const char *src, const char *dest) {
    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Failed to open source file");
        log_message("File copy failed: unable to open source file");
        return;
    }

    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Failed to open destination file");
        close(src_fd);
        log_message("File copy failed: unable to open destination file");
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            log_message("File copy failed: write error");
            break;
        }
    }

    if (bytes_read < 0) {
        perror("Read error");
        log_message("File copy failed: read error");
    } else {
        log_message("File copied successfully");
    }

    close(src_fd);
    close(dest_fd);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Failed to open source directory");
        log_message("Directory sync failed: unable to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory
        }

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively sync subdirectory
            mkdir(dest_path, 0755);
            sync_directory(src_path, dest_path);
        } else {
            // If file doesn't exist or is different, copy the file
            if (!file_exists(dest_path)) {
                log_message("Copying new file");
                copy_file(src_path, dest_path);
            } else {
                log_message("File exists, checking for updates");
                struct stat src_stat, dest_stat;
                stat(src_path, &src_stat);
                stat(dest_path, &dest_stat);
                if (src_stat.st_mtime > dest_stat.st_mtime) {
                    log_message("Updating old file");
                    copy_file(src_path, dest_path);
                } else {
                    log_message("No update needed for file");
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    log_message("File synchronization started");
    sync_directory(argv[1], argv[2]);
    log_message("File synchronization finished");

    return EXIT_SUCCESS;
}