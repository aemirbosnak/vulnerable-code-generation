//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 512
#define BUFFER_SIZE 256

void log_report(const char *filename, const char *action) {
    FILE *log_file = fopen("sync_report.txt", "a");
    if (log_file == NULL) {
        perror("Unable to open report file");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "File %s: %s\n", filename, action);
    fclose(log_file);
}

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

int files_are_different(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    if (f1 == NULL || f2 == NULL) {
        return 1; // Assume they are different if one can't be opened
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t bytesRead1, bytesRead2;

    while ((bytesRead1 = fread(buffer1, 1, BUFFER_SIZE, f1)) > 0 &&
           (bytesRead2 = fread(buffer2, 1, BUFFER_SIZE, f2)) > 0) {
        if (bytesRead1 != bytesRead2 || memcmp(buffer1, buffer2, bytesRead1) != 0) {
            fclose(f1);
            fclose(f2);
            return 1; // Files are different
        }
    }

    fclose(f1);
    fclose(f2);
    return bytesRead1 != bytesRead2; // Return true if one has more bytes
}

void synchronize_files(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    int files_added = 0, files_updated = 0, files_deleted = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char src_path[MAX_PATH], dest_path[MAX_PATH];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

            if (!file_exists(dest_path)) {
                // File does not exist in dest directory
                printf("Adding file: %s\n", entry->d_name);
                FILE *src_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(dest_path, "wb");
                if (src_file && dest_file) {
                    char buffer[BUFFER_SIZE];
                    size_t bytes_read;
                    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, bytes_read, dest_file);
                    }
                    fclose(src_file);
                    fclose(dest_file);
                    log_report(entry->d_name, "added");
                    files_added++;
                }
            } else if (files_are_different(src_path, dest_path)) {
                // File exists but is different
                printf("Updating file: %s\n", entry->d_name);
                FILE *src_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(dest_path, "wb");
                if (src_file && dest_file) {
                    char buffer[BUFFER_SIZE];
                    size_t bytes_read;
                    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, bytes_read, dest_file);
                    }
                    fclose(src_file);
                    fclose(dest_file);
                    log_report(entry->d_name, "updated");
                    files_updated++;
                }
            }
        }
    }
    
    closedir(dir);

    // Check for deleted files
    dir = opendir(dest_dir);
    if (dir == NULL) {
        perror("Unable to open destination directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char src_path[MAX_PATH], dest_path[MAX_PATH];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

            if (!file_exists(src_path)) {
                printf("Deleting file: %s\n", entry->d_name);
                remove(dest_path);
                log_report(entry->d_name, "deleted");
                files_deleted++;
            }
        }
    }

    closedir(dir);

    // Summary report
    printf("\nSynchronization Complete:\n");
    printf("Files Added: %d\n", files_added);
    printf("Files Updated: %d\n", files_updated);
    printf("Files Deleted: %d\n", files_deleted);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    synchronize_files(argv[1], argv[2]);
    return EXIT_SUCCESS;
}