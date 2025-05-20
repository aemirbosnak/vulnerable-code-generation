//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024

void print_usage(const char *progname) {
    printf("Usage: %s <source_directory> <destination_directory>\n", progname);
}

int is_file_modified(const char *source_file, const char *dest_file) {
    struct stat source_stat, dest_stat;

    if (stat(source_file, &source_stat) == -1) {
        perror("Error getting source file stats");
        return 1;
    }
    if (stat(dest_file, &dest_stat) == -1) {
        return 1; // Destination file doesn't exist, implies modification needed
    }

    return source_stat.st_mtime > dest_stat.st_mtime;
}

void copy_file(const char *source_file, const char *dest_file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;
    
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest);
        if (bytes_written < bytes_read) {
            perror("Error writing to destination file");
        }
    }

    fclose(src);
    fclose(dest);
}

void synchronize_directory(const char *source_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);
    
    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] != '.') { // Ignore hidden files
            char source_path[MAX_PATH_LENGTH];
            char dest_path[MAX_PATH_LENGTH];

            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

            struct stat path_stat;
            stat(source_path, &path_stat);

            if (S_ISDIR(path_stat.st_mode)) {
                mkdir(dest_path, 0755);
                synchronize_directory(source_path, dest_path);
            } else {
                if (is_file_modified(source_path, dest_path)) {
                    printf("Copying updated file: %s to %s\n", source_path, dest_path);
                    copy_file(source_path, dest_path);
                }
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    struct stat st;
    if (stat(destination_directory, &st) != 0) {
        mkdir(destination_directory, 0755);
    }

    printf("Synchronizing from %s to %s...\n", source_directory, destination_directory);
    synchronize_directory(source_directory, destination_directory);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}