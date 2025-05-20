//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

// Function prototypes
void sync_directory(const char *source, const char *destination);
void copy_file(const char *source_file, const char *destination_file);
int compare_files(const char *file1, const char *file2);
void create_directory(const char *dir);
void log_activity(const char *message);

// Custom logger function
void log_activity(const char *message) {
    FILE *log_file = fopen("sync.log", "a");
    if (log_file != NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min, tm.tm_sec, message);
        fclose(log_file);
    }
}

// Function to synchronize directories
void sync_directory(const char *source, const char *destination) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(source))) {
        perror("Opendir failed");
        return;
    }

    create_directory(destination);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char source_path[MAX_PATH];
            char destination_path[MAX_PATH];

            snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
            snprintf(destination_path, sizeof(destination_path), "%s/%s", destination, entry->d_name);

            if (entry->d_type == DT_DIR) {
                sync_directory(source_path, destination_path); // Recursive call for directories
            } else if (entry->d_type == DT_REG) {
                if (compare_files(source_path, destination_path) != 0) {
                    copy_file(source_path, destination_path);
                    log_activity("File copied: ");
                    log_activity(source_path);
                }
            }
        }
    }
    closedir(dir);
}

// Function to copy files
void copy_file(const char *source_file, const char *destination_file) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    src_fd = open(source_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Source file open failed");
        return;
    }

    dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd < 0) {
        perror("Destination file open failed");
        close(src_fd);
        return;
    }

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);
}

// Function to compare files
int compare_files(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) != 0 || stat(file2, &stat2) != 0) return -1;
    if (stat1.st_size != stat2.st_size) return 1; // Different sizes, files are not equal

    return 0; // Sizes are the same
}

// Function to create a directory if it doesn't exist
void create_directory(const char *dir) {
    struct stat st = {0};

    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
        log_activity("Directory created: ");
        log_activity(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    log_activity("Synchronization started");
    sync_directory(argv[1], argv[2]);
    log_activity("Synchronization completed");

    printf("Synchronization from '%s' to '%s' completed successfully.\n", argv[1], argv[2]);

    return EXIT_SUCCESS;
}